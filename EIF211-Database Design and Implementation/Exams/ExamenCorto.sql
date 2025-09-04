CREATE OR REPLACE PROCEDURE P0089(CTDP OUT INT, CTDA OUT INT, CTEE OUT INT) IS
  wcod INTEGER;
  wcodProd INTEGER;
  wcodZona INTEGER;
  wcantidad INTEGER;
  wtipoM INTEGER;

  CURSOR wcursor IS
    SELECT * FROM Tabla_movimiento_1, Tabla_movimiento_2, Tabla_movimiento_3;

BEGIN
  OPEN wcursor;
  FETCH wcursor INTO wcod, wcodProd, wcodZona, wcantidad, wtipoM;

  WHILE wcursor%FOUND LOOP
    -- METER EN LA TABLAERROR --
    IF wcodZona IS NULL THEN
      CTEE := CTEE + 1;
      CTDP := CTDP + 1;
      
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,1);
    
    ELSIF wcodProd IS NULL THEN
      CTEE := CTEE + 1;
      CTDP := CTDP + 1;
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,2);
        
    ELSIF wtipoM != 1 AND wtipoM != 2 THEN
      CTEE := CTEE + 1;
      CTDP := CTDP + 1;
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,3);
    
    ELSIF wtipoM = 1 AND (SELECT cantidad FROM inventario WHERE codZona = wcodZona AND codProd = wcodProd) - wcantidad > 0 THEN
      UPDATE inventario
      SET cantidad = (SELECT cantidad FROM inventario WHERE codZona = wcodZona AND codProd = wcodProd) - wcantidad
      WHERE codZona = wcodZona AND codProd = wcodProd;
    ELSIF wtipoM = 2  THEN
      UPDATE inventario
      SET cantidad = (SELECT cantidad FROM inventario WHERE codZona = wcodZona AND codProd = wcodProd) + wcantidad
      WHERE codZona = wcodZona AND codProd = wcodProd; 
      
    ELSE
      CTEE := CTEE + 1;
      CTDP := CTDP + 1;
        INSERT INTO Terrores (codProd, codZona, cantidad, tipoError)
        VALUES ( wcodProd, wcodZona, wcantidad,4);
    END IF;

    FETCH wcursor INTO wcod, wcodProd, wcodZona, wcantidad, wtipoM;
  END LOOP;

  CLOSE wcursor;
  COMMIT;

END P0089;
/
