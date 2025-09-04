/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.data;

import com.mycompany.proyecto1.logic.Categoria;
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
public class CategoriaDao {
    Database db;

    public CategoriaDao(Database db){
        this.db = db;
    }
    
    public Categoria read(String codigo) throws Exception {
        String sql = "select * from categoria ca where ca.codigo = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        Categoria categoria;
        if (rs.next()) {
            categoria = from(rs, "ca");
            return categoria;
        } else {
            throw new Exception("Categoria no Existe");
        }
    }
    
    public List<Categoria> readAll() throws Exception {
        String sql = "select * from categoria ca";
        PreparedStatement stm = db.prepareStatement(sql);
        ResultSet rs = db.executeQuery(stm);
        
        List<Categoria> categorias = new ArrayList();
        CoberturaDao coberturaDao = new CoberturaDao(db);
        Categoria categoria;
        
        try {
            while(rs.next()){
                categoria = from(rs, "ca");
                categoria.setCobertura(coberturaDao.readCategoriaMatch(categoria.getCod()));
                categorias.add(categoria);
            }
            
            return categorias;
        } catch(Exception ignored) {
            throw new Exception("Categoria no Existe");
        }
    }
    
    public void save(Categoria categoria) throws Exception {
        String sql = "insert into categoria (detalle) values(?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, categoria.getDetalle());
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar categoria");
        }
    }
    
    public Categoria from(ResultSet rs, String alias) {
        try {
            Categoria ca = new Categoria();
            ca.setCod(rs.getString(alias + ".codigo"));
            ca.setDetalle(rs.getString(alias + ".detalle"));       
            return ca;
        } catch (SQLException ex) {
            return null;
        }
    } 
}

//////
