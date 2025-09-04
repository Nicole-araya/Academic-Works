<?php
// Incluir el archivo de conexión
include("conexion.php");

// Verificar si la conexión se estableció correctamente
if (!$conn) {
    $error_message = oci_error();
    die("Conexión fallida: " . $error_message['message']);
}

// Consulta SQL para obtener las preguntas con tipo "P"
$sql = "SELECT * FROM sys.sqlarea_view";

// Preparar la consulta
$statement = oci_parse($conn, $sql);

// Ejecutar la consulta
if (!oci_execute($statement)) {
    exit();
            }

// Array para almacenar las preguntas
$sqltext = array();

// Recorrer los resultados de la consulta
while ($row = oci_fetch_assoc($statement)) {
    $sqltext[] = $row;
}


// Enviar las sqltext como respuesta (puede ser en formato JSON)
//header('Content-Type: application/json');
echo json_encode($sqltext);


// Cerrar el statement y la conexión
oci_free_statement($statement);
oci_close($conn);
?>
