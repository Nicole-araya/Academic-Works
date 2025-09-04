/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.cliente.poliza;

import com.mycompany.proyecto1.logic.Categoria;
import com.mycompany.proyecto1.logic.Marca;
import com.mycompany.proyecto1.logic.Poliza;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Model {
    
    Poliza current;
    List<Marca> marcas;
    List<Categoria> categorias;

     public Model() {
        this.reset();
    }

    public void reset(){ 
        List<Marca> rows = new ArrayList<>(); 
        List<Categoria> rowsC = new ArrayList<>();       
        current=new Poliza();
        this.setMarcas(rows);
        this.setCategorias(rowsC);
    }

    public List<Marca> getMarcas() {
        return marcas;
    }

    public void setMarcas(List<Marca> marcas) {
        this.marcas = marcas;
    }

    public List<Categoria> getCategorias() {
        return categorias;
    }

    public void setCategorias(List<Categoria> categorias) {
        this.categorias = categorias;
    }
   

    public Poliza getCurrent() {
        return current;
    }

    public void setCurrent(Poliza current) {
        this.current = current;
    }

}
