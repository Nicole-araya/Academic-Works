<%-- 
    Document   : show
    Created on : 4 abr 2023, 12:50:17
    Author     : INTEL
--%>

<%@page import="com.mycompany.proyecto1.presentation.cliente.polizas.Model"%>
<%@page import="com.mycompany.proyecto1.logic.Poliza"%>
<%@page import="java.util.List"%>
<%@page import="java.util.ArrayList"%>

<%Model model = (Model) request.getAttribute("model");%>
<%List<Poliza> polizas = model.getPolizas();%>


<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <title>Polizas Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/polizas.css" rel="stylesheet" type="text/css"/>
    </head>
    
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        

        <div>
            <label class="form-label">Mis polizas </label>
            <a href="presentation/cliente/poliza/show"><i class="fa-solid fa-circle-plus"></i></a>
        </div>
            <div>
                <form method="post" action="presentation/cliente/poliza/details">
                    <table>
                        <tr>
                            <th>Numero</th>
                            <th>Placa</th>
                            <th>Fecha</th>
                            <th>Marca</th>
                            <th>Modelo</th>
                            <th>Valor</th>
                            <th>Ver</th>
                        </tr>
                        <% for(Poliza i : polizas){%>

                        <tr>
                            <td><%=i.getCod()%></td>

                            <td><%=i.getNumPlaca()%></td>

                            <td><%=i.getFechavigencia()%></td>  

                            <td><%=i.getModelo().getMarca().getMarca()%></td>

                            <td><%=i.getModelo().getModelo()%>
                                <img src="presentation/admin/marca_modelo/image?idFld=<%=i.getModelo().getCod()%>">
                            </td>

                            <td><%=i.getValor()%></td>


                            <td>
                                <button name="codigoPoliza" value="<%=i.getCod()%>" type="submit">
                                    <i class="fa-solid fa-magnifying-glass"></i>
                                </button>
                            </td>

                        </tr>

                        <%}%>
                    </table> 
                </form>
            </div>
        </div>

        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>
