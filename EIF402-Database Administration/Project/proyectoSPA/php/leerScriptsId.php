<?php
// Incluir el archivo de conexión
include("conexion.php");

// Verificar si la conexión se estableció correctamente
if (!$conn) {
    $error_message = oci_error();
    die("Conexión fallida: " . $error_message['message']);
}

$ruta = $_POST['ruta'];

$sql = "SELECT * FROM respaldos WHERE rutaabsoluta  = :ruta";

// Preparar la consulta
$statement = oci_parse($conn, $sql);
oci_bind_by_name($statement, ":ruta", $ruta);

// Ejecutar la consulta
oci_execute($statement);

// Array para almacenar las preguntas
$datos = array();

// Recorrer los resultados de la consulta
while ($row = oci_fetch_assoc($statement)) {
    $datos[] = $row;
}



// Enviar las preguntas como respuesta (puede ser en formato JSON)
echo json_encode($datos);

// Cerrar el statement y la conexión
oci_free_statement($statement);
oci_close($conn);
?> 