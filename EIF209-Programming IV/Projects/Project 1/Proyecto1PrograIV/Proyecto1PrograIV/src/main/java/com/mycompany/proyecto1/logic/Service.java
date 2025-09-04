/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.logic;

import com.mycompany.proyecto1.data.AdminDao;
import com.mycompany.proyecto1.data.CategoriaDao;
import com.mycompany.proyecto1.data.ClienteDao;
import com.mycompany.proyecto1.data.CoberturaDao;
import com.mycompany.proyecto1.data.Database;
import com.mycompany.proyecto1.data.MarcaDao;
import com.mycompany.proyecto1.data.ModeloDao;
import com.mycompany.proyecto1.data.PolizaDao;
import com.mycompany.proyecto1.data.UsuarioDao;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Service {
    
   int cod=4; //MI NUMERO ALEOTORIO POOR AHORA EN ESTE TIPO DE SERVICE sin BD
   
   private static Service uniqueInstance;
    
    public static Service instance(){
        if (uniqueInstance == null){
            uniqueInstance = new Service();
        }
        return uniqueInstance; 
    }
    
    Database database;
    UsuarioDao usuarioDao;
    ClienteDao clienteDao;
    AdminDao adminDao;
    CategoriaDao categoriaDao;
    CoberturaDao coberturaDao;
    MarcaDao marcaDao;
    ModeloDao modeloDao;
    PolizaDao polizaDao;
    
    private Service(){
        
        database = new Database();
        usuarioDao = new UsuarioDao(database);
        clienteDao = new ClienteDao(database);
        adminDao = new AdminDao(database);
        categoriaDao = new CategoriaDao(database);
        coberturaDao = new CoberturaDao(database);
        marcaDao = new MarcaDao(database);
        modeloDao = new ModeloDao(database);
        polizaDao = new PolizaDao(database);

    }

    
    public List<Marca> getMarcasModelo() throws Exception{ // done    
      return marcaDao.readAll();
    }
    
    public List<Categoria> getCategoriaCober() throws Exception{ // done
        return categoriaDao.readAll();
    }
    
    
    public List<Cliente> getClientesPoliza() throws Exception{    
      return clienteDao.readAll();
    }
    

    
    public Usuario usuarioFind(String cedula) throws Exception{ // done
        return usuarioDao.read(cedula);
    }
 
    
    public Cliente clienteFind(Usuario usuario) throws Exception{ // done
        return clienteDao.read(usuario.getCedula());
    }  
 
    
    public Admin adminFind(Usuario usuario) throws Exception{ // done
        return adminDao.read(usuario.getCedula());
    } 
    

    
    public List<Categoria> getCategorias() throws Exception{ // done 
        return categoriaDao.readAll();
    }
    


    
    public List<Marca> getMarcas() throws Exception{ // done
        return marcaDao.readAll();
    }
    

    
    public Marca marcaFind(String codigo) throws Exception{ // done
         return marcaDao.read(codigo);
    } 

    
    public Modelo modeloFind(String codigo) throws Exception{ // done
         return modeloDao.read(codigo);
    }

   
    public Categoria categoriaFind(String codigo) throws Exception{ // done
        return categoriaDao.read(codigo);
    }

    
    public Cobertura coberturaFind(String codigo) throws Exception{ // done
        return coberturaDao.read(codigo);
    }
    

    
    public List<Poliza> polizasFind(Cliente cliente) throws Exception{ // done
        return polizaDao.readMatchingCliente(cliente);
    }

    
    public void clienteUpdate(Cliente cliente) throws Exception{ // done
        clienteDao.update(cliente);
    }
    
    
    public Poliza polizaFind(String codigo) throws Exception{ // done
        return polizaDao.read(codigo);
    }
    
    
    public void agregarPoliza(Poliza poliza) throws Exception{ // done
        polizaDao.save(poliza);
    }

    
    public void agregarCliente(Cliente c) throws Exception{
        usuarioDao.save(c.getUser());
        clienteDao.save(c);
    }

    public void agregarMarca(Marca ma) throws Exception{  // done
        marcaDao.save(ma);
    }
        
    public void agregarModelo(Modelo mo) throws Exception{  // done
        modeloDao.save(mo);
    }
    
    public void agregarCobertura(Cobertura c) throws Exception{ // done
        coberturaDao.save(c);
    }
    
    public void agregarCategoria(Categoria c) throws Exception{ // done
        categoriaDao.save(c);
    }
    
    public String getLastCodigoModelo() throws Exception{
        return modeloDao.readLastCodigo();
    }
}
