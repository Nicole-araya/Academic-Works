package com.mycompany.backendproyecto2_prograiv.resources;

import com.mycompany.backendproyecto2_prograiv.logic.Service;
import com.mycompany.backendproyecto2_prograiv.logic.Usuario;
import jakarta.annotation.security.PermitAll;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.GET;
import jakarta.ws.rs.NotAcceptableException;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.Path;
import jakarta.ws.rs.Produces;
import jakarta.ws.rs.QueryParam;
import jakarta.ws.rs.core.MediaType;

@Path("/usuarios")
@PermitAll
public class Usuarios {
    
    /*
    @GET
    @Produces({MediaType.APPLICATION_JSON})
    public Usuario getUsuarioById(@QueryParam("id") String id, @QueryParam("clave") String clave) throws Exception {
        try {
            return Service.instance().usuarioFind(id, clave);
        } catch (Exception ex) {
            throw new Exception();
        }
    }
    */
    
}
