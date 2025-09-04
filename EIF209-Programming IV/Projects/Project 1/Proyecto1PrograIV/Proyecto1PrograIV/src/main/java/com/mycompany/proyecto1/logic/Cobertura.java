/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.logic;

import java.util.Objects;

/**
 *
 * @author Nicole
 */
public class Cobertura {
    
    String cod; //autogenerada
    String detalle;
    Categoria categoria;
    int porcentaje;         
    int costoMinimo;
    
    public Cobertura(String cod, String detalle,int costoMinimo,int porcentaje,Categoria cat) {
        this.cod = cod;
        this.detalle = detalle;
        this.categoria=cat;
        this.costoMinimo=costoMinimo;
        this.porcentaje=porcentaje; 
    }

    public Cobertura() {
        this.cod = "";
        this.detalle = "";
        categoria=new Categoria();
        costoMinimo=0;
    }

    public int getPorcentaje() {
        return porcentaje;
    }

    public void setPorcentaje(int porcentaje) {
        this.porcentaje = porcentaje;
    }

    public int getCostoMinimo() {
        return costoMinimo;
    }

    public void setCostoMinimo(int costoMinimo) {
        this.costoMinimo = costoMinimo;
    }

    public Categoria getCategoria() {
        return categoria;
    }

    public void setCategoria(Categoria categoria) {
        this.categoria = categoria;
    }

    public String getCod() {
        return cod;
    }

    public void setCod(String cod) {
        this.cod = cod;
    }

    public String getDetalle() {
        return detalle;
    }

    public void setDetalle(String detalle) {
        this.detalle = detalle;
    }
    
     @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Cobertura other = (Cobertura) obj;
        if (!Objects.equals(this.getCod(), other.getCod())) {
            return false;
        }
        return true;
    }
    
    
}
