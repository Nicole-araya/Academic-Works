/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.proyecto1.presentation.admin.blank;
import com.mycompany.proyecto1.logic.Admin;
/**
 *
 * @author INTEL
 */
public class Model {

    Admin current;

    public Model() {
        this.reset();
    }

    public void reset() {
        current = null;
    }

    public Admin getCurrent() {
        return current;
    }

    public void setCurrent(Admin current) {
        this.current = current;
    }
}
