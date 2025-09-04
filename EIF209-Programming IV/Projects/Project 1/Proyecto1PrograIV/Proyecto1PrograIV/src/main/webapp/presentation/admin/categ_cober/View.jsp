<%-- 
    Document   : View
    Created on : 18 abr. 2023, 19:12:55
    Author     : Nicole
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="com.mycompany.proyecto1.logic.Categoria"%>
<%@page import="com.mycompany.proyecto1.logic.Cobertura"%>
<%@page import="com.mycompany.proyecto1.presentation.admin.categ_cober.Model"%>

<%Model model = (Model)request.getAttribute("model");%>
<!DOCTYPE html>
<html>
    
    <head>
        <title>Categorias y Coberturas Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/border.css" rel="stylesheet" type="text/css"/>

    </head>
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        <link href="/Proyecto1PrograIV/style/cat_cober.css" rel="stylesheet" type="text/css"/>
        
        <div>
        <h1>Categorias que actualmente existen</h1>
            
            <%for (Categoria cat : model.getCategorias()){%>
                <h3> <%=cat.getDetalle()%> </h3>
                
                <%for (Cobertura co : cat.getCobertura()){%>
                <div class="detalleCobertura"> <%=co.getDetalle()%> </div>
                <lable> Costo minimo: <%=co.getCostoMinimo()%> </lable>
                <lable> Porcentaje: <%=co.getPorcentaje()%>% </lable>
                <br>
                <%}%>
                
            <%}%>

        <div>
        <a href="presentation/admin/categoria/show"><button>Crear nueva categoria</button></a>
        </div>
        <div>
        <a href="presentation/admin/cobertura/show"><button>Crear nueva cobertura</button></a>
        </div>
        
        <a href="presentation/admin/blank/show">
            <button>
                <i class="fa-solid fa-arrow-left"></i>Regresar
            </button>
        </a>
        </div>
        
        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>
