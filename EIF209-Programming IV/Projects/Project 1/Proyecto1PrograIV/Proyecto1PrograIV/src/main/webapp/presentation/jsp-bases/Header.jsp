<%@page import="com.mycompany.proyecto1.logic.Usuario"%>
<% Usuario usuario=  (Usuario) session.getAttribute("usuario");  %>

<header>
    <div>
        <div>
            <a href="presentation/Index.jsp">
                Seguros infinitos
            </a>
        </div>

        <div><i class="fa-solid fa-phone"></i>+506 88888888</div>

        <div>
            <a href="presentation/acercaDe">
                Acerca de...
            </a>
        </div>

        <% if (usuario!=null){ %>
            <% if (usuario.getTipo()==1){%>
                <div>
                    <a href="presentation/cliente/polizas/show">
                        Polizas
                    </a>
                </div>
            <div>
                <a href="presentation/cliente/datos/show">
                    <i class="fa-sharp fa-solid fa-id-card"></i>
                    <%=usuario.getCedula()%>
                </a>
            </div>
            <%}%>

            <% if (usuario.getTipo()==2){%>
            <div>
                <i class="fa-sharp fa-solid fa-id-card"></i>
                <%=usuario.getCedula()%>
            </div>
            <%}%>
            <div>
                <a href="presentation/login/logout">
                    Logout
                </a>
            </div>

        <%}%>

        <% if (usuario==null){%>

        <div>
            <a href="presentation/login/show">
                Login
            </a>
        </div>

        <%}%>          
        
    </div>
</header>
