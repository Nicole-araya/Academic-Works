/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.logic;

/**
 *
 * @author Nicole
 */
public class Modelo {
    
    String cod;
    String modelo;
    Marca marca;
    
    public Modelo(String cod,String modelo,Marca marca) {
        this.cod=cod;
        this.modelo = modelo;
        this.marca=marca;
    }

    public Modelo() {
        this.cod="";
         this.modelo = "";
          this.marca=new Marca();
    }

    public String getCod() {
        return cod;
    }

    public void setCod(String cod) {
        this.cod = cod;
    }

    public Marca getMarca() {
        return marca;
    }

    public void setMarca(Marca marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }
    
    
}
