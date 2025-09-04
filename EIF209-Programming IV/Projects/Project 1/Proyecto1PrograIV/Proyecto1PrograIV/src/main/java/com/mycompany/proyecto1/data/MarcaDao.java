/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.data;

import com.mycompany.proyecto1.logic.Marca;
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
public class MarcaDao {
    Database db;

    public MarcaDao(Database db){
        this.db = db;
    }
    
    public Marca read(String codigo) throws Exception {
        String sql = "select * from marca ma where ma.codigo = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        Marca marca;
        if (rs.next()) {
            marca = from(rs, "ma");
            return marca;
        } else {
            throw new Exception("Marca no Existe");
        }
    }
    
    public List<Marca> readAll() throws Exception {
        String sql = "select * from marca ma";
        PreparedStatement stm = db.prepareStatement(sql);
        ResultSet rs = db.executeQuery(stm);
        
        List<Marca> marcas = new ArrayList();
        ModeloDao modeloDao = new ModeloDao(db);
        Marca marca;
        
        try {
            while(rs.next()){
                marca = from(rs, "ma");
                marca.setModelos(modeloDao.readMarcaMatch(marca.getCod()));
                marcas.add(marca);
            }
            
            return marcas;
        } catch(Exception ignored) {
            throw new Exception("Marca no Existe");
        }
    }
    
    public void save(Marca marca) throws Exception {
        String sql = "insert into marca (marca) values(?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, marca.getMarca());
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar marca");
        }
    }
    
    public Marca from(ResultSet rs, String alias) {
        try {
            Marca m = new Marca();
            m.setCod(rs.getString(alias + ".codigo"));
            m.setMarca(rs.getString(alias + ".marca"));       
            return m;
        } catch (SQLException ex) {
            return null;
        }
    } 
}

//////
