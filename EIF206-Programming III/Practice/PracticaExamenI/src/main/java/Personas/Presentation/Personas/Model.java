package Personas.Presentation.Personas;

import Personas.Logic.Persona;

import java.util.ArrayList;
import java.util.List;
import java.util.Observer;

public class Model extends java.util.Observable {
    List<Persona> personas;

    public Model(){this.setPersonas(new ArrayList<Persona>());}

    public List<Persona> getPersonas() {
        return personas;
    }

    public void setPersonas(List<Persona> personas) {
        this.personas = personas;
    }
    public void commit(){
        setChanged();
        notifyObservers(null);
    }
    @Override
    public synchronized void addObserver(Observer o) {
        super.addObserver(o);
        commit();
    }
}
