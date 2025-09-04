<%-- 
    Document   : Menu
    Created on : 19 abr 2023, 15:48:03
    Author     : INTEL
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    
    <head>
        <title>Admin Option Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/border.css" rel="stylesheet" type="text/css"/>

    </head>
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>
            <a href="presentation/admin/clientes/show">
                <button>
                    Ver Clientes
                </button>
            </a>
        </div>
 
        <div>
            <a href="presentation/admin/categ_cober/show">
                <button>
                    Administrar categorias y coberturas
                </button>
            </a>
        </div>
        <div>
            <a href="presentation/admin/marca_modelo/show">
                <button>
                    Administrar vehiculos
                </button>
            </a>
        </div>
        
        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>
