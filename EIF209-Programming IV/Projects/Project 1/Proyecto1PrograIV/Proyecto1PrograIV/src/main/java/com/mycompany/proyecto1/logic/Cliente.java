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
public class Cliente {
    
    Usuario usuario;
    String nombre;
    String telefono;
    String correo;
    String medioPago;
    List<Poliza> polizas;

    public Cliente(Usuario user, String nombre, String telefono, String correo, String medioPago) {
        this.usuario = user;
        this.nombre = nombre;
        this.telefono = telefono;
        this.correo = correo;
        this.medioPago = medioPago;
        this.polizas = new ArrayList<>();
    }

    public Cliente() {
        this.usuario = new Usuario();
        this.nombre = "";
        this.telefono = "";
        this.correo = "";
        this.medioPago = "";
        this.polizas = new ArrayList<>();
    }

    public Usuario getUser() {
        return usuario;
    }

    public void setUser(Usuario user) {
        this.usuario = user;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public String getMedioPago() {
        return medioPago;
    }

    public void setMedioPago(String medioPago) {
        this.medioPago = medioPago;
    }

    public List<Poliza> getPolizas() {
        return polizas;
    }

    public void setPolizas(List<Poliza> polizas) {
        this.polizas = polizas;
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
        final Cliente other = (Cliente) obj;
        if (!Objects.equals(this.usuario.getCedula(), other.usuario.getCedula())) {
            return false;
        }
        return true;
    }
  
}
