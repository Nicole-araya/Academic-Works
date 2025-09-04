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
public class Poliza {
    
    String cod;
    String numPlaca;
    Modelo modelo;
    int anio;
    int valor;
    int plazopago; //clasificar por # 
    String fechavigencia;
    Cliente cliente;
    Categoria categoria;
    Cobertura cobertura;
    int costo;

    public Poliza(String cod, String numPlaca, Modelo modelo, int anio, int valor, int plazopago, String fechavigencia, Cliente cliente,Categoria categoria,Cobertura cober) {
        this.cod = cod;
        this.numPlaca = numPlaca;
        this.modelo = modelo;
        this.anio = anio;
        this.valor = valor;
        this.plazopago = plazopago;
        this.fechavigencia = fechavigencia;
        this.cliente = cliente;
        this.categoria=categoria;
        this.cobertura=cober;
        this.costo=0;
    }

    public Poliza() {
        this.cod = "";
        this.numPlaca = "";
        this.modelo = new Modelo();
        this.anio = 0;
        this.valor = 0;
        this.plazopago = 0;
        this.fechavigencia = "";
        this.costo=0;
        this.cliente = new Cliente();
        this.categoria=new Categoria();
        this.cobertura=new Cobertura();
    }

    int calcularCosto(){
    int minimo= cobertura.getCostoMinimo();
    int porcentaje= cobertura.getPorcentaje();
    int resultado= (valor*porcentaje)/100;
    
    if(resultado<minimo){
        return minimo;
    }        
        return resultado;
    }
            
    public int getCosto() {
        
        costo=calcularCosto();
        return costo;
                
    }

    public void setCosto(int costo) {
        this.costo = costo;
    }

    public Modelo getModelo() {
        return modelo;
    }

    public void setModelo(Modelo modelo) {
        this.modelo = modelo;
    }

    public String getCod() {
        return cod;
    }

    public void setCod(String cod) {
        this.cod = cod;
    }

    public String getNumPlaca() {
        return numPlaca;
    }

    public void setNumPlaca(String numPlaca) {
        this.numPlaca = numPlaca;
    }

    public int getAnio() {
        return anio;
    }

    public void setAnio(int anio) {
        this.anio = anio;
    }

    public int getValor() {
        return valor;
    }

    public void setValor(int valor) {
        this.valor = valor;
    }

    public int getPlazopago() {
        return plazopago;
    }

    public void setPlazopago(int plazopago) {
        this.plazopago = plazopago;
    }

    public String getFechavigencia() {
        return fechavigencia;
    }

    public void setFechavigencia(String fechavigencia) {
        this.fechavigencia = fechavigencia;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public Categoria getCategoria() {
        return categoria;
    }

    public void setCategoria(Categoria categoria) {
        this.categoria = categoria;
    }

    public Cobertura getCobertura() {
        return cobertura;
    }

    public void setCobertura(Cobertura cobertura) {
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
        final Poliza other = (Poliza) obj;
        if (!Objects.equals(this.cod, other.cod)) {
            return false;
        }
        return true;
    }
}
