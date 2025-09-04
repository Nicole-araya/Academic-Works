/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.backendproyecto2_prograiv.logic;

/**
 *
 * @author Nicole
 */
public class Admin {
    Usuario usuario;
    String nombre;

    public Admin(Usuario usuario, String nombre) {
        this.usuario = usuario;
        this.nombre = nombre;
    }

    public Admin() {
        this.usuario = new Usuario();
        this.nombre = "";
    }

    
    
    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
    
    
    
}
