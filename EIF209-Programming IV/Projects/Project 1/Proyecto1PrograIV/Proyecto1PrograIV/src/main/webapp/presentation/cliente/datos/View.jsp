<%-- 
    Document   : View
    Created on : 4 abr 2023, 23:09:13
    Author     : INTEL
--%>
<%@page import="com.mycompany.proyecto1.presentation.cliente.datos.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Usuario"%>
<%@page import="com.mycompany.proyecto1.logic.Cliente"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<% Model model = (Model) request.getAttribute("model"); %>
<% Map<String,String> errores = (Map<String,String>) request.getAttribute("errores"); %>
<% Map<String,String[]> form = (errores==null)?this.getForm(model):request.getParameterMap();%>

<!DOCTYPE html>
<html>
    
    <head>
        <title>Cliente Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/datos.css" rel="stylesheet" type="text/css"/>

    </head>
    <body>        
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>

        <div>
        
        <form method="post" action="presentation/cliente/datos/update">

            <table>
            <tr>
                <td>Nombre: </td>
                <td><input type="text" name="nombreFld" value="<%=form.get("nombreFld")[0]%>" readonly></td>
            </tr>
            <tr>
                <td>Telefono: </td>
                <td><input type="text" name="telefonoFld" value="<%=form.get("telefonoFld")[0]%>" title="<%=title("telefonoFld",errores)%>"></td>
            </tr>
            <tr>
                <td>Correo: </td>
                <td><input type="text" name="correoFld" value="<%=form.get("correoFld")[0]%>" title="<%=title("correoFld",errores)%>"></td>
            </tr>
            <tr>
                <td>Medio de Pago: </td>
                <td><input type="text" name="medioFld" value="<%=form.get("medioFld")[0]%>" title="<%=title("medioFld",errores)%>"></td>
            </tr>
            <tr>
                <td><button type="submit">Actualizar datos</button></td>
            </tr>
            </table>
        </form>
            <a href="presentation/cliente/polizas/show">
                <button>
                    <i class="fa-solid fa-arrow-left"></i> Regresar
                </button>
            </a>
            
            </div>
            
        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>
<%!
    
    private String title(String campo, Map<String,String> errores){
      if ( (errores!=null) && (errores.get(campo)!=null) )
        return errores.get(campo);
      else
        return "";
    }

    private Map<String,String[]> getForm(Model model){
       Map<String,String[]> values = new HashMap<>();
       values.put("nombreFld", new String[]{String.valueOf(model.getCurrent().getNombre())});
       values.put("telefonoFld", new String[]{String.valueOf(model.getCurrent().getTelefono())});
       values.put("correoFld", new String[]{String.valueOf(model.getCurrent().getCorreo())});
       values.put("medioFld", new String[]{String.valueOf(model.getCurrent().getMedioPago())});
       return values;
    } 
%> 