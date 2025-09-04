<?php

	$connection_string = "localhost/xe";
	$username = "userdba";
	$password = "root";
	//$database = "proyectobd";

	$conn = oci_connect($username, $password, $connection_string);
	
	/*if(!$conn){
		echo " NO Conectado";
	}else echo "Conectado";*/
	
?>
