/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.marca_modelo;

import com.mycompany.proyecto1.logic.Marca;
import com.mycompany.proyecto1.logic.Modelo;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Model {
    
    List<Marca> marcas;
    List<Modelo> modelos; // NO necesario ahora
    Modelo seleccionado;
    
    public Model() {
        this.reset();
    }

    public void reset(){ 
        List<Marca> rows = new ArrayList<>();  
        List<Modelo> rowsM = new ArrayList<>(); 
        seleccionado=new Modelo();  
       setMarcas(rows);
       setModelos(rowsM);
    }

    public List<Marca> getMarcas() {
        return marcas;
    }

    public void setMarcas(List<Marca> marcas) {
        this.marcas = marcas;
    }

    public List<Modelo> getModelos() {
        return modelos;
    }

    public void setModelos(List<Modelo> modelos) {
        this.modelos = modelos;
    }

    public Modelo getSeleccionado() {
        return seleccionado;
    }

    public void setSeleccionado(Modelo seleccionado) {
        this.seleccionado = seleccionado;
    } 
}
