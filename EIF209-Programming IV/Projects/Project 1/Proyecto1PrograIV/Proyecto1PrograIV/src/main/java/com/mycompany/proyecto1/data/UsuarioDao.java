/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.data;

import com.mycompany.proyecto1.logic.Usuario;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Jorei
 */


//////
public class UsuarioDao {
    Database db;

    public UsuarioDao(Database db){
        this.db = db;
    }
    
    public Usuario read(String cedula) {
        String sql = "select " +
                "* " +
                "from  usuario u " +
                "where u.cedula=?";   
        try { 
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cedula);
        ResultSet rs = db.executeQuery(stm);
            if (rs.next()) {
                return from(rs, "u");
            } else {
                return null;
            }
        } catch (SQLException ex) {
             return null;
        }
    }
    
    public void save(Usuario usuario) throws Exception {
        String sql = "insert into usuario (cedula, clave, tipo) values(?,?,?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, usuario.getCedula());
        stm.setString(2, usuario.getClave());
        stm.setString(3, String.valueOf(usuario.getTipo()));
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar usuario");
        }
    }
    
    public Usuario from(ResultSet rs, String alias) {
        try {
            Usuario e = new Usuario();
            e.setCedula(rs.getString(alias + ".cedula"));
            e.setClave(rs.getString(alias + ".clave"));
            e.setTipo(rs.getInt(alias + ".tipo"));            
            return e;
        } catch (SQLException ex) {
            return null;
        }
    } 
}
//////
