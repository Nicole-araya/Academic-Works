<%-- 
    Document   : View
    Created on : 19 abr 2023, 23:09:56
    Author     : INTEL
--%>

<%@page import="com.mycompany.proyecto1.presentation.admin.cobertura.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Categoria"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<% Model model = (Model) request.getAttribute("model"); %>
<% Map<String,String> errores = (Map<String,String>) request.getAttribute("errores"); %>
<% Map<String,String[]> form = (errores==null)?this.getForm(model):request.getParameterMap();%>

<!DOCTYPE html>
<html>
    
    <head>
        <title>Cobertura Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%></head>
        <link href="/Proyecto1PrograIV/style/border.css" rel="stylesheet" type="text/css"/>

    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>        
        <form method="post" action="presentation/admin/cobertura/add">
            <select name="categCombox">
                <%for (Categoria categoria : model.getCategorias()){%>
                <option value="<%=categoria.getCod()%>">
                    <%=categoria.getDetalle()%>
                </option>
                <%}%>
            </select>
            <div>Descripcion de la cobertura </div>
            <input type="text" name="descripcionFld" placeholder="Descripcion" value="<%=form.get("descripcionFld")[0]%>" title="<%=title("descripcionFld",errores)%>">
            <br>
            <input type="number" name="costoFld" placeholder="Costo minimo">
            <br>
            <input type="number" name="porcentajeFld" placeholder="Porcentaje">
            <br>
            <input type="submit" value="Guardar">
        </form>
        
            <div>
                <a href="presentation/admin/categ_cober/show">
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
       values.put("descripcionFld", new String[]{model.getSeleccionado().getDetalle()});
       return values;
    } 
%> 
