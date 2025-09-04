<?php

// Validar si el formulario fue enviado
if (isset($_POST)) {
	$totalPreguntas = 0;
    $respuestaSI = 0;
    $respuestaNA = 0;
	
    // Iterar a través de las preguntas y guardar en la base de datos
    foreach ($_POST as $key => $value) {
        if (substr($key, 0, 1) === 'p' && isset($_POST['r' . substr($key, 1)])) {
			$totalPreguntas++;
			
            $descripcion = $_POST[$key];
            $respuesta = $_POST['r' . substr($key, 1)];
			
			if ($respuesta == 1) {
                $respuestaSI++;
            } elseif ($respuesta == 2) {
                $respuestaNA++;
            }
			
        }
    }
	if ($totalPreguntas > 0) {
        $resultadoCalculo = ($respuestaSI / ($totalPreguntas - $respuestaNA)) * 100;
    } else {
        $resultadoCalculo = 0;
    }

    // Respuesta JSON
    echo json_encode($resultadoCalculo);

    exit();
}

?>