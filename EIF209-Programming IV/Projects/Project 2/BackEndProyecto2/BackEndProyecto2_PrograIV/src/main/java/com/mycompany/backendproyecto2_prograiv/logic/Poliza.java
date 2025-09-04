package com.mycompany.backendproyecto2_prograiv.logic;

import java.util.ArrayList;
import java.util.List;

public class Poliza {
    
    String cod;
    String numPlaca;
    Modelo modelo;
    int anio;
    int valor;
    int plazopago;
    String fechavigencia;
    Cliente cliente;
    List<Cobertura> coberturas;
    int costo;

    public Poliza(String cod, String numPlaca, Modelo modelo, int anio, int valor, int plazopago, String fechavigencia, Cliente cliente, List<Cobertura> coberturas) {
        this.cod = cod;
        this.numPlaca = numPlaca;
        this.modelo = modelo;
        this.anio = anio;
        this.valor = valor;
        this.plazopago = plazopago;
        this.fechavigencia = fechavigencia;
        this.coberturas = coberturas;
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
        this.coberturas = new ArrayList();
    }
    
    int calcularCosto(){
        int minimo;
        int porcentaje;
        int resultado;
        int total=0;
        
        for(Cobertura c : coberturas){    
            minimo = c.getCostoMinimo();
            porcentaje = c.getPorcentaje();
            resultado = (valor*porcentaje)/100;

            if(resultado<minimo){
                resultado = minimo;
            } 

            total += resultado;
        }

        return total;
    }
    
            
    public int getCosto() {
        
        costo = calcularCosto();
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

    public List<Cobertura> getCoberturas() {
        return coberturas;
    }

    public void setCoberturas(List<Cobertura> coberturas) {
        this.coberturas = coberturas;
    }
}
