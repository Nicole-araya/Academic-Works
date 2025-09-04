/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.cliente.datos;

import com.mycompany.proyecto1.logic.Cliente;
import com.mycompany.proyecto1.logic.Usuario;

/**
 *
 * @author Nicole
 */
public class Model {
     Cliente current;

    public Model() {
        this.current = new Cliente();
    }

    
    public Cliente getCurrent() {
        return current;
    }

    public void setCurrent(Cliente current) {
        this.current = current;
    }
}
