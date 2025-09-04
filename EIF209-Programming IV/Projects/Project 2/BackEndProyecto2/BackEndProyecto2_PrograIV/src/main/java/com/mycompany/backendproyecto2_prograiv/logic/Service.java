package com.mycompany.backendproyecto2_prograiv.logic;

import com.mycompany.backendproyecto2_prograiv.data.AdminDao;
import com.mycompany.backendproyecto2_prograiv.data.CategoriaDao;
import com.mycompany.backendproyecto2_prograiv.data.ClienteDao;
import com.mycompany.backendproyecto2_prograiv.data.CoberturaDao;
import com.mycompany.backendproyecto2_prograiv.data.Database;
import com.mycompany.backendproyecto2_prograiv.data.MarcaDao;
import com.mycompany.backendproyecto2_prograiv.data.ModeloDao;
import com.mycompany.backendproyecto2_prograiv.data.PolizaDao;
import com.mycompany.backendproyecto2_prograiv.data.UsuarioDao;
import java.util.ArrayList;
import java.util.List;

public class Service {
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
    
    public List<Poliza> getPolizasByClienteId(String id) throws Exception{
         return polizaDao.getPolizasByClienteId(id);
    }
    
    public Poliza getPolizasById(String idPoliza, String idCliente) throws Exception{
         return polizaDao.read(idPoliza, idCliente);
    }
    
    public List<Cliente> findByNombre(String nombre) throws Exception{    
        return clienteDao.findByNombre(nombre);
    }
    
    public List<Categoria> findByNombreCategoria(String nombre) throws Exception{   
        return categoriaDao.findByNombre(nombre);
    }
    
    public List<Marca> findByNombreMarca(String nombre) throws Exception{ 
        return marcaDao.findByNombre(nombre);
    }
    
    public List<Marca> getMarcasModelo() throws Exception{   
        return marcaDao.readAll();
    }
    
    public List<Categoria> getCategoriaCober() throws Exception{   
        return categoriaDao.readAll();
    }
    
    public List<Cliente> getClientesPoliza() throws Exception{    
        return clienteDao.readAll();
    }
    
    public Usuario usuarioFind(Usuario u) throws Exception{ 
        Usuario usuario = usuarioDao.read(u.getCedula());
        if(!usuario.getClave().equals(u.getClave())){
            throw new Exception();
        }
        return usuario;
    }
 
    public Cliente clienteFind(String id) throws Exception{ 
        return clienteDao.read(id);
    }  
    
    public Admin adminFind(Usuario usuario) throws Exception{ 
        return adminDao.read(usuario.getCedula());
    } 
    
    public List<Categoria> getCategorias() throws Exception{ 
        return categoriaDao.readAll();
    }
    
    public List<Marca> getMarcas() throws Exception{ 
        return marcaDao.readAll();
    }
    
    public int getCostoPoliza(int valor, List<String> coberturas) throws Exception{
        Poliza poliza = new Poliza();
        for(String cobertura : coberturas){
            poliza.getCoberturas().add(coberturaDao.read(cobertura));
        }
        poliza.setValor(valor);
        return poliza.getCosto();
    }
    
    public Marca marcaFind(String codigo) throws Exception{ 
        return marcaDao.read(codigo);
    } 
    
    public Modelo modeloFind(String codigo) throws Exception{ 
        return modeloDao.read(codigo);
    }
   
    public Categoria categoriaFind(String codigo) throws Exception{ 
        return categoriaDao.read(codigo);
    }
    
    public Cobertura coberturaFind(String codigo) throws Exception{ 
        return coberturaDao.read(codigo);
    }
    
    public List<Poliza> searchPolizaByPlaca(String cedula, String placa) throws Exception{ 
        return polizaDao.findByNombreMatchingClienteCedula(cedula, placa);
    }
    
    public void updateCliente(String cedula, String nombre, String telefono, String correo, String medioPago) throws Exception{
        Cliente cliente = new Cliente(new Usuario(cedula, "",1), nombre, telefono, correo, medioPago);
        clienteDao.update(cliente);
    }
    
    public Poliza getPolizaById(String id) throws Exception{
        return polizaDao.getPolizaById(id);
    }
    
    public void agregarPoliza(Poliza poliza) throws Exception{
        
        String idPoliza = polizaDao.save(poliza);
        
        for(Cobertura cobertura : poliza.getCoberturas()){
            polizaDao.saveCobertura(idPoliza, cobertura.getCod());
        }
    }
    
    public void agregarCliente(Cliente cliente) throws Exception{
        usuarioDao.save(cliente.getUser());
        clienteDao.save(cliente);
    }
    
    public void agregarMarca(Marca ma) throws Exception{ 
        marcaDao.save(ma);
    }
        
    public void agregarModelo(Modelo mo) throws Exception{ 
        modeloDao.save(mo);
    }
    
    public void agregarCobertura(Cobertura c) throws Exception{ 
        coberturaDao.save(c);
    }
    
    public void agregarCategoria(Categoria c) throws Exception{ 
        categoriaDao.save(c);
    }
    
    public String getLastCodigoModelo() throws Exception{
        return modeloDao.readLastCodigo();
    }
}
















/*
package com.mycompany.backendproyecto2_prograiv.logic;

import com.mycompany.backendproyecto2_prograiv.data.AdminDao;
import com.mycompany.backendproyecto2_prograiv.data.CategoriaDao;
import com.mycompany.backendproyecto2_prograiv.data.ClienteDao;
import com.mycompany.backendproyecto2_prograiv.data.CoberturaDao;
import com.mycompany.backendproyecto2_prograiv.data.Database;
import com.mycompany.backendproyecto2_prograiv.data.MarcaDao;
import com.mycompany.backendproyecto2_prograiv.data.ModeloDao;
import com.mycompany.backendproyecto2_prograiv.data.PolizaDao;
import com.mycompany.backendproyecto2_prograiv.data.UsuarioDao;
import java.util.List;

public class Service {
   
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
    
    public List<Cliente> findByNombre(String nombre) throws Exception{    
      return clienteDao.findByNombre(nombre);
    }
    
    public List<Cobertura> findByNombreCategoria(String nombre) throws Exception{   
      return coberturaDao.findByNombreCategoria(nombre);
    }
    
    public List<Modelo> findByNombreMarca(String nombre) throws Exception{ 
      return modeloDao.findByNombreMarca(nombre);
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
    
    public Usuario usuarioFind(Usuario u) throws Exception{ // done
        Usuario usuario = usuarioDao.read(u.getCedula());
        if(!usuario.getClave().equals(u.getClave())){
            throw new Exception();
        }
        return usuario;
    }
 
    
    public Cliente clienteFind(String id) throws Exception{ // done
        return clienteDao.read(id);
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

    
    public void agregarCliente(Cliente cliente) throws Exception{
        usuarioDao.save(cliente.getUser());
        clienteDao.save(cliente);
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
*/