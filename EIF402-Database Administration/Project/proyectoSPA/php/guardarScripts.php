<?php
// Incluir el archivo de conexión
include("conexion.php");

if (!$conn) {
    $error_message = oci_error();
    die("Conexión fallida: " . $error_message['message']);
}

$data = json_decode(file_get_contents("php://input"));

$rutaRespaldo = $data->rutaRespaldo;
$nombreRespaldo = $data->nombreRespaldo;
$rutaScript = $data->rutaScript;
$rutaSpfile = $data->rutaSpfile;
$rutaBitacora = $data->rutaBitacora;
$rutaControl = $data->rutaControl;
$nombresTS = $data->nombresTS;
$tipo = $data->tipo;

$nombresTSStr = implode(',', $nombresTS);

$rutaAbsoluta = $rutaRespaldo . "/" . $nombreRespaldo;

$sql = "INSERT INTO respaldos (rutaAbsoluta, rutaRespaldo, nombreRespaldo, rutaScript, rutaSpfile, rutaBitacora, rutaControl, nombresTS, tipo) 
VALUES (:rutaAbsoluta, :rutaRespaldo, :nombreRespaldo, :rutaScript, :rutaSpfile, :rutaBitacora, :rutaControl, :nombresTS, :tipo)";
$statementInsercion = oci_parse($conn, $sql);

oci_bind_by_name($statementInsercion, ":rutaAbsoluta", $rutaAbsoluta);
oci_bind_by_name($statementInsercion, ":rutaRespaldo", $rutaRespaldo);
oci_bind_by_name($statementInsercion, ":nombreRespaldo", $nombreRespaldo);
oci_bind_by_name($statementInsercion, ":rutaScript", $rutaScript);
oci_bind_by_name($statementInsercion, ":rutaSpfile", $rutaSpfile);
oci_bind_by_name($statementInsercion, ":rutaBitacora", $rutaBitacora);
oci_bind_by_name($statementInsercion, ":rutaControl", $rutaControl);
oci_bind_by_name($statementInsercion, ":nombresTS", $nombresTSStr);
oci_bind_by_name($statementInsercion, ":tipo", $tipo);

oci_execute($statementInsercion);

oci_free_statement($statementInsercion);
oci_close($conn);

?>