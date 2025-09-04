/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.modelo;

import com.mycompany.proyecto1.logic.Marca;
import com.mycompany.proyecto1.logic.Modelo;
import com.mycompany.proyecto1.logic.Poliza;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Model {
    List<Marca> marcas;
    Modelo seleccionado;

    
     public Model() {
        this.reset();
    }

    public void reset(){ 
        List<Marca> rows = new ArrayList<>();         
        seleccionado=new Modelo();
        this.setMarcas(rows);
    }
    
    
    public List<Marca> getMarcas() {
        return marcas;
    }

    public void setMarcas(List<Marca> marcas) {
        this.marcas = marcas;
    }

    public Modelo getSeleccionado() {
        return seleccionado;
    }

    public void setSeleccionado(Modelo seleccionado) {
        this.seleccionado = seleccionado;
    }

}
