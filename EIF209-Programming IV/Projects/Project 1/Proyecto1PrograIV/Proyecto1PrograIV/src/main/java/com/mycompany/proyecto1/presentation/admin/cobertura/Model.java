/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.cobertura;

import com.mycompany.proyecto1.logic.Categoria;
import com.mycompany.proyecto1.logic.Cobertura;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Model {
    
    List<Categoria> categorias;
    Cobertura seleccionado;
    
    public Model() {
        this.reset();
    }

    public void reset(){ 
        List<Categoria> rows = new ArrayList<>();         
        seleccionado=new Cobertura();
        this.setCategorias(rows);
    }

    public List<Categoria> getCategorias() {
        return categorias;
    }

    public void setCategorias(List<Categoria> categorias) {
        this.categorias = categorias;
    }

    public Cobertura getSeleccionado() {
        return seleccionado;
    }

    public void setSeleccionado(Cobertura seleccionado) {
        this.seleccionado = seleccionado;
    }
    
    
}
