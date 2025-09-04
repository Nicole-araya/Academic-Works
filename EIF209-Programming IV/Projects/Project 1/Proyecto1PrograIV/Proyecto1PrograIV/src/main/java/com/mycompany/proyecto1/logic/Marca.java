/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.logic;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Nicole
 */
public class Marca {
    
    String cod;
    String marca;
    List<Modelo> modelos;

    public Marca(String cod, String marca) {
        this.cod = cod;
        this.marca = marca;
        this.modelos=new ArrayList<>();
    }

    public Marca() {
        this.cod = "";
        this.marca = "";
        this.modelos=new ArrayList<>();
    }

    public String getCod() {
        return cod;
    }

    public void setCod(String cod) {
        this.cod = cod;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public List<Modelo> getModelos() {
        return modelos;
    }

    public void setModelos(List<Modelo> modelos) {
        this.modelos = modelos;
    }
    
 
}


