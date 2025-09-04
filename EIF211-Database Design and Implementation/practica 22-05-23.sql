create table Familias (
  codigo integer,
  nombre varchar(30),
  constraint PKfamilias primary key(codigo)
  );
  insert into Familias(codigo, nombre) values (1,'fam1');
  insert into Familias(codigo, nombre) values (2,'fam2');
  insert into Familias(codigo, nombre) values (3,'fam3');
  
  
  create table Productos (
  codigo integer,
  costo integer,
  utilidad integer,
  precio integer,
  reorder integer,
  nombre varchar(30),
  familia integer,
  constraint PKproductos primary key(codigo),
  constraint FKproductos Foreign key(familia) references Familias(codigo)
  );

  insert into Productos(codigo, costo, utilidad, precio, reorder, nombre, familia) values (1,2000,10,1000,20,'produc1',1);
  insert into Productos(codigo, costo, utilidad, precio, reorder, nombre, familia) values (2,3000,20,5000,10,'produc2',2);
  insert into Productos(codigo, costo, utilidad, precio, reorder, nombre, familia) values (3,4000,30,4000,30,'produc3',3);
  
  
  create table Componentes (
  codigo integer,
  nombre varchar(30),
  producto integer,
  constraint PKcomponentes primary key(codigo),
  constraint FKcomponentes Foreign key(producto) references Productos(codigo)
  );
   insert into Componentes(codigo, nombre, producto) values (1,'compa1',1);
   insert into Componentes(codigo, nombre, producto) values (2,'comp2',2);
   insert into Componentes(codigo, nombre, producto) values (3,'comp3',3);
   insert into Componentes(codigo, nombre, producto) values (4,'comp4',3);
   insert into Componentes(codigo, nombre, producto) values (5,'comp5',1);

   create table Proveedores (
	codigo integer,
	nombre VARCHAR(30),
	 constraint PKproveedores primary key(codigo)
  );
  insert into Proveedores(codigo, nombre) values (1, 'prov1');
  insert into Proveedores(codigo, nombre) values (2, 'prov2');
  insert into Proveedores(codigo, nombre) values (3, 'prov3');
  

create table Materias (
  cantidad integer,
  cantidad_minima integer,
  reorder integer,
  codigo integer,
  precio integer,
  proveedor integer,
  constraint PKMaterias primary key(codigo),
  constraint FKmaterias Foreign key(proveedor) references Proveedores(codigo)
  );
  insert into Materias(cantidad, cantidad_minima, reorder, codigo, precio, proveedor) values (50,10,30,1,1000,1);
  insert into Materias(cantidad, cantidad_minima, reorder, codigo, precio, proveedor) values (30,10,20,2,5000,2);
  insert into Materias(cantidad, cantidad_minima, reorder, codigo, precio, proveedor) values (40,10,50,3,3000,3);
  
  create table Formulas (
  cantidad integer,
  componente integer,
  materia integer,
  constraint FK1formulas Foreign key(componente) references Componentes(codigo),
  constraint FK2formulas Foreign key(materia) references Materias(codigo)
  );
  insert into Formulas(cantidad, componente, materia) values (50,1,1);
  insert into Formulas(cantidad, componente, materia) values (40,2,2);
  insert into Formulas(cantidad, componente, materia) values (30,3,3);
  
  create table OrdenProduccion(
    usuario varchar(30),
    fecha DATE, 
    producto INT, 
    cantidad INT, 
    CONSTRAINT FkOProd FOREIGN KEY (producto)REFERENCES PRODUCTO(codigo));
  
  
create or replace Procedure P048(Fcodigo OUT integer, Pcodigo OUT integer, FormComp OUT integer, FormCantidad OUT integer)
IS
  c1 SYS_REFCURSOR;
  wFcodigo integer;
  wPcodigo integer;
  wFormComp integer;
  wFormCantidad integer;
BEGIN
OPEN c1 FOR 'select familias.codigo, productos.codigo, formulas.componente, formulas.cantidad
    from Familias, Productos, componentes, formulas, materias where familias.codigo = productos.familia AND productos.codigo = componentes.producto AND componentes.codigo = formulas.componente AND formulas.materia = materias.codigo 
    order by familias.codigo, productos.codigo';
    FETCH c1 INTO wFcodigo, wPcodigo, wFormComp, wFormCantidad;

WHILE c1%FOUND LOOP
    DBMS_OUTPUT.PUT_LINE('Familia codigo: ' || wFCodigo);
    DBMS_OUTPUT.PUT_LINE('Producto codigo: ' || wPCodigo);
    DBMS_OUTPUT.PUT_LINE('Formula componente: ' || wFormComp);
    DBMS_OUTPUT.PUT_LINE('Cantidad de formula: ' || wFormCantidad);
    FETCH c1 INTO wFcodigo, wPcodigo, wFormComp, wFormCantidad;
    END LOOP;

    close c1;
END;
/

create or replace Procedure P049(Fcodigo OUT integer, Pcodigo OUT integer, FormComp OUT integer, FormCantidad OUT integer)
IS
  c1 SYS_REFCURSOR;
  c2 SYS_REFCURSOR;
  c3 SYS_REFCURSOR;
  wFcodigo integer;
  wPcodigo integer;
  wFormComp integer;
  wFormCantidad integer;
  wProductoria integer; --formulas.cantidad*materias.precio
  wSumaMaterias integer; --Va acumulando el precio del componente mediante la suma de todas las materias.
  wPrecioFinal integer; --Acumula el precio del producto mediante la suma de los componentes.
BEGIN
wSumaMaterias := 0;
wPrecioFinal := 0;
wProductoria := 0;

OPEN c1 FOR 'select familias.codigo, productos.codigo, formulas.componente, formulas.cantidad
    from Familias, Productos, componentes, formulas, materias where familias.codigo = productos.familia AND productos.codigo = componentes.producto AND componentes.codigo = formulas.componente AND formulas.materia = materias.codigo 
    order by familias.codigo, productos.codigo';
    FETCH c1 INTO wFcodigo, wPcodigo, wFormComp, wFormCantidad;
    
    OPEN C2 FOR 'select formulas.cantidad, materias.precio 
                    from Formulas'
    FETCH c2 INTO 

    OPEN C3 FOR 
    FETCH c3 INTO 

WHILE c1%FOUND LOOP
    wProductoria := select formula.cantidad from Formulas where formula.codigo = codigo;

    FETCH c1 INTO wFcodigo, wPcodigo, wFormComp, wFormCantidad;
    END LOOP;

    close c1;
END;
/

SET SERVEROUTPUT ON;

DECLARE

wFcodigo INTEGER;
wPcodigo INTEGER;
wFormComp INTEGER;
wFormCantidad INTEGER;

BEGIN
    P048(wFcodigo, wPcodigo, wFormComp, wFormCantidad);
END;
/


CREATE USER luis IDENTIFIED BY luis;
GRANT CREATE SESSION TO luis;
GRANT CREATE PROCEDURE TO luis;
GRANT CREATE FUNCTION TO luis;
GRANT CREATE TRIGGER TO luis;
GRANT CREATE TABLE TO luis;
GRANT SELECT ANY TABLE TO luis;
GRANT INSERT ANY TABLE TO luis;
GRANT UNLIMITED TABLESPACE TO luis;


CREATE OR REPLACE TRIGGER TR004
AFTER UPDATE ON Materias FOR EACH ROW
BEGIN

IF :NEW.cantidad < :OLD.cantidad_minima THEN
    INSERT INTO OrdenProduccion(usuario, fecha, producto, cantidad);
    VALUES (:USER, SYSDATE, :NEW.producto, :OLD.reorder );
  END IF;

END;
/