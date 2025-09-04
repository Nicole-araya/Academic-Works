<?php
// Incluir el archivo de conexión
include("conexion.php");

// Verificar si la conexión se estableció correctamente
if (!$conn) {
    $error_message = oci_error();
    die("Conexión fallida: " . $error_message['message']);
}

$ruta = $_POST['ruta'];

$response = array();

$sql = "DELETE FROM respaldos WHERE rutaabsoluta  = :ruta";

// Preparar la consulta
$statement = oci_parse($conn, $sql);
oci_bind_by_name($statement, ":ruta", $ruta);

// Ejecutar la consulta
oci_execute($statement);
oci_commit($conn);

$response['message'] = "Archivo RMAN borrado con éxito.";

// Cerrar el statement y la conexión
oci_free_statement($statement);
oci_close($conn);

echo json_encode($response);
?>