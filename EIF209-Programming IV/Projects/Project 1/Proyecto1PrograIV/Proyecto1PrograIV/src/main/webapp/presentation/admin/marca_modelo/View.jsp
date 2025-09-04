<%-- 
    Document   : View
    Created on : 18 abr. 2023, 16:40:11
    Author     : Nicole
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="com.mycompany.proyecto1.logic.Marca"%>
<%@page import="com.mycompany.proyecto1.logic.Modelo"%>
<%@page import="com.mycompany.proyecto1.presentation.admin.marca_modelo.Model"%>

<%Model model = (Model)request.getAttribute("model");%>
<!DOCTYPE html>
<html>
    
    <head>
        <title>Marcas y Modelos Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/border.css" rel="stylesheet" type="text/css"/>
    </head>
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>
        <h1>Marcas que actualmente existen</h1>
        
        <div>
            <%for (Marca ma : model.getMarcas()){%>
            <div>
                <h3> <%=ma.getMarca()%> </h3>
                
                <%for (Modelo mo : ma.getModelos()){%>
                <div> <%=mo.getModelo()%> </div>
                <img src="presentation/admin/marca_modelo/image?idFld=<%=mo.getCod()%>"/>
                <%}%>
                
            </div>
            <%}%>
        </div>
        <div>
        <a href="presentation/admin/marca/addBlank">
            <button>Crear nueva marca</button>  
        </a>
        </div>
        <div>
        <a href="presentation/admin/modelo/show">
            <button>Crear nuevo modelo</button>  
        </a>
        </div>

        <a href="presentation/admin/blank/show">
            <button>
                <i class="fa-solid fa-arrow-left"></i> Regresar
            </button>
        </a>
        </div>

        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>

