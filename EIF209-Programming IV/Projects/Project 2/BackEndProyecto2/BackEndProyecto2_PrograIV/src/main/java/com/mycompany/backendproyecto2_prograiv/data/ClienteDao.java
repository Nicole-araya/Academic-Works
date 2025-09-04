/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.backendproyecto2_prograiv.data;

import com.mycompany.backendproyecto2_prograiv.logic.Cliente;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Jorei
 */

//////
public class ClienteDao {
    Database db;

    public ClienteDao(Database db){
        this.db = db;
    }
    
    public Cliente read(String cedula) throws Exception {
        String sql = "select * from cliente c inner join usuario u on c.usuario = u.cedula where c.usuario = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cedula);
        ResultSet rs = db.executeQuery(stm);
        UsuarioDao usuarioDao = new UsuarioDao(db);
        Cliente cliente;
        if (rs.next()) {
            cliente = from(rs, "c");
            cliente.setUser(usuarioDao.from(rs, "u"));
            return cliente;
        } else {
            throw new Exception("Cliente no Existe");
        }
    }
    
    public List<Cliente> readAll() throws Exception {
        String sql = "select * from cliente c inner join usuario u on c.usuario = u.cedula";
        PreparedStatement stm = db.prepareStatement(sql);
        ResultSet rs = db.executeQuery(stm);
        
        UsuarioDao usuarioDao = new UsuarioDao(db);
        PolizaDao polizaDao = new PolizaDao(db);
        Cliente cliente;
        List<Cliente> clientes = new ArrayList();
        
        try {
            while(rs.next()){
                cliente = from(rs, "c");
                cliente.setUser(usuarioDao.from(rs, "u"));
                cliente.setPolizas(polizaDao.readMatchingCliente(cliente));
                clientes.add(cliente);
                
            }
            return clientes;
            
        } catch(Exception ignored) {
            throw new Exception("Cliente no Existe");
        }
    }
    
    public List<Cliente> findByNombre(String nombre) throws Exception {
        String sql = "select * from cliente c inner join usuario u on c.usuario = u.cedula where c.nombre like concat('%', ?, '%')";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, nombre);
        ResultSet rs = db.executeQuery(stm);
        
        UsuarioDao usuarioDao = new UsuarioDao(db);
        PolizaDao polizaDao = new PolizaDao(db);
        Cliente cliente;
        List<Cliente> clientes = new ArrayList();
        
        try {
            while(rs.next()){
                cliente = from(rs, "c");
                cliente.setUser(usuarioDao.from(rs, "u"));
                cliente.setPolizas(polizaDao.readMatchingCliente(cliente));
                clientes.add(cliente);
                
            }
            return clientes;
            
        } catch(Exception ignored) {
            throw new Exception("Cliente no Existe");
        }
    }
    
    public void save(Cliente cliente) throws Exception {
        String sql = "insert into cliente (usuario, nombre, telefono, correo, medioPago) values(?,?,?,?,?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cliente.getUser().getCedula());
        stm.setString(2, cliente.getNombre());
        stm.setString(3, cliente.getTelefono());
        stm.setString(4, cliente.getCorreo());
        stm.setString(5, cliente.getMedioPago());
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar cliente");
        }
    }
    
    public void update(Cliente cliente) throws Exception {
        String sql = "update cliente set usuario=?, nombre=?, telefono=?, correo=?, medioPago=? where usuario=?";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cliente.getUser().getCedula());
        stm.setString(2, cliente.getNombre());
        stm.setString(3, cliente.getTelefono());
        stm.setString(4, cliente.getCorreo());
        stm.setString(5, cliente.getMedioPago());
        stm.setString(6, cliente.getUser().getCedula());
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al actualizar cliente");
        }
    }
    
    public Cliente from(ResultSet rs, String alias) {
        try {
            Cliente c = new Cliente();
            c.setNombre(rs.getString(alias + ".nombre")); 
            c.setTelefono(rs.getString(alias + ".telefono"));
            c.setCorreo(rs.getString(alias + ".correo"));            
            c.setMedioPago(rs.getString(alias + ".medioPago"));            
            return c;
        } catch (SQLException ex) {
            return null;
        }
    } 
}

//////
