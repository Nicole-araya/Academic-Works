<%-- 
    Document   : View
    Created on : 27 mar 2023, 10:58:53
    Author     : ESCINF
--%>

<%@page import="com.mycompany.proyecto1.presentation.login.Model"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>

    <head>
        <title>Login</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/login.css" rel="stylesheet" type="text/css"/>
    </head>
    
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <% Model model = (Model) request.getAttribute("model"); %>
        <% Map<String,String> errores = (Map<String,String>) request.getAttribute("errores"); %>
        <% Map<String,String[]> form = (errores==null)?this.getForm(model):request.getParameterMap();%>
        
        <div>

            <br>
            <i class="fa-regular fa-id-badge"></i>

            <form method="POST" action="presentation/login/login">
                <div class="panel">
                    <div class="fila">
                        <div>Cedula</div>
                        <div class="campo"><input type="text" name="cedulaFld" value="<%=form.get("cedulaFld")[0]%>" title="<%=title("cedulaFld",errores)%>" placeholder="Identificacion"></div>
                    </div>
                    <div class="fila">
                        <div>Clave</div>
                        <div class="campo"><input type="password" name="claveFld" value="<%=form.get("claveFld")[0]%>" title="<%=title("claveFld",errores)%>" placeholder="Clave"></div>
                    </div>
                    <div><input type= "submit" name="ingresar" value="Ingresar"></div>
                </div>
            </form>

            <form method="post" action="presentation/login/registerBlank">
                <p> No tiene cuenta?... </p>
                <div><input type= "submit" name="regist" value="Registrese aqui"></div>
            </form>

            <br>
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
       return values;
    } 
%> 