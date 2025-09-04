<%-- 
    Document   : View
    Created on : 18 abr. 2023, 14:18:09
    Author     : Nicole
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="com.mycompany.proyecto1.logic.Usuario"%>
<%@page import="com.mycompany.proyecto1.logic.Cliente"%>
<%@page import="com.mycompany.proyecto1.logic.Poliza"%>
<%@page import="com.mycompany.proyecto1.presentation.admin.clientes.Model"%>

<%Model model = (Model)request.getAttribute("model");%>
<!DOCTYPE html>
<html>
    
    <head>
        <title>Admin Clientes Page</title>
        <%@ include file="/presentation/jsp-bases/Head.jsp"%>
        <link href="/Proyecto1PrograIV/style/clientes.css" rel="stylesheet" type="text/css"/>

    </head>
    
    <body>
        <%@ include file="/presentation/jsp-bases/Header.jsp"%>
        
        <div>
        <h1>Clientes existentes</h1>
        
        <table>
            <tr>
                <th>Nombre</th>
                <th>Cedula</th>
                <th>Contacto</th>
                <th>Medio de pago</th>
                <th>Polizas</th>
            </tr>
            <%for(Cliente c : model.getClientes()){%>
            <tr class="info">
                <td><%=c.getNombre()%></td>
            
                <td><%=c.getUser().getCedula()%></td>
            
                <td>
                    <label>506+<%=c.getTelefono()%></label>
                    <label> <%=c.getCorreo()%></label>
                </td>
                
                <td><%=c.getMedioPago()%></td>
                <td>
                    <%for (Poliza p : c.getPolizas()){%>
                    <table class="detallesPoliza">
                        <tr>
                            <td>Placa del Vehiculo: <%=p.getNumPlaca()%></td>
                            <td>
                                Vehiculo: 
                                <%=p.getModelo().getMarca().getMarca()%>-
                                <%=p.getModelo().getModelo()%>
                            </td>
                            <td>Fecha de Vigencia: <%=p.getFechavigencia()%></td>
                            <td>Valor: <%=p.getValor()%></td>
                        </tr>   
                    </table>
                    <%}%>
                </td>
            </tr>
            <%}%>
        </table>
        
        <a href="presentation/admin/blank/show">
            <button>
                <i class="fa-solid fa-arrow-left"></i> Regresar
            </button>
        </a>
        </div>
        
        <%@ include file="/presentation/jsp-bases/Footer.jsp"%>
    </body>
</html>
