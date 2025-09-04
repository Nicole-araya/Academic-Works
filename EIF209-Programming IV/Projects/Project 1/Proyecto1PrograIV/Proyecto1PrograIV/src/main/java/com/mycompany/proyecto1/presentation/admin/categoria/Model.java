/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.categoria;

import com.mycompany.proyecto1.logic.Categoria;

/**
 *
 * @author Nicole
 */
public class Model {
    
    Categoria current;

    public Model() {
        current=new Categoria();
    }

    public Categoria getCurrent() {
        return current;
    }

    public void setCurrent(Categoria current) {
        this.current = current;
    }
    
    
}
