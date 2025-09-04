<%-- 
    Document   : View
    Created on : Apr 13, 2023, 1:07:25 AM
    Author     : Jorei
--%>

<%@page import="com.mycompany.proyecto1.presentation.login.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Usuario;"%>
<%@page import="com.mycompany.proyecto1.logic.Cliente;"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<% Model model = (Model) request.getAttribute("model"); %>
<% Map<String,String> errores = (Map<String,String>) request.getAttribute("errores"); %>
<% Map<String,String[]> form = (errores==null)?this.getForm(model):request.getParameterMap();%>
<!DOCTYPE html>
<html>
    
    <head>
        <title>Register</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/register.css" rel="stylesheet" type="text/css"/>

    </head>

    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>
        
        <form method="post" action="presentation/login/registerAdd">
            <table>
                <tr>
                    <td>Nombre:</td>
                    <td><input name="nombreFld" value="<%=form.get("nombreFld")[0]%>" title="<%=title("nombreFld",errores)%>" placeholder="Nombre"></td>
                </tr>
                <tr>
                    <td>Cedula:</td>
                    <td><input name="cedulaFld" value="<%=form.get("cedulaFld")[0]%>" title="<%=title("cedulaFld",errores)%>" placeholder="Indentificacion"></td>
                </tr>
                <tr>
                    <td>Clave:</td>
                    <td><input name="claveFld" value="<%=form.get("claveFld")[0]%>" title="<%=title("claveFld",errores)%>" placeholder="Clave"></td>
                </tr>
                <tr>
                    <td>Telefono:</td>
                    <td><input name="telefonoFld" value="<%=form.get("telefonoFld")[0]%>" title="<%=title("telefonoFld",errores)%>" placeholder="Telefono"></td>
                </tr>
                <tr>
                    <td>Correo:</td>
                    <td><input name="correoFld" value="<%=form.get("correoFld")[0]%>" title="<%=title("correoFld",errores)%>" placeholder="Correo"></td>
                </tr>
                <tr>
                    <td>Medio de pago:</td>
                    <td><input name="pagoFld" value="<%=form.get("pagoFld")[0]%>" title="<%=title("pagoFld",errores)%>" placeholder="Medio de pago"></td>
                </tr>

                <tr>
                    <td>
                        <input type="submit" name="registerBtn" value="Registarse">
                    </td>
                </tr>
            </table>
        </form>
                
        <a href="presentation/login/show">
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
       values.put("cedulaFld", new String[]{model.getCurrent().getCedula()});
       values.put("claveFld", new String[]{model.getCurrent().getClave()});
       values.put("nombreFld", new String[]{model.getCliente().getNombre()});
       values.put("telefonoFld", new String[]{model.getCliente().getTelefono()});
       values.put("correoFld", new String[]{model.getCliente().getCorreo()});
       values.put("pagoFld", new String[]{model.getCliente().getMedioPago()});
       return values;
    } 
%> 