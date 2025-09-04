
<%-- 
    Document   : View
    Created on : 18 abr. 2023, 19:25:38
    Author     : Nicole
--%>
<%@page import="com.mycompany.proyecto1.presentation.admin.categoria.Model"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<% Model model = (Model) request.getAttribute("model"); %>
<% Map<String,String> errores = (Map<String,String>) request.getAttribute("errores"); %>
<% Map<String,String[]> form = (errores==null)?this.getForm(model):request.getParameterMap();%>

<!DOCTYPE html>
<html>
    
    <head>
        <title>Categoria Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/border.css" rel="stylesheet" type="text/css"/>

    </head>
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>
        
        <form method="post" action="presentation/admin/categoria/add">
            <label>Descripcion de la categoria: </label>
            <input type="text" name="descripcionFld" placeholder="Descripcion" value="<%=form.get("descripcionFld")[0]%>" title="<%=title("descripcionFld",errores)%>">
            <input type="submit" value="Guardar">
        </form>
        
            <div>
                <a href="presentation/admin/blank/show">
                    <button>
                        <i class="fa-solid fa-arrow-left"></i> Regresar
                    </button>
                </a>
            </div>
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
       values.put("descripcionFld", new String[]{model.getCurrent().getDetalle()});
       return values;
    } 
%> 