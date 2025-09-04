<%-- 
    Document   : AgregarCober
    Created on : 11 abr. 2023, 18:48:50
    Author     : Nicole
--%>
<%@page import="com.mycompany.proyecto1.presentation.cliente.poliza.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Poliza"%>
<%@page import="com.mycompany.proyecto1.logic.Cobertura"%>
<%@page import="com.mycompany.proyecto1.logic.Categoria"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<% Model model = (Model) request.getAttribute("model"); %>
<!DOCTYPE html>
<html>
    <title>Coberturas Page</title>
    <head><%@ include file="/presentation/jsp-bases/Head.jsp"%></head>
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>
            
        <h1>Seleciona coberturas</h1>

            <form method="post" action="presentation/cliente/poliza/add2">
                <table>
                    <%for (Categoria cat : model.getCategorias()){%>
                    <tr><%=cat.getDetalle()%></tr>
                    <table>
                      <%for (Cobertura cober : cat.getCobertura()){%>
                      <tr>
                      <div>
                      <input type="radio" name="coberFld" value="<%=cober.getCod()%>">
                      <label><%=cober.getDetalle()%></label>
                      </div>
                      </tr>
                      <%}%>
                    </table>
                    <%}%>
                </table>
                <input type="submit" value="Agregar cobertura">
            </form>
                
                <a href="presentation/cliente/poliza/show">
                    <button>
                        <i class="fa-solid fa-arrow-left"></i> Regresar
                    </button>
                </a>

        </div>
        
        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>
