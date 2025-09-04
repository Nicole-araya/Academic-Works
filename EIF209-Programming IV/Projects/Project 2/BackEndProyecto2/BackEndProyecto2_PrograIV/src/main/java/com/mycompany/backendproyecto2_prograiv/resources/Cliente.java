/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.backendproyecto2_prograiv.resources;

import com.mycompany.backendproyecto2_prograiv.logic.Categoria;
import com.mycompany.backendproyecto2_prograiv.logic.Marca;
import com.mycompany.backendproyecto2_prograiv.logic.Poliza;
import com.mycompany.backendproyecto2_prograiv.logic.Service;
import jakarta.annotation.security.PermitAll;
import jakarta.annotation.security.RolesAllowed;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.GET;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.Path;
import jakarta.ws.rs.Produces;
import jakarta.ws.rs.QueryParam;
import jakarta.ws.rs.core.MediaType;
import java.util.List;

@Path("/cliente")
@PermitAll
public class Cliente {
    
    @GET
    @Path("/getPolizasByClienteId")
    @Produces(MediaType.APPLICATION_JSON)
    public List<Poliza> getPolizasByClienteId(@QueryParam("id") String id) throws Exception {
        try {
            return Service.instance().getPolizasByClienteId(id);
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @GET
    @Path("/searchPolizaByPlaca")
    @Produces(MediaType.APPLICATION_JSON)
    public List<Poliza> searchPolizaByName(@QueryParam("idCliente") String idCliente, @QueryParam("placa") String placa) throws Exception {
        try {
            return Service.instance().searchPolizaByPlaca(idCliente, placa);
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @GET
    @Path("/getPolizaById")
    @Produces(MediaType.APPLICATION_JSON)
    public Poliza getPolizaById(@QueryParam("idPoliza") String idPoliza, @QueryParam("idCliente") String idCliente) throws Exception {
        try {
            return Service.instance().getPolizasById(idPoliza, idCliente);
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @GET
    @Path("/getCategorias")
    @Produces(MediaType.APPLICATION_JSON)
    public List<Categoria> getCategorias() throws Exception {
        try {
            return Service.instance().getCategoriaCober();
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @GET
    @Path("/getMarcas")
    @Produces(MediaType.APPLICATION_JSON)
    public List<Marca> getMarcas() throws Exception {
        try {
            return Service.instance().getMarcas();
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @POST
    @Path("/getCostoPoliza")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public int getCostoPoliza(@QueryParam("valor") String valor, List<String> coberturas) throws Exception {
        try {
            int valorPoliza = Integer.parseInt(valor);
            return Service.instance().getCostoPoliza(valorPoliza, coberturas);
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @POST
    @Path("/guardarPoliza")
    @Consumes(MediaType.APPLICATION_JSON)
    public void guardarPoliza(
            @QueryParam("numPlaca") String numPlaca,
            @QueryParam("fechaVigencia") String fechaVigencia,
            @QueryParam("idModelo") String idModelo,
            @QueryParam("anio") String anio,
            @QueryParam("valor") String valor,
            @QueryParam("plazoPago") String plazoPago,
            @QueryParam("idCliente") String idCliente,
            List<String> coberturas
    ) throws Exception {
        
        try{
            Poliza poliza = new Poliza();
            poliza.setNumPlaca(numPlaca);
            poliza.setFechavigencia(fechaVigencia);
            poliza.setModelo(Service.instance().modeloFind(idModelo));
            String year = anio.substring(0, 4);
            poliza.setAnio(Integer.parseInt(year));
            poliza.setValor(Integer.parseInt(valor));
            poliza.setPlazopago(Integer.parseInt(plazoPago));
            poliza.setCliente(Service.instance().clienteFind(idCliente));
            
            for(String idCobertura : coberturas){
                poliza.getCoberturas().add(Service.instance().coberturaFind(idCobertura));
            }
            
            Service.instance().agregarPoliza(poliza);
            
        } catch (Exception e) {
            throw new Exception();
        }
    }
    
    @GET
    @Path("/getClienteById")
    @Produces({MediaType.APPLICATION_JSON})
    public com.mycompany.backendproyecto2_prograiv.logic.Cliente getClienteById(@QueryParam("idCliente") String idCliente) throws Exception {
        try {
            return Service.instance().clienteFind(idCliente);
        } catch (Exception e) {throw new Exception();
        }
    }
    
    @GET
    @Path("/updateCliente")
    @Produces({MediaType.APPLICATION_JSON})
    public com.mycompany.backendproyecto2_prograiv.logic.Cliente updateCliente(
            @QueryParam("cedula") String cedula,
            @QueryParam("nombre") String nombre,
            @QueryParam("telefono") String telefono,
            @QueryParam("correo") String correo,
            @QueryParam("medioPago") String medioPago
            ) throws Exception {
        try {
            Service.instance().updateCliente(cedula, nombre, telefono, correo, medioPago);
            return Service.instance().clienteFind(cedula);
        } catch (Exception e) {throw new Exception();
        }
    }
    
    
}
