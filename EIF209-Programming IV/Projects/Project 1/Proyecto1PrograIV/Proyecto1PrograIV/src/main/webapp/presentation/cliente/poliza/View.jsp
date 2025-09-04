<%-- 
    Document   : View
    Created on : 17 abr 2023, 23:58:39
    Author     : INTEL
--%>
<%@page import="com.mycompany.proyecto1.presentation.cliente.poliza.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Poliza"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%Model model = (Model)request.getAttribute("model");%>
<!DOCTYPE html>
<html>
    
    <head>
        <title>Poliza Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/poliza.css" rel="stylesheet" type="text/css"/>

    </head>
    
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>
        <table>
            <tr>
                <td>Numero de placa:</td>
                <td><%=model.getCurrent().getNumPlaca()%></td>
            </tr>
            <tr>
                <td>Marca:</td>
                <td><%=model.getCurrent().getModelo().getMarca().getMarca()%></td>
            </tr>
            <tr>
                <td>Modelo:</td>
                <td><%=model.getCurrent().getModelo().getModelo()%></td>
            </tr>
            <tr>
                <td>Año:</td>
                <td><%=model.getCurrent().getAnio()%></td>
            </tr>
            <tr>
                <td>Valor:</td>
                <td><%=model.getCurrent().getValor()%></td>
            </tr>
            <tr>
                <td>Plazo de pago:</td>
                <%if(model.getCurrent().getPlazopago() == 1){%>
                <td>Trimestral</td>
                <%}%>
                <%if(model.getCurrent().getPlazopago() == 2){%>
                <td>Semestral</td>
                <%}%>
                <%if(model.getCurrent().getPlazopago() == 3){%>
                <td>Anual</td>
                <%}%>
            </tr>
            <tr>
                <td>Fecha de vigencia:</td>
                <td><%=model.getCurrent().getFechavigencia()%></td>
            </tr>
            <tr>
                <td>Categoria:</td>
                <td><%=model.getCurrent().getCategoria().getDetalle()%></td>
            </tr>
            <tr>
                <td>Cobertura:</td>
                <td><%=model.getCurrent().getCobertura().getDetalle()%></td>
            </tr>
            <tr>
                <td>Costo:</td>
                <td><%=model.getCurrent().getCosto()%></td>
            </tr>
            
        </table>

        <a href="presentation/cliente/polizas/show">
            <button>
                <i class="fa-solid fa-arrow-left"></i> Regresar
            </button>
        </a>
            
        </div>
            
        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>
