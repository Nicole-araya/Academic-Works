<%-- 
    Document   : Agregar
    Created on : 4 abr 2023, 16:16:23
    Author     : INTEL
--%>

<%@page import="com.mycompany.proyecto1.presentation.cliente.poliza.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Poliza"%>
<%@page import="com.mycompany.proyecto1.logic.Marca"%>
<%@page import="com.mycompany.proyecto1.logic.Modelo"%>
<%@page import="java.util.HashMap"%>
<%@page import="java.util.Map"%>

<% Model model = (Model) request.getAttribute("model"); %>
<% Map<String,String> errores = (Map<String,String>) request.getAttribute("errores"); %>
<% Map<String,String[]> form = (errores==null)?this.getForm(model):request.getParameterMap();%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
    
    <head>
        <title>Add Poliza Page</title>
        <link href="/Proyecto1PrograIV/style/agregar.css" rel="stylesheet" type="text/css"/>

        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
    </head>
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>

            <form method="post" action="presentation/cliente/poliza/add1">
                <table>
                    <tr>
                        <td>Placa:</td>
                        <td><input type="text" name="placaFld" value="<%=form.get("placaFld")[0]%>" title="<%=title("placaFld",errores)%>"></td>
                    </tr>
                    <tr>
                        <td>Marca-Modelo:</td>
                        <td>

                            <select name="modeloFld">
                                <%for(Marca marca: model.getMarcas()){%>
                                <option value= "<%=marca.getCod()%>" disabled> 
                                    <%=marca.getMarca()%>

                                    <%for (Modelo modelo : marca.getModelos()){%>
                                <option value="<%=modelo.getCod()%>">
                                    <%=modelo.getModelo()%>
                                </option>
                                <%}%>
                                </option>
                                <%}%>
                            </select>

                        </td>
                    </tr>
                    <tr>
                        <td>Año:</td>
                        <td><input type="text" name="anioFld" value="<%=form.get("anioFld")[0]%>" title="<%=title("anioFld",errores)%>"></td>
                    </tr>
                    <tr>
                        <td>Valor:</td>
                        <td><input type="text" name="valorFld" value="<%=form.get("valorFld")[0]%>" title="<%=title("valorFld",errores)%>"></td>
                    </tr>
                    <tr>
                        <td>Fecha de vigencia: </td>
                        <td>
                            <input type="Date" name="fechaVigenciaFld" value="<%=form.get("fechaVigenciaFld")[0]%>" title="<%=title("fechaVigenciaFld",errores)%>">
                        </td>
                    </tr>
                    <tr>
                        <td>Metodo de pago:</td>
                        <td>
                            <input type="radio" name="plazoFld" value="1" checked>
                            <label>Trimestral</label>
                            <input type="radio" name="plazoFld" value="2">
                            <label>Semestral</label>
                            <input type="radio" name="plazoFld" value="3">
                            <label>Anual</label>
                        </td>
                    </tr>
                    <tr><td><input type="submit" value="Solicitar Poliza"></td></tr>
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
       values.put("placaFld", new String[]{model.getCurrent().getNumPlaca()});
       values.put("anioFld", new String[]{String.valueOf(model.getCurrent().getAnio())});
       values.put("valorFld", new String[]{String.valueOf(model.getCurrent().getValor())});
       values.put("fechaVigenciaFld", new String[]{String.valueOf(model.getCurrent().getFechavigencia())});
       return values;
    } 
%> 
