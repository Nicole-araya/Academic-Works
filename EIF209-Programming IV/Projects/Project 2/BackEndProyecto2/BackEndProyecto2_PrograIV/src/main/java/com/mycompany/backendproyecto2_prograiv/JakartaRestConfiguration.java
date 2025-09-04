package com.mycompany.backendproyecto2_prograiv;

import com.mycompany.backendproyecto2_prograiv.resources.Cliente;
import com.mycompany.backendproyecto2_prograiv.resources.Administrador;
import com.mycompany.backendproyecto2_prograiv.resources.Clientes;
import com.mycompany.backendproyecto2_prograiv.resources.CustomAuthentication;
import com.mycompany.backendproyecto2_prograiv.resources.Session;
import com.mycompany.backendproyecto2_prograiv.resources.Usuarios;
import jakarta.annotation.security.DeclareRoles;
import jakarta.ws.rs.ApplicationPath;
import jakarta.ws.rs.core.Application;
import java.util.HashSet;
import java.util.Set;

@ApplicationPath("api")
@DeclareRoles({"1","2"})
public class JakartaRestConfiguration extends Application {
    @Override
    public Set<Class<?>> getClasses() {
        HashSet<Class<?>> classes = new HashSet<>();
        classes.add(Session.class);
        classes.add(CustomAuthentication.class);
        classes.add(Usuarios.class);
        classes.add(Clientes.class);
        classes.add(Cliente.class);
        classes.add(Administrador.class);
        return classes;
    }     
}
