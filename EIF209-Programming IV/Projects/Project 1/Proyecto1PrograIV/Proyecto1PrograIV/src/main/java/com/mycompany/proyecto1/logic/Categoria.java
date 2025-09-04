/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.logic;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 *
 * @author Nicole
 */
public class Categoria {
    
    String cod; //autogenerada
    String detalle;
    List<Cobertura> cobertura;

    public Categoria(String cod, String detalle) {
        this.cod = cod;
        this.detalle = detalle;
        this.cobertura = new ArrayList();
    }

    public Categoria() {
        this.cod = "";
        this.detalle = "";
        this.cobertura = new ArrayList();
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

    public List<Cobertura> getCobertura() {
        return cobertura;
    }

    public void setCobertura(List<Cobertura> cobertura) {
        this.cobertura = cobertura;
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
        final Categoria other = (Categoria) obj;
        if (!Objects.equals(this.getCod(), other.getCod())) {
            return false;
        }
        return true;
    }
    
}
