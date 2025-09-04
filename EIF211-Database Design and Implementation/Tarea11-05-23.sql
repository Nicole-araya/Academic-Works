CREATE OR REPLACE PROCEDURE P0090(wcodZona INT, wcodProd INT, wcantidad INT, wtipoM INT, V1 OUT INT, V2 OUT INT, V3 OUT INT) IS

zona INTEGER;
prod INTEGER;
cantidad INTEGER;

BEGIN
 OPEN wcursor FOR SELECT * FROM invetario;
 FETCH wcursor INTO prod, zona, cantidad;

 IF wcodZona IS NULL THEN
      V3 := V3 + 1;
      V1 := V1 + 1;
      
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,1);
    
    ELSIF wcodProd IS NULL THEN
      V3 := V3 + 1;
      V1 := V1 + 1;
      
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,2);
        
    ELSIF wtipoM != 1 AND wtipoM != 2 THEN
      V3 := V3 + 1;
      V1 := V1 + 1;
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,4);
        
     ELSIF  (cantidad - wcantidad) <= 0 OR wcantidad <= 0 THEN
      V3 := V3 + 1;
      V1 := V1 + 1;
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,3);
        
    ELSIF wtipoM = 1 THEN
      UPDATE inventario
      SET cantidad = cantidad - wcantidad
      WHERE zona = wcodZona AND prod = wcodProd;
      V1 := V1 + 1;
      V2 := V2 + 1;
      
    ELSIF wtipoM = 2  THEN
      UPDATE inventario
      SET cantidad = cantidad + wcantidad
      WHERE zona = wcodZona AND prod = wcodProd;
      V1 := V1 + 1;
      V2 := V2 + 1;
    
    END IF;

CLOSE wcursor;
  COMMIT;

END P0090;
/


CREATE OR REPLACE PROCEDURE P0089(WCTDP OUT INT, WCTDA OUT INT, WCTEE OUT INT) IS
  wcod INTEGER;
  wcodZona INTEGER;
  wcodProd INTEGER;
  wcantidad INTEGER;
  wtipoM INTEGER;
  
  V1 INTEGER;
  V2 INTEGER;
  V3 INTEGER;
  wcursor SYS_REFCURSOR;

BEGIN
   OPEN wcursor FOR
    SELECT * FROM T1
    UNION
    SELECT * FROM T2
    UNION
    SELECT * FROM T3;
    
  FETCH wcursor INTO wcod, wcodProd, wcodZona, wcantidad, wtipoM;

  WHILE wcursor%FOUND LOOP
   
   P0090(wcodZona,wcodProd,wcantidad,wtipoM, V1,V2,V3); 
   WCTDP:=WCTDP+V1;
   WCTDA:=WCTDA+V2;
   WCTEE:=WCTEE+V3;

    FETCH wcursor INTO wcod, wcodProd, wcodZona, wcantidad, wtipoM;
  END LOOP;

  CLOSE wcursor;
  COMMIT;

END P0089;
/
