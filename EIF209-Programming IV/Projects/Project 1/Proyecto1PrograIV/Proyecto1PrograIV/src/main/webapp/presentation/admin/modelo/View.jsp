<%-- 
    Document   : View
    Created on : 18 abr. 2023, 18:04:41
    Author     : Nicole
--%>

<%@page import="com.mycompany.proyecto1.presentation.admin.modelo.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Marca"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<% Model model = (Model) request.getAttribute("model"); %>
<% Map<String,String> errores = (Map<String,String>) request.getAttribute("errores"); %>
<% Map<String,String[]> form = (errores==null)?this.getForm(model):request.getParameterMap();%>

<!DOCTYPE html>
<html>
    
    <head>
        <title>Marca Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/border.css" rel="stylesheet" type="text/css"/>

    </head>
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>

            <form method="post" action="presentation/admin/modelo/add" enctype="multipart/form-data">
                <select name="marcaCombox">
                    <%for (Marca ma : model.getMarcas()){%>
                    <option value="<%=ma.getCod()%>">
                        <%=ma.getMarca()%>
                    </option>
                    <%}%>
                </select>
                <label>Descripcion del modelo: </label>
                <input type="text" name="descripcionFld" placeholder="Descripcion" value="<%=form.get("descripcionFld")[0]%>" title="<%=title("descripcionFld",errores)%>">
                <div>
                    <div>Subir imagen del modelo</div>
                    <input type="file" name="imagen" accept="image/*" id="imagen">
                </div>
                <div>
                <input type="submit" value="Guardar">
                </div>
            </form>
            <div>
                <a href="presentation/admin/marca_modelo/show">
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
       values.put("descripcionFld", new String[]{model.getSeleccionado().getModelo()});
       return values;
    } 
%> 