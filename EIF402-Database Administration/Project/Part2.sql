
-------------------------------------------------------SQLTEXT----------------------------------------------
--EN SYS
---Haciendo view Y dando permisos
GRANT SELECT ON sqlarea_view TO userdba;

CREATE OR REPLACE VIEW sqlarea_view AS
SELECT DISTINCT
  vs.hash_value AS idprocess,
  TO_CHAR(TO_DATE(vs.first_load_time, 'YYYY-MM-DD/HH24:MI:SS'), 'YYYY/MM/DD HH24:MI:SS') AS first_load_time,
  vs.sql_text AS sqlText,
  au.USERNAME AS parseuser
FROM v$sqlarea vs, all_users au
WHERE (parsing_user_id != 0) AND (au.user_id(+) = vs.parsing_user_id) AND (executions >= 1)
ORDER BY first_load_time DESC;


----SQLTEXT---EN userdba
 
SELECT * FROM sys.sqlarea_view;


-----------------------------------------------------CACHEBUFFER----------------------------------------------------------

----------------------EN userdba-------------
CREATE TABLE cachetable (
    codigo int,
    fecha_hora VARCHAR2(50),
    total_size_mb NUMBER,
    free_space_mb NUMBER,
    used_size_mb NUMBER
);
CREATE SEQUENCE seq_cache MINVALUE 1 START WITH 1 INCREMENT BY 1 CACHE 200;


------------------------EN SYS ---------------------------

CREATE OR REPLACE PROCEDURE cachebuffer_values AS
    total_size_mb NUMBER;
    free_space_mb NUMBER;
    used_size_mb NUMBER;
    fecha_actual VARCHAR2(50);
BEGIN
    -- Calcular los valores
    SELECT ROUND(bytes/(1024*1024), 5) INTO total_size_mb FROM v$sgainfo WHERE name = 'Buffer Cache Size';
    SELECT ROUND(SUM(CASE WHEN name = 'buffer_cache' THEN bytes ELSE 0 END) / (1024 * 1024), 5) INTO used_size_mb FROM v$sgastat;
    SELECT ROUND(SUM(CASE WHEN name = 'free memory' THEN bytes ELSE 0 END) / (1024 * 1024), 5) INTO free_space_mb FROM v$sgastat;
    
    fecha_actual := TO_CHAR(SYSDATE, 'YYYY/MM/DD HH24:MI:SS');

    -- Insertar los valores en la tabla chachetable
    INSERT INTO userdba.cachetable (codigo, fecha_hora, total_size_mb, free_space_mb, used_size_mb)
    VALUES (userdba.seq_cache.NEXTVAL, fecha_actual, total_size_mb, free_space_mb, used_size_mb);
    
    COMMIT;
END cachebuffer_values;
/


BEGIN
    cachebuffer_values;
END;


--------------------------HWM del BD----------------------------------------------------------------------
------EN USERDBA-------
CREATE TABLE CBLog (
    codigo int,
    fecha_hora VARCHAR2(500),
    idprocess NUMBER,
    log_user VARCHAR2(500),
    sql_detail VARCHAR2(1000),
 constraint pkcodigo primary key (codigo)
);

CREATE SEQUENCE seq_CBLog MINVALUE 1 START WITH 1 INCREMENT BY 1 CACHE 200;

------------------EN SYS*-------------------

CREATE OR REPLACE PROCEDURE monitor_cache_buffer_consumption AS
    v_total_cache_mb NUMBER;
    v_used_cache_mb NUMBER;
    v_consumption_pct NUMBER;
    v_sql_text varchar2(1000);
    v_sid NUMBER;
    v_username varchar2(500);
    fecha_actual VARCHAR2(500);
    vlast DATE;
BEGIN
    -- Obtener el tamaño total y el espacio utilizado de la memoria caché del buffer
    SELECT bytes / (1024 * 1024) INTO v_total_cache_mb
    FROM v$sgainfo
    WHERE name = 'Buffer Cache Size';
    
    SELECT SUM(CASE WHEN name = 'buffer_cache' THEN bytes ELSE 0 END) / (1024 * 1024) INTO v_used_cache_mb
    FROM v$sgastat;
    
    -- Calcular el porcentaje de consumo
    v_consumption_pct := (v_used_cache_mb / v_total_cache_mb) * 100;
    
    -- Si el consumo supera el 85%, registrar una alerta en CBLog
    IF v_consumption_pct > 85 THEN
        -- Obtener la sentencia SQL que causó la alerta
        
        SELECT idprocess, sqlText, parseuser, last_active_time into v_sid,v_sql_text,v_username,vlast
        FROM (
            SELECT
                vs.hash_value AS idprocess,
                vs.sql_text AS sqlText,
                au.USERNAME AS parseuser,
                vs.last_active_time,
                ROW_NUMBER() OVER (ORDER BY vs.last_active_time DESC) AS rn
            FROM v$sqlarea vs
            LEFT JOIN all_users au ON vs.parsing_user_id = au.user_id
            WHERE vs.parsing_user_id != 0 AND vs.executions >= 1
        )
        WHERE rn = 1
        FETCH FIRST ROW ONLY; -- Obtener solo una fila (la más reciente)
        
        fecha_actual := TO_CHAR(SYSDATE, 'YYYY/MM/DD HH24:MI:SS');
        
        INSERT INTO userdba.CBLog (codigo, fecha_hora, idprocess, log_user, sql_detail)
        VALUES (userdba.seq_CBLog.NEXTVAL, fecha_actual, v_sid, v_username, v_sql_text);
        COMMIT;
    END IF;
END monitor_cache_buffer_consumption;
/


BEGIN
    monitor_cache_buffer_consumption;
END;
/
----------------------------------------------------------------------------------------------------------------------

















