/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.clientes;


import com.mycompany.proyecto1.logic.Admin;
import com.mycompany.proyecto1.logic.Cliente;
import com.mycompany.proyecto1.logic.Poliza;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Model {
    
    List<Cliente> clientes;
    List<Poliza> polizas;  //ESTO YA NO
    Cliente seleccionado;
    Admin admin;

    public Model() {
        this.reset();
    }

    public void reset(){ 
        List<Cliente> rows = new ArrayList<>(); 
        List<Poliza> rowsP = new ArrayList<>();
        seleccionado=null;  
        admin=new Admin();
        this.setClientes(rows);
        this.setPolizas(rowsP);
    }

    public Admin getAdmin() {
        return admin;
    }

    public void setAdmin(Admin admin) {
        this.admin = admin;
    }

    
    public List<Poliza> getPolizas() {
        return polizas;
    }

    public void setPolizas(List<Poliza> polizas) {
        this.polizas = polizas;
    }

    public List<Cliente> getClientes() {
        return clientes;
    }

    public void setClientes(List<Cliente> clientes) {
        this.clientes = clientes;
    }


    public Cliente getSeleccionado() {
        return seleccionado;
    }

    public void setSeleccionado(Cliente seleccionado) {
        this.seleccionado = seleccionado;
    }
    
    
}
