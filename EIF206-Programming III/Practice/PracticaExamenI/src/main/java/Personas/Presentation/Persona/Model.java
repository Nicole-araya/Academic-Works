package Personas.Presentation.Persona;

import Personas.Logic.Persona;

import java.util.ArrayList;
import java.util.List;
import java.util.Observer;

public class Model extends java.util.Observable{

    Persona current;
    int modo;

    public Model(){}

    public int getModo() {
        return modo;
    }

    public void setModo(int modo) {
        this.modo = modo;
    }

    public Persona getCurrent() {
        return current;
    }

    public void setCurrent(Persona current) {
        this.current = current;
    }

    public void commit(){
        setChanged();
        notifyObservers(null);
    }

    @Override
    public synchronized void addObserver(Observer o) {
        super.addObserver(o);
        this.commit();
    }
}
