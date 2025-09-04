/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.login;

import com.mycompany.proyecto1.logic.Cliente;
import com.mycompany.proyecto1.logic.Usuario;

/**
 *
 * @author Nicole
 */
public class Model {
    Usuario current;
    Cliente cliente;
    
    public Model() {
        this.reset();
    }
    
    public void reset(){
        setCurrent(new Usuario());  
        setCliente(new Cliente());
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }
    
    public Usuario getCurrent() {
        return current;
    }

    public void setCurrent(Usuario current) {
        this.current = current;
    }
   
}