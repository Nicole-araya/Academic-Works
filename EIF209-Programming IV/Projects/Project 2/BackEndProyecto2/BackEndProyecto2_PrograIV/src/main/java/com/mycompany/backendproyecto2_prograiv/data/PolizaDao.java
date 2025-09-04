package com.mycompany.backendproyecto2_prograiv.data;

import com.mycompany.backendproyecto2_prograiv.logic.Cliente;
import com.mycompany.backendproyecto2_prograiv.logic.Cobertura;
import com.mycompany.backendproyecto2_prograiv.logic.Modelo;
import com.mycompany.backendproyecto2_prograiv.logic.Poliza;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class PolizaDao {
    Database db;

    public PolizaDao(Database db){
        this.db = db;
    }
    
    public Poliza read(String idPoliza, String idCliente) throws Exception {
        String sql = "select * from poliza po "
                + "inner join modelo mo on po.modelo = mo.codigo "
                + "inner join cliente cl on po.cliente = cl.usuario "
                + "where po.codigo = ? "
                + "and po.cliente = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, idPoliza);
        stm.setString(2, idCliente);
        ResultSet rs = db.executeQuery(stm);
        
        ModeloDao modeloDao = new ModeloDao(db);
        ClienteDao clienteDao = new ClienteDao(db);
        Modelo modelo;
        Poliza poliza;
        
        if (rs.next()) {
            poliza = from(rs, "po");
            modelo = modeloDao.from(rs,"mo");
            poliza.setModelo(modeloDao.read(modelo.getCod()));
            poliza.setCliente(clienteDao.from(rs,"cl"));
            poliza.setCoberturas(getCoberturasMatchingPoliza(poliza.getCod()));
            return poliza;
        } else {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public List<Poliza> findByNombreMatchingClienteCedula(String cedula, String placa) throws Exception {
        String sql = "select * from poliza po "
                + "inner join modelo mo on po.modelo = mo.codigo "
                + "inner join cliente cl on po.cliente = cl.usuario "
                + "where po.cliente = ? "
                + "and po.numPlaca like concat('%', ?,'%')";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cedula);
        stm.setString(2, placa);
        ResultSet rs = db.executeQuery(stm);
        
        ModeloDao modeloDao = new ModeloDao(db);
        ClienteDao clienteDao = new ClienteDao(db);
        Poliza poliza;
        Modelo modelo;
        List<Poliza> polizas = new ArrayList();
        
        try {
            while(rs.next()){
                poliza = from(rs, "po");
                modelo = modeloDao.from(rs,"mo");
                poliza.setModelo(modeloDao.read(modelo.getCod()));
                poliza.setCliente(clienteDao.from(rs,"cl"));
                polizas.add(poliza);
            }
                
            return polizas;
        } catch(Exception ignored) {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public Poliza getPolizaById(String idPoliza) throws Exception {
        String sql = "select * from poliza po "
                + "inner join modelo mo on po.modelo = mo.codigo "
                + "inner join cliente cl on po.cliente = cl.usuario "
                + "where po.codigo = ? ";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, idPoliza);
        ResultSet rs = db.executeQuery(stm);
        
        ModeloDao modeloDao = new ModeloDao(db);
        ClienteDao clienteDao = new ClienteDao(db);
        Modelo modelo;
        Poliza poliza;
        
        if (rs.next()) {
            poliza = from(rs, "po");
            modelo = modeloDao.from(rs,"mo");
            poliza.setModelo(modeloDao.read(modelo.getCod()));
            poliza.setCliente(clienteDao.from(rs,"cl"));
            poliza.setCoberturas(getCoberturasMatchingPoliza(poliza.getCod()));
            return poliza;
        } else {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public List<Poliza> getPolizasByClienteId(String id) throws Exception { // error
        String sql = "select * from poliza po "
                + "inner join modelo mo on po.modelo = mo.codigo "
                + "inner join cliente cl on po.cliente = cl.usuario "
                + "where po.cliente = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, id);
        ResultSet rs = db.executeQuery(stm);
        
        ModeloDao modeloDao = new ModeloDao(db);
        ClienteDao clienteDao = new ClienteDao(db);
        Poliza poliza;
        Modelo modelo;
        List<Poliza> polizas = new ArrayList();
        
        try {
            while(rs.next()){
                poliza = from(rs, "po");
                modelo = modeloDao.from(rs,"mo");
                poliza.setModelo(modeloDao.read(modelo.getCod()));
                poliza.setCliente(clienteDao.from(rs,"cl"));
                poliza.setCoberturas(getCoberturasMatchingPoliza(poliza.getCod()));
                polizas.add(poliza);
            }
                
            return polizas;
        } catch(Exception ignored) {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public List<Poliza> readMatchingCliente(Cliente cliente) throws Exception {
        String sql = "select * from poliza po "
                + "inner join modelo mo on po.modelo = mo.codigo "
                + "inner join cliente cl on po.cliente = cl.usuario "
                + "where po.cliente = ?";
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, cliente.getUser().getCedula());
        ResultSet rs = db.executeQuery(stm);
        
        ModeloDao modeloDao = new ModeloDao(db);
        ClienteDao clienteDao = new ClienteDao(db);
        Poliza poliza;
        Modelo modelo;
        List<Poliza> polizas = new ArrayList();
        
        try {
            while(rs.next()){
                poliza = from(rs, "po");
                modelo = modeloDao.from(rs,"mo");
                poliza.setModelo(modeloDao.read(modelo.getCod()));
                poliza.setCliente(clienteDao.from(rs,"cl"));
                poliza.setCoberturas(getCoberturasMatchingPoliza(poliza.getCod()));
                polizas.add(poliza);
            }
                
            return polizas;
        } catch(Exception ignored) {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public List<Cobertura> getCoberturasMatchingPoliza(String codigo) throws Exception{
        String sql = "select * from poliza_cobertura pc "
                + "inner join poliza po on pc.idPoliza = po.codigo "
                + "inner join cobertura co on pc.idCobertura = co.codigo "
                + "where pc.idPoliza = ?";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, codigo);
        ResultSet rs = db.executeQuery(stm);
        
        CoberturaDao coberturaDao = new CoberturaDao(db);
        Cobertura cobertura;
        List<Cobertura> coberturas = new ArrayList();
        
        try {
            while(rs.next()){
                cobertura = coberturaDao.from(rs, "co");
                cobertura = coberturaDao.read(cobertura.getCod());
                coberturas.add(cobertura);
            }
                
            return coberturas;
        } catch(Exception ignored) {
            throw new Exception("Poliza no Existe");
        }
    }
    
    public String save(Poliza poliza) throws Exception {
    String sql = "INSERT INTO poliza (numPlaca, modelo, anio, valor, plazoPago, fechaVigencia, cliente) VALUES (?,?,?,?,?,?,?)";

    try (PreparedStatement stm = db.prepareStatement(sql)) {
        stm.setString(1, poliza.getNumPlaca());
        stm.setString(2, poliza.getModelo().getCod());
        stm.setString(3, String.valueOf(poliza.getAnio()));
        stm.setString(4, String.valueOf(poliza.getValor()));
        stm.setString(5, String.valueOf(poliza.getPlazopago()));
        stm.setString(6, poliza.getFechavigencia());
        stm.setString(7, poliza.getCliente().getUser().getCedula());

        int affectedRows = stm.executeUpdate();

        if (affectedRows == 0) {
            throw new Exception("Error al agregar póliza");
        }
    } catch (Exception e) {
        throw new Exception("Error al agregar póliza", e);
    }
    
    // Consulta adicional para obtener el código de la última póliza insertada
    String codigoPoliza = null;
    String consultaCodigo = "SELECT MAX(codigo) FROM poliza";

    try (PreparedStatement stmCodigo = db.prepareStatement(consultaCodigo);
         ResultSet rs = stmCodigo.executeQuery()) {
        if (rs.next()) {
            codigoPoliza = rs.getString(1);
        }
    } catch (Exception e) {
        throw new Exception("Error al obtener el código de la póliza", e);
    }

    return codigoPoliza;
}


    
    public void saveCobertura(String idPoliza, String idCobertura) throws Exception {
        String sql = "insert into poliza_cobertura (idPoliza, idCobertura) values(?,?)";
        
        PreparedStatement stm = db.prepareStatement(sql);
        stm.setString(1, idPoliza);
        stm.setString(2, idCobertura);
        
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
