package com.mycompany.backendproyecto2_prograiv.resources;

import com.mycompany.backendproyecto2_prograiv.logic.Cliente;
import com.mycompany.backendproyecto2_prograiv.logic.Service;
import com.mycompany.backendproyecto2_prograiv.logic.Usuario;
import jakarta.annotation.security.PermitAll;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpSession;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.DELETE;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.Path;
import jakarta.ws.rs.Produces;
import jakarta.ws.rs.QueryParam;
import jakarta.ws.rs.core.Context;
import jakarta.ws.rs.core.MediaType;

@Path("/session")
@PermitAll
public class Session {
    @Context
    HttpServletRequest request;
    
    @POST
    @Path("/login")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Usuario login(Usuario u) throws Exception {
        try {
            Usuario usuario = Service.instance().usuarioFind(u);
            request.getSession(true).setAttribute("usuario", usuario);
            return new Usuario(usuario.getCedula(),"",usuario.getTipo());
        } catch (Exception ex) {
            throw new Exception();
        }
    }
    
    @POST
    @Path("/register")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Usuario register(
            @QueryParam("nombre") String nombre, 
            @QueryParam("cedula") String cedula,
            @QueryParam("clave") String clave,
            @QueryParam("telefono") String telefono,
            @QueryParam("correo") String correo,
            @QueryParam("medioPago") String medioPago
    ) throws Exception {
        
        try{
            Usuario usuario = new Usuario(cedula, clave, 1);
            Cliente cliente = new Cliente(usuario, nombre, telefono, correo, medioPago);
            Service.instance().agregarCliente(cliente);
            request.getSession(true).setAttribute("usuario", usuario);
            return new Usuario(usuario.getCedula(),"",usuario.getTipo());
            
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @DELETE
    @Path("/logout")
    public void logout(){
        HttpSession session = request.getSession(true);
        session.removeAttribute("usuario");
        session.invalidate();
    }
    
}
