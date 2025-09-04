<?php

$data = json_decode(file_get_contents("php://input"));


$rutaRespaldo = str_replace("\\", "/", rtrim($data->RUTARESPALDO, "\\"));
$nombreRespaldo = $data->NOMBRERESPALDO;
$rutaScript = str_replace("\\", "/", rtrim($data->RUTASCRIPT, "\\"));
$rutaSpfile = str_replace("\\", "/", rtrim($data->RUTASPFILE, "\\"));
$rutaBitacora = str_replace("\\", "/", rtrim($data->RUTABITACORA, "\\"));
$rutaControl = str_replace("\\", "/", rtrim($data->RUTACONTROL, "\\"));

$nombreArchivoRMAN = $rutaRespaldo . "/" . $nombreRespaldo . ".rman";


$response = array();


// Crear el archivo .rman

$archivoRMAN = fopen($nombreArchivoRMAN, 'w');

if ($archivoRMAN) {
    fwrite($archivoRMAN, "RUN {\n");
    fwrite($archivoRMAN, "  ALLOCATE CHANNEL ch1 TYPE DISK;\n");
    fwrite($archivoRMAN, "  BACKUP AS BACKUPSET DATABASE PLUS ARCHIVELOG FORMAT '$rutaRespaldo/$nombreRespaldo" . "_%U';\n");
    fwrite($archivoRMAN, "  BACKUP CURRENT CONTROLFILE FORMAT '$rutaControl/controlfile_%U';\n");
    fwrite($archivoRMAN, "  BACKUP SPFILE FORMAT '$rutaSpfile/spfile_%U';\n");

    fwrite($archivoRMAN, "}\n");
    fclose($archivoRMAN);

    $response['message'] = "Archivo RMAN creado con éxito.";
    

    $comando = "rman target SYS/root @XE cmdfile=$nombreArchivoRMAN log='$rutaBitacora/bitacora.log' APPEND";

    // Ejecutar el comando
    $output = shell_exec($comando);

    // Verificar si se generó algún resultado o salida
    if ($output !== null) {
        $response['message'] = "Arhivo ejecutado correctamente.";
    } else {
        $response['message'] = "Error al ejecutar el comando RMAN.";
    }

} else {
    $response['message'] = "No se pudo crear el archivo RMAN.";
}

echo json_encode($response);
?>