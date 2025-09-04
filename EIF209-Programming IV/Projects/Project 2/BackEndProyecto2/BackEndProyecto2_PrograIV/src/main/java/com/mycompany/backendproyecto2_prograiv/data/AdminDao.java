/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.backendproyecto2_prograiv.data;

import com.mycompany.backendproyecto2_prograiv.logic.Admin;
import com.mycompany.backendproyecto2_prograiv.logic.Cliente;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Jorei
 */

//////
public class AdminDao {
    Database db;

    public AdminDao(Database db){
        this.db = db;
    }
    
    public Admin read(String cedula) throws Exception {
        String sql = "select * from administrador a inner join usuario u on a.usuario = u.cedula where a.usuario = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cedula);
        ResultSet rs = db.executeQuery(stm);
        UsuarioDao usuarioDao = new UsuarioDao(db);
        Admin admin;
        if (rs.next()) {
            admin = from(rs, "a");
            admin.setUsuario(usuarioDao.from(rs, "u"));
            return admin;
        } else {
            throw new Exception("Admin no Existe");
        }
    }
    
    public void save(Admin admin) throws Exception {
        String sql = "insert into administrador (usuario, nombre) values(?,?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, admin.getUsuario().getCedula());
        stm.setString(2, admin.getNombre());
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar admin");
        }
    }
    
    public Admin from(ResultSet rs, String alias) {
        try {
            Admin a = new Admin();
            a.setNombre(rs.getString(alias + ".nombre"));       
            return a;
        } catch (SQLException ex) {
            return null;
        }
    } 
}

//////
