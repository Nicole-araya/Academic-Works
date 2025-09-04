/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.categ_cober;

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
    List<Cobertura> coberturas;  //NO necesario ya
    Cobertura seleccionado;
    
    
      public Model() {
        this.reset();
    }

    public void reset(){ 
        List<Categoria> rows = new ArrayList<>();  
        List<Cobertura> rowsM = new ArrayList<>(); 
        seleccionado=new Cobertura();  
       setCategorias(rows);
       setCoberturas(rowsM);
    } 

    public List<Categoria> getCategorias() {
        return categorias;
    }

    public void setCategorias(List<Categoria> categorias) {
        this.categorias = categorias;
    }

    public List<Cobertura> getCoberturas() {
        return coberturas;
    }

    public void setCoberturas(List<Cobertura> cobertura) {
        this.coberturas = cobertura;
    }

    public Cobertura getSeleccionado() {
        return seleccionado;
    }

    public void setSeleccionado(Cobertura seleccionado) {
        this.seleccionado = seleccionado;
    }
    
    
}
