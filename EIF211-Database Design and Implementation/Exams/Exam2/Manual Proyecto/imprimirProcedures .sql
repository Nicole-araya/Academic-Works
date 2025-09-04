--INSERTS
INSERT INTO vendedores (codigo, nombre, total_vendido, comision_anual)
VALUES (1, 'Juan Perez', 10000, 500);
INSERT INTO vendedores (codigo, nombre, total_vendido, comision_anual)
VALUES(2, 'Maria Lopez', 15000, 750);
INSERT INTO vendedores (codigo, nombre, total_vendido, comision_anual)
VALUES(3, 'Pedro Sanchez', 8000, 400);

INSERT INTO zonas (codigo, nombre, total_clientes, total_ventas)
VALUES (1, 'Zona A', 100, 5000);
INSERT INTO zonas (codigo, nombre, total_clientes, total_ventas)
VALUES (2, 'Zona B', 75, 4000);
 INSERT INTO zonas (codigo, nombre, total_clientes, total_ventas)
VALUES (3, 'Zona C', 120, 6000);

INSERT INTO tipo_clientes (codigo, descuento, limite_credito, plazo_maximo)
VALUES (1, 10, 5000, 30);
INSERT INTO tipo_clientes (codigo, descuento, limite_credito, plazo_maximo)
VALUES (2, 15, 10000, 45);
INSERT INTO tipo_clientes (codigo, descuento, limite_credito, plazo_maximo)
VALUES (3, 5, 2000, 15);

INSERT INTO clientes (codigo, nombre, total_compra, tipo_cliente, zona, vendedor)
VALUES (1, 'Cliente A', 5000, 2, 1, 1);
INSERT INTO clientes (codigo, nombre, total_compra, tipo_cliente, zona, vendedor)
VALUES (2, 'Cliente B', 10000, 1, 2, 2);
INSERT INTO clientes (codigo, nombre, total_compra, tipo_cliente, zona, vendedor)
VALUES (3, 'Cliente C', 2000, 3, 3, 3);

INSERT INTO facturas (numero, fecha_creacion, tipo_factura, subtotal_factura, total_impuesto, total_descuento, total_factura, saldo_factura, cliente, estado)
VALUES (1, TO_DATE('2023-06-01', 'YYYY-MM-DD'), 1, 5000, 800, 200, 5600, 5600, 1, 1);
INSERT INTO facturas (numero, fecha_creacion, tipo_factura, subtotal_factura, total_impuesto, total_descuento, total_factura, saldo_factura, cliente, estado)
VALUES (2, TO_DATE('2023-06-05', 'YYYY-MM-DD'), 2, 10000, 1600, 400, 11600, 11600, 2, 1);
INSERT INTO facturas (numero, fecha_creacion, tipo_factura, subtotal_factura, total_impuesto, total_descuento, total_factura, saldo_factura, cliente, estado)
VALUES (3, TO_DATE('2023-06-10', 'YYYY-MM-DD'), 1, 2000, 320, 80, 2240, 2240, 3, 1);


INSERT INTO familias (codigo, descripcion)
VALUES (1, 'Familia A');
INSERT INTO familias (codigo, descripcion)
VALUES (2, 'Familia B');
INSERT INTO familias (codigo, descripcion)
VALUES (3, 'Familia C');

INSERT INTO productos (codigo, nombre, precio_venta, utilidad, familia)
VALUES (1, 'Producto A', 100, 20, 1);
INSERT INTO productos (codigo, nombre, precio_venta, utilidad, familia)
VALUES (2, 'Producto B', 200, 30, 2);
INSERT INTO productos (codigo, nombre, precio_venta, utilidad, familia)
VALUES (3, 'Producto C', 150, 25, 3);

INSERT INTO lineas_factura (producto, cantidad, precio_linea, factura)
VALUES (1, 2, 200, 1);
INSERT INTO lineas_factura (producto, cantidad, precio_linea, factura)
VALUES (2, 3, 300, 1);
INSERT INTO lineas_factura (producto, cantidad, precio_linea, factura)
VALUES (3, 1, 150, 2);

INSERT INTO bodegas (codigo, zona)
VALUES (1, 1);
INSERT INTO bodegas (codigo, zona)
VALUES (2, 2);
INSERT INTO bodegas (codigo, zona)
VALUES (3, 1);

INSERT INTO inventario_bodega (bodega, producto, cantidad_actual, cantidad_minima, cantidad_reorder)
VALUES (1, 1, 10, 5, 8);
INSERT INTO inventario_bodega (bodega, producto, cantidad_actual, cantidad_minima, cantidad_reorder)
VALUES (2, 2, 15, 10, 12);
INSERT INTO inventario_bodega (bodega, producto, cantidad_actual, cantidad_minima, cantidad_reorder)
VALUES (1, 3, 20, 15, 18);

INSERT INTO proveedores (codigo, nombre, tipo, limiteCredito, totalComprado)
VALUES (1, 'Proveedor A', 1, 5000, 2000);
INSERT INTO proveedores (codigo, nombre, tipo, limiteCredito, totalComprado)
VALUES (2, 'Proveedor B', 2, 10000, 5000);
INSERT INTO proveedores (codigo, nombre, tipo, limiteCredito, totalComprado)
VALUES (3, 'Proveedor C', 1, 3000, 1500);

INSERT INTO materias_primas (codigo, nombre, cantidad_actual, cantidad_minima, cantidad_reorder, ultimo_precio, proveedor)
VALUES (1, 'Materia Prima A', 100, 50, 80, 10, 1);
INSERT INTO materias_primas (codigo, nombre, cantidad_actual, cantidad_minima, cantidad_reorder, ultimo_precio, proveedor)
VALUES (2, 'Materia Prima B', 150, 75, 100, 15, 2);
INSERT INTO materias_primas (codigo, nombre, cantidad_actual, cantidad_minima, cantidad_reorder, ultimo_precio, proveedor)
VALUES (3, 'Materia Prima C', 200, 100, 150, 20, 1);

INSERT INTO componente_productos (producto, materia_prima, cantidad)
VALUES (1, 1, 2);
INSERT INTO componente_productos (producto, materia_prima, cantidad)
VALUES(1, 2, 3);
INSERT INTO componente_productos (producto, materia_prima, cantidad)
VALUES(2, 1, 1);

-------------------------------------------------------------------------------------

INSERT INTO OrdenProduccion (codigo, producto, cantidad, bodega, fecha, estado)
VALUES (1, 1, 100, 1, TO_DATE('2023-06-01', 'YYYY-MM-DD'), 1);
INSERT INTO OrdenProduccion (codigo, producto, cantidad, bodega, fecha, estado)
VALUES       (2, 2, 200, 2, TO_DATE('2023-06-01', 'YYYY-MM-DD'), 1);
INSERT INTO OrdenProduccion (codigo, producto, cantidad, bodega, fecha, estado)
VALUES       (3, 3, 150, 1, TO_DATE('2023-06-01', 'YYYY-MM-DD'), 0);

INSERT INTO OrdenTrabajo (codigo, ordenProduccion, fecha, estado)
VALUES (1, 1, TO_DATE('2023-06-01', 'YYYY-MM-DD'), 1);
INSERT INTO OrdenTrabajo (codigo, ordenProduccion, fecha, estado)
VALUES (2, 2, TO_DATE('2023-06-01', 'YYYY-MM-DD'), 1);
INSERT INTO OrdenTrabajo (codigo, ordenProduccion, fecha, estado)
VALUES (3, 3, TO_DATE('2023-06-01', 'YYYY-MM-DD'), 0);

INSERT INTO requisicion_materiales (OrdenTrabajo, material, cantidad, estado)
VALUES (1, 1, 10, 1);
INSERT INTO requisicion_materiales (OrdenTrabajo, material, cantidad, estado)
VALUES  (1, 2, 5, 0);
INSERT INTO requisicion_materiales (OrdenTrabajo, material, cantidad, estado)
VALUES  (2, 3, 8, 1);
--------------------------------------------------------------------------------------------

INSERT INTO facturas_proveedor (numero, fechaEmision, formaDePago, montoTotal, proveedor, saldo)
VALUES (1, TO_DATE('2023-06-21', 'YYYY-MM-DD'), 1, 500, 1, 500);
INSERT INTO facturas_proveedor (numero, fechaEmision, formaDePago, montoTotal, proveedor, saldo)
VALUES (2, TO_DATE('2023-06-22', 'YYYY-MM-DD'), 2, 1000, 2, 1000);
INSERT INTO facturas_proveedor (numero, fechaEmision, formaDePago, montoTotal, proveedor, saldo)
VALUES (3, TO_DATE('2023-06-23', 'YYYY-MM-DD'), 1, 800, 3, 800);


INSERT INTO Pago (codigo, montoPago)
VALUES (1, 500);
INSERT INTO Pago (codigo, montoPago)
VALUES(2, 1000);
INSERT INTO Pago (codigo, montoPago)
VALUES(3, 800);

INSERT INTO FechaUltimoPago (codigo, fecha, pagos)
VALUES (1, TO_DATE('2023-06-21', 'YYYY-MM-DD'), 1);
INSERT INTO FechaUltimoPago (codigo, fecha, pagos)
VALUES (2, TO_DATE('2023-06-22', 'YYYY-MM-DD'), 2);
INSERT INTO FechaUltimoPago (codigo, fecha, pagos)
VALUES (3, TO_DATE('2023-06-23', 'YYYY-MM-DD'), 3);

INSERT INTO facturas_prestamo (numero, fechaUltimoPago, factura)
VALUES (1, 1, 1);
INSERT INTO facturas_prestamo (numero, fechaUltimoPago, factura)
VALUES(2, 2, 2);
INSERT INTO facturas_prestamo (numero, fechaUltimoPago, factura)
VALUES(3, 3, 3);

/*INSERT INTO OrdenCompra (materia, proveedor, cantidad, estado)
VALUES (1, 1, 100, 1),
       (2, 2, 200, 1),
       (3, 3, 150, 1);

INSERT INTO solicitud_compra (codigo, materia, proveedor, cantidad, fecha, estado)
VALUES (1, 1, 1, 100, '2023-06-21', 1),
       (2, 2, 2, 200, '2023-06-22', 1),
       (3, 3, 3, 150, '2023-06-23', 1);*/

--

SET SERVEROUTPUT ON;

--SP008
DECLARE
  C3 SYS_REFCURSOR;
  v_nombre_vendedor vendedores.nombre%TYPE;
  v_codigo_vendedor vendedores.codigo%TYPE;
  v_codigo_cliente clientes.codigo%TYPE;
  v_nombre_cliente clientes.nombre%TYPE;
  v_nombre_zona zonas.nombre%TYPE;
  v_codigo_zona zonas.codigo%TYPE;
BEGIN
  sp008(C3);
  LOOP
    FETCH C3 INTO v_nombre_vendedor, v_codigo_vendedor, v_codigo_cliente, v_nombre_cliente, v_nombre_zona, v_codigo_zona;
    EXIT WHEN C3%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE('Vendedor: ' || v_nombre_vendedor || ',Codigo: ' || v_codigo_vendedor);
    DBMS_OUTPUT.PUT_LINE('Cliente: ' || v_nombre_cliente || ', Codigo: ' || v_codigo_cliente);
    DBMS_OUTPUT.PUT_LINE('Zona: ' || v_nombre_zona || ', Codigo: ' || v_codigo_zona);
    DBMS_OUTPUT.PUT_LINE('-----------------------------');
  END LOOP;
  CLOSE C3;
END;
/

--SP009
DECLARE
  C4 SYS_REFCURSOR;
  v_codigo_cliente clientes.codigo%TYPE;
  v_nombre_cliente clientes.nombre%TYPE;
  v_total_compra clientes.total_compra%TYPE;
BEGIN
  sp009(C4);
  LOOP
    FETCH C4 INTO v_codigo_cliente, v_nombre_cliente, v_total_compra;
    EXIT WHEN C4%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE('Cliente: ' || v_nombre_cliente || ', Codigo: ' || v_codigo_cliente || ', Total Compra: ' || v_total_compra);
  END LOOP;
  CLOSE C4;
END;
/

--SP0010
DECLARE
  C5 SYS_REFCURSOR;
  v_codigo_vendedor vendedores.codigo%TYPE;
  v_nombre_vendedor vendedores.nombre%TYPE;
  v_codigo_producto productos.codigo%TYPE;
  v_nombre_producto productos.nombre%TYPE;
  v_precio_venta productos.precio_venta%TYPE;
BEGIN
  sp010(C5);
  LOOP
    FETCH C5 INTO v_codigo_vendedor, v_nombre_vendedor, v_codigo_producto, v_nombre_producto, v_precio_venta;
    EXIT WHEN C5%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE('Vendedor: ' || v_nombre_vendedor || ', Codigo: ' || v_codigo_vendedor);
    DBMS_OUTPUT.PUT_LINE('Producto: ' || v_nombre_producto || ', Codigo: ' || v_codigo_producto || ', Precio de venta: ' || v_precio_venta);
    DBMS_OUTPUT.PUT_LINE('-----------------------------');
  END LOOP;
  CLOSE C5;
END;
/

--SP0011

DECLARE
  c6 SYS_REFCURSOR;
  vendedor_codigo vendedores.codigo%TYPE;
  vendedor_nombre vendedores.nombre%TYPE;
  cliente_codigo clientes.codigo%TYPE;
  cliente_nombre clientes.nombre%TYPE;
BEGIN
  sp011(c6);
  LOOP
    FETCH c6 INTO vendedor_codigo, vendedor_nombre, cliente_codigo, cliente_nombre;
    EXIT WHEN c6%NOTFOUND;
    -- Realiza cualquier operación adicional con los datos recuperados
    DBMS_OUTPUT.PUT_LINE('Vendedor: ' || vendedor_nombre || ', Codigo: ' || vendedor_codigo);
    DBMS_OUTPUT.PUT_LINE('Cliente: ' || cliente_nombre || ', Codigo: ' || cliente_codigo);
    DBMS_OUTPUT.PUT_LINE('-----------------------------');
  END LOOP;
  CLOSE c6;
END;
/

DECLARE
  c12 SYS_REFCURSOR;
  nombre productos.nombre%TYPE;
  cantidad lineas_factura.cantidad%TYPE;
  descripcion familias.descripcion%TYPE;
  vendedor vendedores.nombre%TYPE;
BEGIN
  sp012(c12);
  
  LOOP
    FETCH c12 INTO nombre, cantidad, descripcion, vendedor;
    EXIT WHEN c12%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE(nombre || ', ' || cantidad || ', ' || descripcion || ', Vendedor ' || vendedor);
  END LOOP;

  CLOSE c12;
END;
/

-----------------------BODEGUERO-------------------
SET SERVEROUTPUT ON;
DECLARE
  juan bodeguero;
  respuesta VARCHAR2(30);
BEGIN
  juan := bodeguero('Juan', 123);
  respuesta :=juan.actualizar_requisiciones();
  DBMS_OUTPUT.PUT_LINE(respuesta);
END;
/
--------------------------------------------------