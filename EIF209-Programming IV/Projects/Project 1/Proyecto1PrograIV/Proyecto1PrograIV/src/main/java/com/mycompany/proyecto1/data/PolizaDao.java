/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.data;

import com.mycompany.proyecto1.logic.Cliente;
import com.mycompany.proyecto1.logic.Modelo;
import com.mycompany.proyecto1.logic.Poliza;
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
public class PolizaDao {
    Database db;

    public PolizaDao(Database db){
        this.db = db;
    }
    
    public Poliza read(String codigo) throws Exception {
        String sql = "select * from poliza po "
                + "inner join modelo mo on po.modelo = mo.codigo "
                + "inner join cliente cl on po.cliente = cl.usuario "
                + "inner join categoria ca on po.categoria = ca.codigo "
                + "inner join cobertura co on po.cobertura = co.codigo "
                + "where po.codigo = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        
        ModeloDao modeloDao = new ModeloDao(db);
        ClienteDao clienteDao = new ClienteDao(db);
        CategoriaDao categoriaDao = new CategoriaDao(db);
        CoberturaDao coberturaDao = new CoberturaDao(db);
        Modelo modelo;
        Poliza poliza;
        
        if (rs.next()) {
            poliza = from(rs, "po");
            modelo = modeloDao.from(rs,"mo");
            poliza.setModelo(modeloDao.read(modelo.getCod()));
            poliza.setCliente(clienteDao.from(rs,"cl"));
            poliza.setCategoria(categoriaDao.from(rs,"ca"));
            poliza.setCobertura(coberturaDao.from(rs,"co"));
            return poliza;
        } else {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public List<Poliza> readMatchingCliente(Cliente cliente) throws Exception {
        String sql = "select * from poliza po "
                + "inner join modelo mo on po.modelo = mo.codigo "
                + "inner join cliente cl on po.cliente = cl.usuario "
                + "inner join categoria ca on po.categoria = ca.codigo " 
                + "inner join cobertura co on po.cobertura = co.codigo "
                + "where po.cliente = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cliente.getUser().getCedula());
        ResultSet rs = db.executeQuery(stm);
        
        ModeloDao modeloDao = new ModeloDao(db);
        ClienteDao clienteDao = new ClienteDao(db);
        CategoriaDao categoriaDao = new CategoriaDao(db);
        CoberturaDao coberturaDao = new CoberturaDao(db);
        Poliza poliza;
        Modelo modelo;
        List<Poliza> polizas = new ArrayList();
        
        try {
            while(rs.next()){
                poliza = from(rs, "po");
                modelo = modeloDao.from(rs,"mo");
                poliza.setModelo(modeloDao.read(modelo.getCod()));
                poliza.setCliente(clienteDao.from(rs,"cl"));
                poliza.setCategoria(categoriaDao.from(rs,"ca"));
                poliza.setCobertura(coberturaDao.from(rs,"co"));
                polizas.add(poliza);
            }
                
            return polizas;
        } catch(Exception ignored) {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public void save(Poliza poliza) throws Exception {
        String sql = "insert into poliza (numPlaca, modelo, anio, valor, plazoPago, fechaVigencia, cliente, categoria, cobertura) values(?,?,?,?,?,?,?,?,?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, poliza.getNumPlaca());
        stm.setString(2, poliza.getModelo().getCod());
        stm.setString(3, String.valueOf(poliza.getAnio()));
        stm.setString(4, String.valueOf(poliza.getValor()));
        stm.setString(5, String.valueOf(poliza.getPlazopago()));
        stm.setString(6, poliza.getFechavigencia());
        stm.setString(7, poliza.getCliente().getUser().getCedula());
        stm.setString(8, poliza.getCategoria().getCod());
        stm.setString(9, poliza.getCobertura().getCod());
        
        try{
            db.executeUpdate(stm);
        } catch (Exception ignored){
            throw new Exception("Error al agregar poliza");
        }
    }
    
    public Poliza from(ResultSet rs, String alias) {
        try {
            Poliza po = new Poliza();
            po.setCod(rs.getString(alias + ".codigo"));
            po.setNumPlaca(rs.getString(alias + ".numPlaca"));
            po.setAnio(rs.getInt(alias + ".anio"));
            po.setValor(rs.getInt(alias + ".valor"));
            po.setPlazopago(rs.getInt(alias + ".plazoPago"));
            po.setFechavigencia(rs.getString(alias + ".fechaVigencia"));
            return po;
        } catch (SQLException ex) {
            return null;
        }
    }
}

//////
