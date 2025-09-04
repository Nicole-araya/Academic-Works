/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.backendproyecto2_prograiv.resources;

import com.mycompany.backendproyecto2_prograiv.logic.Cliente;
import com.mycompany.backendproyecto2_prograiv.logic.Categoria;
import com.mycompany.backendproyecto2_prograiv.logic.Cobertura;
import com.mycompany.backendproyecto2_prograiv.logic.Marca;
import com.mycompany.backendproyecto2_prograiv.logic.Modelo;
import com.mycompany.backendproyecto2_prograiv.logic.Poliza;
import com.mycompany.backendproyecto2_prograiv.logic.Service;
import jakarta.annotation.security.PermitAll;
import jakarta.annotation.security.RolesAllowed;
import jakarta.ws.rs.Consumes;
import jakarta.ws.rs.DefaultValue;
import jakarta.ws.rs.FormParam;
import jakarta.ws.rs.GET;
import jakarta.ws.rs.NotAcceptableException;
import jakarta.ws.rs.NotFoundException;
import jakarta.ws.rs.POST;
import jakarta.ws.rs.Path;
import jakarta.ws.rs.PathParam;
import jakarta.ws.rs.Produces;
import jakarta.ws.rs.QueryParam;
import jakarta.ws.rs.core.MediaType;
import jakarta.ws.rs.core.Response;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.List;

/**
 *
 * @author INTEL
 */
@Path("/administrador")
@PermitAll
public class Administrador {
    
    String location = "C:/Proyecto/seguros/";
    
    //LISTA CLIENTES
    @GET
    @Path("/clientes")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Cliente> listaClientes() throws Exception { 
        try {
            return Service.instance().getClientesPoliza();
        } catch (Exception ex) {
           throw new Exception();
        }
    }
    //LISTA CATEGORIAS Y COBERTURAS
    @GET
    @Path("/categorias")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Categoria> listaCategorias() throws Exception { 
        try {
            return Service.instance().getCategoriaCober();
        } catch (Exception ex) {
           throw new Exception();
        }
    }   
    
    //LISTA CATEGORIAS 
    @GET
    @Path("/onlyCategorias")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Categoria> onlyCategorias() throws Exception { 
        try {
            return Service.instance().getCategorias();
        } catch (Exception ex) {
           throw new Exception();
        }
    } 
    
    //LISTA MARCAS 
    @GET
    @Path("/onlyMarcas")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Marca> onlyMarcas() throws Exception {
        try {
            return Service.instance().getMarcas();
        } catch (Exception ex) {
            throw new Exception();
        }
    }
    
    //LISTA MARCA Y MODELOS
    @GET
    @Path("/marcas")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Marca> listaMarcas() throws Exception { 
        try {
            return Service.instance().getMarcasModelo();
        } catch (Exception ex) {
           throw new Exception();
        }
    }  
    
    //AGREGAR CATEGORIA
    @POST
    @Path("/newCategoria")
    @Consumes (MediaType.APPLICATION_JSON)
    @Produces({MediaType.APPLICATION_JSON})
    public void addCategoria(@QueryParam("detalle") String detalle) {
        try {
            Categoria ca=new Categoria(detalle);
            Service.instance().agregarCategoria(ca);
        } catch (Exception ex) {
            throw new NotFoundException();
        }
    } 
    
    //AGREGAR MARCA
    @POST
    @Path("/newMarca")
    @Consumes (MediaType.APPLICATION_JSON)
    @Produces({MediaType.APPLICATION_JSON})
    public void addMarca(@QueryParam("marca") String marca) {
        try {
            Marca m=new Marca();
            m.setMarca(marca);
            Service.instance().agregarMarca(m);
        } catch (Exception ex) {
            throw new NotFoundException();
        }
    } 
    
    //AGREGAR MODELO
    @POST
    @Path("/newModelo")
    @Consumes (MediaType.APPLICATION_JSON)
    @Produces({MediaType.APPLICATION_JSON})
    public void addModelo(@QueryParam("modelo") String modelo, @QueryParam("marcaCod") String marca) {
        try {
            Modelo mo=new Modelo();
            mo.setModelo(modelo);
            Marca m = Service.instance().marcaFind(marca);
            mo.setMarca(m);
            Service.instance().agregarModelo(mo);
        } catch (Exception ex) {
            throw new NotFoundException();
        }
    } 

    //IMAGEN MODELO
    @POST
    @Consumes(MediaType.MULTIPART_FORM_DATA)
    @Path("{nombreMo}/imagen")    //podria cambiar
    public void createImage(@PathParam("nombreMo") String modeloNom, @FormParam("imagen") InputStream in) {
        try {
            OutputStream out = new FileOutputStream(new File(location +modeloNom));
            in.transferTo(out);
            out.close();
        } catch (IOException ex) {
            throw new NotAcceptableException();
        }
    }
    
    @GET
    @Produces("image/png")
    @Path("{modelo}/imagen")    //podria cambiar
    public Response readImage(@PathParam("modelo") String modeloCod) {
        try {
            File file = new File(location+modeloCod);
            Response.ResponseBuilder response = Response.ok((Object) file);
            return response.build();
        } catch (Exception ex) {
            throw new NotFoundException();
        }
    }
    
    //AGREGAR COBERTURA
   @POST
   @Path("/newCobertura")
   @Consumes(MediaType.APPLICATION_JSON)
   @Produces(MediaType.APPLICATION_JSON)
   public void addCobertura(@QueryParam("detalle") String detalle,@QueryParam("costoMinimo") String costoMinimo,
       @QueryParam("porcentaje") String porcentaje,@QueryParam("categoria") String categoria) 
          {
       try {
           Categoria ca = Service.instance().categoriaFind(categoria);
           int costoMinimoInt = Integer.parseInt(costoMinimo);
           int porcentajeInt = Integer.parseInt(porcentaje);
           
           Cobertura co = new Cobertura(detalle, costoMinimoInt, porcentajeInt, ca);
           
           Service.instance().agregarCobertura(co);
       } catch (Exception ex) {
           throw new NotFoundException();
       }
   }
    
    //LISTA POLIZAS DEL CLIENTE
   
    @POST
    @Path("/polizas")
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces({MediaType.APPLICATION_JSON})
    public List<Poliza> polizasCliente(List<Poliza> p) throws Exception{
        List<Poliza> p1 = p;
       return p1;
    }
    
    //SEARCH
    
    @GET
    @Path("/searchCliente")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Cliente> findCliente(@DefaultValue("") @QueryParam("name") String name) throws Exception {
        try {
            return Service.instance().findByNombre(name);
        } catch (Exception ex) {
            throw new Exception();
        }
    }
    
    @GET
    @Path("/searchCategoria")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Categoria> findCategoria(@DefaultValue("") @QueryParam("name") String name) throws Exception {
        try {
            return Service.instance().findByNombreCategoria(name);
        } catch (Exception ex) {
            throw new Exception();
        }
    }
    
    @GET
    @Path("/searchMarca")
    @Produces({MediaType.APPLICATION_JSON})
    public List<Marca> findMarca(@DefaultValue("") @QueryParam("name") String name) throws Exception {
        try {
            return Service.instance().findByNombreMarca(name);
        } catch (Exception ex) {
            throw new Exception();
        }
    }
}