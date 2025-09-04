/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.backendproyecto2_prograiv.data;

import com.mycompany.backendproyecto2_prograiv.logic.Cobertura;
import com.mycompany.backendproyecto2_prograiv.logic.Modelo;
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
public class ModeloDao {
    Database db;

    public ModeloDao(Database db){
        this.db = db;
    }
    
    public Modelo read(String codigo) throws Exception {
        String sql = "select * from modelo mo inner join marca ma on mo.marca = ma.codigo where mo.codigo = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        
        MarcaDao marcaDao = new MarcaDao(db);
        Modelo modelo;
        if (rs.next()) {
            modelo = from(rs, "mo");
            modelo.setMarca(marcaDao.from(rs,"ma"));
        
            return modelo;
        } else {
            throw new Exception("Modelo no existe");
        }
    }
    
    public List<Modelo> findByNombreMarca(String nombre) throws Exception {
        String sql = "select * from modelo mo inner join marca ma on mo.marca = ma.codigo where ma.marca like concat('%', ?, '%')";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, nombre);
        ResultSet rs = db.executeQuery(stm);
        
        MarcaDao marcaDao = new MarcaDao(db);
        List<Modelo> modelos = new ArrayList();
        Modelo modelo;
        
        try {
            while(rs.next()){
                modelo = from(rs, "mo");
                modelo.setMarca(marcaDao.from(rs, "ma"));
                modelos.add(modelo);
            }

            return modelos;
        } catch(Exception ignored) {
            throw new Exception("Modelo no existe");
        }
    }
    
    public String readLastCodigo() throws Exception {
        String sql = "select * from modelo mo";
        PreparedStatement stm = db.prepareStatement(sql);
        ResultSet rs = db.executeQuery(stm);
        
        String codigo = "";
        Modelo modelo = new Modelo();
        
        try {
            while(rs.next()){
                modelo = from(rs, "mo");
            }
            codigo = modelo.getCod();

            return codigo;
        } catch(Exception ignored) {
            throw new Exception("Modelo no Existe");
        }
    }
    
    
    public List<Modelo> readMarcaMatch(String codigo) throws Exception {
        String sql = "select * from modelo mo inner join marca ma on mo.marca = ma.codigo where mo.marca=?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        
        MarcaDao marcaDao = new MarcaDao(db);
        List<Modelo> modelos = new ArrayList();
        Modelo modelo;
        try {
            while(rs.next()){
                modelo = from(rs, "mo");
                modelo.setMarca(marcaDao.from(rs, "ma"));
                modelos.add(modelo);
            }

            return modelos;
        } catch(Exception ignored) {
            throw new Exception("Modelo no Existe");
        }
    }
    
    public void save(Modelo modelo) throws Exception {
        String sql = "insert into modelo (modelo, marca) values(?,?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, modelo.getModelo());
        stm.setString(2, modelo.getMarca().getCod());
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar modelo");
        }
    }
    
    public Modelo from(ResultSet rs, String alias) {
        try {
            Modelo mo = new Modelo();
            mo.setCod(rs.getString(alias + ".codigo"));
            mo.setModelo(rs.getString(alias + ".modelo"));
            return mo;
        } catch (SQLException ex) {
            return null;
        }
    } 
}

//////
