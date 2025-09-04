/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.cliente.polizas;

import com.mycompany.proyecto1.logic.Poliza;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Model {
    
    List<Poliza> polizas;
    Poliza seleccionado;

    public Model() {
        this.reset();
    }

    public void reset(){ 
        List<Poliza> rows = new ArrayList<>();        
        seleccionado=new Poliza();  
        this.setPolizas(rows);
    }
    
    public void setPolizas(List<Poliza> cuentas){
        this.polizas =cuentas;    
    }

     public List<Poliza> getPolizas() {
        return polizas;
    }

    public Poliza getSeleccionado() {
        return seleccionado;
    }

    public void setSeleccionado(Poliza seleccionado) {
        this.seleccionado = seleccionado;
    }
}
