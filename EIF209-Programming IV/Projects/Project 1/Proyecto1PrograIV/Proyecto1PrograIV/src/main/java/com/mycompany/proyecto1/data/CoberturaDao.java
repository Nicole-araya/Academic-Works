/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.data;

import com.mycompany.proyecto1.logic.Cobertura;
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
public class CoberturaDao {
    Database db;

    public CoberturaDao(Database db){
        this.db = db;
    }
    
    public Cobertura read(String codigo) throws Exception {
        String sql = "select * from cobertura co inner join categoria ca on co.categoria = ca.codigo where co.codigo = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        
        CategoriaDao categoriaDao = new CategoriaDao(db);
        Cobertura cobertura;
        if (rs.next()) {
            cobertura = from(rs, "co");
            cobertura.setCategoria(categoriaDao.from(rs, "ca"));
        
            return cobertura;
        } else {
            throw new Exception("Cobertura no Existe");
        }
    }
    
    public List<Cobertura> readAll() throws Exception {
        String sql = "select * from cobertura co inner join categoria ca on co.categoria = ca.codigo";
        PreparedStatement stm = db.prepareStatement(sql);
        ResultSet rs = db.executeQuery(stm);
        
        CategoriaDao categoriaDao = new CategoriaDao(db);
        List<Cobertura> coberturas = new ArrayList();
        Cobertura cobertura;
        try {
            while(rs.next()){
                cobertura = from(rs, "co");
                cobertura.setCategoria(categoriaDao.from(rs, "ca"));
                coberturas.add(cobertura);
            }

            return coberturas;
        } catch(Exception ignored) {
            throw new Exception("Cobertura no Existe");
        }
    }
    
    public List<Cobertura> readCategoriaMatch(String codigo) throws Exception {
        String sql = "select * from cobertura co inner join categoria ca on co.categoria = ca.codigo where co.categoria=?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        
        CategoriaDao categoriaDao = new CategoriaDao(db);
        List<Cobertura> coberturas = new ArrayList();
        Cobertura cobertura;
        try {
            while(rs.next()){
                cobertura = from(rs, "co");
                cobertura.setCategoria(categoriaDao.from(rs, "ca"));
                coberturas.add(cobertura);
            }

            return coberturas;
        } catch(Exception ignored) {
            throw new Exception("Cobertura no Existe");
        }
    }
    
    public void save(Cobertura cobertura) throws Exception {
        String sql = "insert into cobertura (detalle, categoria, porcentaje, costoMinimo) values(?,?,?,?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cobertura.getDetalle());
        stm.setString(2, cobertura.getCategoria().getCod());
        stm.setString(3, String.valueOf(cobertura.getPorcentaje()));
        stm.setString(4, String.valueOf(cobertura.getCostoMinimo()));
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar cobertura");
        }
    }
    
    public Cobertura from(ResultSet rs, String alias) {
        try {
            Cobertura co = new Cobertura();
            co.setCod(rs.getString(alias + ".codigo"));
            co.setDetalle(rs.getString(alias + ".detalle"));       
            co.setPorcentaje(Integer.parseInt(rs.getString(alias + ".porcentaje")));       
            co.setCostoMinimo(Integer.parseInt(rs.getString(alias + ".costoMinimo")));       
            return co;
        } catch (SQLException ex) {
            return null;
        }
    } 
}

//////
