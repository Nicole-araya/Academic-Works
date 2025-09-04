create tablespace PINUNA Datafile 'PINUNA.DBF' Size 8M;
create table vendedores (
    codigo int,
    nombre varchar(30),
    total_vendido int,
    comision_anual int,
    constraint pkvendedor primary key (codigo)
) TABLESPACE PINUNA;
create table zonas (
    codigo int,
    nombre varchar(30),
    total_clientes int,
    total_ventas int,
    constraint pkzonas primary key (codigo)
) TABLESPACE PINUNA;
create table tipo_clientes (
    codigo int,
    descuento int,
    limite_credito int,
    plazo_maximo int,
    constraint pktipo_cliente primary key (codigo)
) TABLESPACE PINUNA;
create table clientes (
    codigo int,
    nombre varchar(30),
    total_compra int,
    tipo_cliente int,
    zona int,
    vendedor int,
    constraint pkcliente primary key (codigo),
    constraint fkcliente1 foreign key (vendedor) references vendedores (codigo),
    constraint fkcliente2 foreign key (tipo_cliente) references tipo_clientes (codigo),
    constraint fkcliente3 foreign key (zona) references zonas (codigo)
) TABLESPACE PINUNA;
create table facturas (
    numero int,
    fecha_creacion date,
    tipo_factura int,
    subtotal_factura int,
    total_impuesto int,
    total_descuento int,
    total_factura int,
    saldo_factura int,
    cliente int,
    estado int,
    constraint pkfactura primary key (numero),
    constraint fkfactura1 foreign key (cliente) references clientes (codigo),
    constraint cktipo_factura check (tipo_factura=1 or tipo_factura=2),
    constraint ckestado_factura check (estado=1 or estado=2 or estado=3)
) TABLESPACE PINUNA;
create table familias (
    codigo int,
    descripcion varchar(30),
    constraint pkfamilias primary key (codigo)
) TABLESPACE PINUNA;
create table productos (
    codigo int,
    nombre varchar(30),
    precio_venta int,
    utilidad int,
    familia int,
    constraint pkproducto primary key (codigo),
    constraint fkproducto foreign key (familia) references familias (codigo)
) TABLESPACE PINUNA;
create table lineas_factura (
    producto int,
    cantidad int,
    precio_linea int,
    factura int,
    constraint pklineas_facturas primary key (factura, producto),
    constraint fklineas_producto1 foreign key (producto) references productos (codigo),
    constraint fklineas_producto2 foreign key (factura) references facturas (numero)
) TABLESPACE PINUNA;
create table bodegas (
    codigo int,
    zona int,
    constraint pkbodega primary key (codigo),
    constraint fkbodega foreign key (zona) references zonas (codigo)
) TABLESPACE PINUNA;
create table inventario_bodega (
    bodega int,
    producto int,
    cantidad_actual int,
    cantidad_minima int,
    cantidad_reorder int,
    constraint pkinventario_bodega primary key (bodega, producto),
    constraint fkinventario_bodega1 foreign key (bodega) references bodegas(codigo),
    constraint fkinventario_bodega2 foreign key (producto) references productos (codigo)
) TABLESPACE PINUNA;
create table proveedores(
    codigo int,
    nombre varchar(20),
    tipo int,
    limiteCredito int,
    totalComprado int,
    Constraint Pkproveedor primary key (codigo)
) TABLESPACE PINUNA;
create table materias_primas(
    codigo int,
    nombre varchar(30),
    cantidad_actual int,
    cantidad_minima int,
    cantidad_reorder int,
    ultimo_precio int,
    proveedor int,
    constraint pkmaterias_primas primary key (codigo),
    constraint fkmaterias_primas foreign key(proveedor) references proveedores(codigo)
) TABLESPACE PINUNA;
create table componente_productos(
    producto int,
    materia_prima int,
    cantidad int,
    constraint pkcomponente_productos primary key (producto, materia_prima),
    constraint fkcomponente_productos1 foreign key (producto) references productos (codigo),
    constraint fkcomponente_productos2 foreign key (materia_prima) references materias_primas (codigo)
) TABLESPACE PINUNA;
create table OrdenProduccion (
    codigo int,
    producto int,
    cantidad int,
    bodega int,
    fecha date,
    estado int,
    constraint pkOrdenProduccion primary key (codigo),
    constraint fkOrdenProduccion1 foreign key (producto) references productos (codigo),
    constraint fkOrdenProduccion2 foreign key (bodega) references bodegas (codigo),
    constraint ckestado_OP check (estado=1 or estado=2 or estado=3)
) TABLESPACE PINUNA;
create table OrdenTrabajo (
    codigo int,
    ordenProduccion int,
    fecha date,
    estado int,
    constraint pkOrdenTrabajo primary key (codigo),
    constraint fkOrdenTrabajo foreign key (ordenProduccion) references OrdenProduccion (codigo),
    constraint ckestado_OT check (estado=1 or estado=2 or estado=3)
) TABLESPACE PINUNA;
create table requisicion_materiales (
    OrdenTrabajo int,
    material int,
    cantidad int,
    estado int,
    Constraint Pkrequisicion primary key (OrdenTrabajo, material),
    constraint fkrequisicion_materiales1 foreign key (OrdenTrabajo) references OrdenTrabajo (codigo),
    constraint fkrequisicion_materiales2 foreign key (material) references materias_primas (codigo),
    constraint ckestado_RM check (estado=1 or estado=2 or estado=3)
) TABLESPACE PINUNA;

create table facturas_proveedor(
    numero int,
    fechaEmision DATE,
    formaDePago int,
    montoTotal int,
    proveedor int,
    saldo int,
    Constraint PkfacturaP primary key(numero),
    Constraint fkfactura foreign key(proveedor) references proveedores(codigo)
) TABLESPACE PINUNA;
create table Pago(
    codigo int,
    montoPago int,
    Constraint PkPago primary key(codigo)
) TABLESPACE PINUNA;
create table FechaUltimoPago(
    codigo int,
    fecha DATE,
    pagos int,
    Constraint PkfechaUltimoPago primary key(codigo),
    Constraint fkfechaUltimoPago foreign key(pagos) references Pago(codigo)
) TABLESPACE PINUNA;
create table facturas_prestamo(
    numero int,
    fechaUltimoPago int,
    factura int,
    Constraint Pkfacturas_prestamo primary key(numero),
    Constraint fkfacturas_prestamo1 foreign key(factura) references facturas_proveedor(numero),
    constraint fkfacturas_prestamo2 foreign key(fechaUltimoPago) references FechaUltimoPago(codigo)
) TABLESPACE PINUNA;
create table OrdenCompra(
    materia int,
    proveedor int,
    cantidad int,
    estado int,
    constraint FkOrdenCompra1 foreign key(proveedor) references proveedores(codigo),
    constraint FkOrdenCompra2 foreign key(materia) references materias_primas(codigo)
) TABLESPACE PINUNA;
create table solicitud_compra(
    codigo int,
    materia int,
    proveedor int,
    cantidad int,
    fecha DATE,
    estado int,
    constraint FksoliCompra foreign key(proveedor) references proveedores(codigo),
    constraint FksoliCompra2 foreign key(materia) references materias_primas(codigo)
) TABLESPACE PINUNA;
--
CREATE SEQUENCE seq_OP MINVALUE 1 START WITH 1 INCREMENT BY 1 CACHE 20;
CREATE SEQUENCE seq_OT MINVALUE 1 START WITH 1 INCREMENT BY 1 CACHE 20;
CREATE SEQUENCE seq_SC MINVALUE 1 START WITH 1 INCREMENT BY 1 CACHE 20;
--
create or replace procedure sp001 (wcodigo int, wnombre varchar) is Begin
insert into vendedores (codigo, nombre, total_vendido, comision_anual)
values (wcodigo, wnombre, 0.00, 0.00);
commit;
end SP001;
/
create or replace procedure sp002 (wcodigo int, wnombre varchar) is begin
update vendedores
set nombre = wnombre
where codigo = wcodigo;
commit;
end sp002;
/
Create or replace procedure sp003 (wcodigo int) is begin
delete from vendedores
where vendedor.codigo = wcodigo;
commit;
end sp003;
/
create or replace procedure sp004 (wcodigo int, wcomision int) is begin
update vendedores
set comision_anual = wcomision
where codigo = wcodigo;
commit;
end sp004;
/
create or replace procedure sp005 (c1 OUT SYS_REFCURSOR) is begin open c1 for
select codigo,
    nombre
from vendedores
order by nombre;
end sp005;
/
Create or replace procedure sp006 (comisiones out SYS_REFCURSOR) is begin open comisiones for
select vendedores.codigo,
    sum(
        vendedores.comision_anual * facturas.total_factura
    ) as comision_anual
from vendedores,
    clientes,
    facturas
where vendedores.codigo = clientes.vendedor
    and clientes.codigo = facturas.cliente
group by vendedores.codigo;
end sp006;
/
Create or replace procedure SP007 (WVENDEDOR int, C2 OUT SYS_REFCURSO) IS BEGIN OPEN C2 FOR
SELECT CLIENTES.NOMBRE
FROM VENDEDORES,
    CLIENTES
WHERE VENDEDORES.CODIGO = CLIENTES.VENDEDOR
    AND VENDEDORES.CODIGO = WVENDEDOR;
END SP007;
/
create or replace procedure sp008 (C3 OUT SYS_REFCURSOR) IS BEGIN OPEN C3 FOR
SELECT vendedores.nombre,
    vendedores.codigo,
    clientes.codigo,
    clientes.nombre,
    zonas.nombre,
    zonas.codigo
from VENDEDORES,
    CLIENTES,
    ZONAS
where vendedores.codigo = clientes.vendedor
    AND clientes.zona = zonas.codigo
order by zonas.nombre;
end sp008;
/
create or replace procedure sp009 (C4 OUT SYS_REFCURSOR) IS BEGIN OPEN C4 FOR
SELECT clientes.codigo,
    clientes.nombre,
    clientes.total_compra
from CLIENTES
order by clientes.total_compra;
end sp009;
/
create or replace procedure sp010 (C5 OUT SYS_REFCURSOR) IS BEGIN OPEN C5 FOR
SELECT vendedores.codigo,
    vendedores.nombre,
    productos.codigo,
    productos.nombre,
    productos.precio_venta
from vendedores,
    clientes,
    facturas,
    lineas_factura,
    productos
where vendedores.codigo = clientes.vendedor
    AND clientes.codigo = facturas.cliente
    AND facturas.numero = lineas_factura.factura
    AND lineas_factura.producto = productos.codigo
order by productos.precio_venta desc;
end sp010;
/
CREATE OR REPLACE PROCEDURE sp011 (C6 OUT SYS_REFCURSOR) IS BEGIN OPEN C6 FOR
SELECT vendedores.codigo,
    vendedores.nombre,
    clientes.codigo,
    clientes.nombre
FROM vendedores,
    clientes
WHERE vendedores.codigo = clientes.vendedor
    AND clientes.codigo NOT IN (
        SELECT DISTINCT facturas.cliente
        FROM facturas,
            lineas_factura
        WHERE facturas.numero = lineas_factura.factura
            AND facturas.fecha_creacion >= TO_DATE('2023-01-01', 'YYYY-MM-DD')
            AND facturas.fecha_creacion <= TO_DATE('2023-03-31', 'YYYY-MM-DD')
    )
ORDER BY vendedores.codigo;
END sp011;
/
create or replace procedure sp012 (C12 OUT SYS_REFCURSOR) IS BEGIN OPEN C12 FOR
SELECT productos.nombre,
    lineas_factura.cantidad,
    familias.descripcion,
    vendedores.nombre
FROM productos,
    familias,
    lineas_factura,
    facturas,
    clientes,
    vendedores
WHERE familias.codigo = productos.familia
    AND productos.codigo = lineas_factura.producto
    AND lineas_factura.factura = facturas.numero
    AND facturas.cliente = clientes.codigo
    AND clientes.vendedor = vendedores.codigo
ORDER BY lineas_factura.cantidad ASC;
END;
/ 
---------------------------TRIGGERS
CREATE OR REPLACE TRIGGER TR001 
AFTER UPDATE ON inventario_bodega FOR EACH ROW 
BEGIN 
IF :NEW.cantidad_actual < :NEW.cantidad_minima THEN
INSERT INTO OrdenProduccion(
        codigo,
        producto,
        cantidad,
        bodega,
        fecha,
        estado
    )
VALUES (
        seq_OP.NEXTVAL,
        :NEW.producto,
        :NEW.cantidad_reorder,
        :NEW.bodega,
        SYSDATE,
        1
    );
END IF;
END;
/
CREATE OR REPLACE TRIGGER TR002 
AFTER INSERT ON OrdenProduccion FOR EACH ROW 
BEGIN
INSERT INTO OrdenTrabajo(codigo, ordenProduccion, fecha, estado)
VALUES (seq_OT.NEXTVAL, :NEW.codigo, SYSDATE, 1);
END;
/
CREATE OR REPLACE TRIGGER TR003 --TRIGGER REQUISICION DE MATERIALES
AFTER INSERT ON OrdenTrabajo FOR EACH ROW 
DECLARE
wComponente int;
wCantidad int;
c1 SYS_REFCURSOR;
BEGIN 
open c1 for select componente_productos.materia_prima,
    componente_productos.cantidad
FROM componente_productos,
    OrdenProduccion
WHERE :NEW.ordenProduccion = OrdenProduccion.codigo
    AND OrdenProduccion.producto = componente_productos.producto;
Fetch c1 into wComponente,wCantidad;
WHILE c1 %found loop
INSERT INTO requisicion_materiales(OrdenTrabajo, material, cantidad, estado)
VALUES (:NEW.codigo, wComponente, wCantidad, 1);
Fetch c1 into wComponente,wCantidad;
end loop;
close c1;
END;
/
CREATE OR REPLACE TRIGGER TR004 --TRIGGER SOLICITUD DE COMPRA MATERIAS PRIMAS
AFTER
UPDATE ON materias_primas FOR EACH ROW BEGIN IF :NEW.cantidad_actual < :OLD.cantidad_minima THEN
INSERT INTO solicitud_compra(
        codigo,
        materia,
        proveedor,
        cantidad,
        fecha,
        estado
    )
VALUES (
        seq_SC.NEXTVAL,
        :NEW.codigo,
        :NEW.proveedor,
        :OLD.cantidad_reorder,
        SYSDATE,
        1
    );
END IF;
END;
/

--------------------BODEGUERO---------------------------------------------

create or replace type  bodeguero as object  ( 
 nombre varchar2(30),
 id int,
member function actualizar_requisiciones return varchar2
)

CREATE OR REPLACE TYPE BODY BODEGUERO AS
 member function actualizar_requisiciones return varchar2 AS
  c SYS_REFCURSOR;
  wcanRequisicion int;
  wcanMateriaP int;
  wcodMateriaP int;
  total int;
  BEGIN
    open c for select requisicion_materiales.cantidad, materias_primas.cantidad_actual, materias_primas.codigo
    FROM requisicion_materiales, materias_primas 
    WHERE requisicion_materiales.material = materias_primas.codigo;
    Fetch c into wcanRequisicion,wcanMateriaP,wcodMateriaP;
    
    WHILE c%found loop
    
    total := wcanMateriaP-wcanRequisicion;
    UPDATE materias_primas set cantidad_actual=total where codigo=wcodMateriaP;
    commit;
    
    Fetch c into wcanRequisicion,wcanMateriaP,wcodMateriaP;
    end loop;
    close c;
    RETURN 'Actualizado';
  END actualizar_requisiciones;
END;

-----------------------USUARIO--------------------------------------------------

ALTER SESSION SET "_ORACLE_SCRIPT" = TRUE;
CREATE USER proyecto IDENTIFIED BY proyecto;
GRANT DBA TO proyecto;
GRANT CONNECT,RESOURCE TO proyecto;
GRANT CREATE SESSION TO proyecto;
GRANT CREATE TABLE TO proyecto;
GRANT SELECT Any table TO proyecto;
GRANT INSERT Any table TO proyecto;
GRANT UPDATE Any table TO proyecto;
GRANT DELETE Any table TO proyecto;
GRANT CREATE TRIGGER TO proyecto;
GRANT ALTER ANY TABLE TO proyecto;
GRANT CREATE PROCEDURE TO proyecto;
GRANT EXECUTE ANY PROCEDURE TO proyecto;
GRANT UNLIMITED TABLESPACE TO proyecto;











