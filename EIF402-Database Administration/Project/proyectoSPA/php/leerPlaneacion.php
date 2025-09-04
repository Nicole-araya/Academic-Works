<?php
// Incluir el archivo de conexión
include("conexion.php");

// Verificar si la conexión se estableció correctamente
if (!$conn) {
    $error_message = oci_error();
    die("Conexión fallida: " . $error_message['message']);
}

// Consulta SQL para obtener las preguntas con tipo "P"
$sql = "SELECT DESCRIPCION FROM PREGUNTAS WHERE TIPO = 'P'";

// Preparar la consulta
$statement = oci_parse($conn, $sql);

// Ejecutar la consulta
oci_execute($statement);

// Array para almacenar las preguntas
$preguntas = array();

// Recorrer los resultados de la consulta
while ($row = oci_fetch_assoc($statement)) {
    $preguntas[] = $row;
}


// Enviar las preguntas como respuesta (puede ser en formato JSON)
echo json_encode($preguntas);

// Cerrar el statement y la conexión
oci_free_statement($statement);
oci_close($conn);
?> 