package Personas.Presentation.Persona;

import Personas.Application;
import Personas.Logic.Persona;
import Personas.Logic.Service;

import javax.swing.*;
import java.awt.*;

public class Controller {

    View view;
    Model model;
    JDialog dialog;

    public Controller(View view, Model model){
        model.setCurrent(new Persona());
        this.view = view;
        this.model = model;
        view.setController(this);
        view.setModel(model);
    }

    public void preagregar(){
        model.setModo(Application.MODO_AGREGAR);
        model.setCurrent(new Persona());
        model.commit();
        this.show();
    }
    public void show(){
        dialog = new JDialog(Application.window,"Persona", true);
        dialog.setSize(1050,750);
        dialog.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        dialog.setContentPane(view.getPanel());
        Point location = Application.window.getLocation();
        dialog.setLocation( location.x+400,location.y+100);
        dialog.setVisible(true);
    }

    public void hide(){
        dialog.dispose();
    }

    /*public void show1(){
        Application.window.setContentPane(view.getPanel());
        Application.window.revalidate();
    }
    public void hide1(){
        Application.mainController.show();
    }*/

    public void guardar(Persona p) throws Exception {
        switch (model.getModo()) {
            case Application.MODO_AGREGAR:
                Service.instance().agregarPersona(p);
                model.setCurrent(new Persona());
                break;
            case Application.MODO_EDITAR:
                Service.instance().personaUpdate(p);
                model.setCurrent(p);
                break;
        }
        Application.personasController.buscar("");
        model.commit();
    }

    public void editar(Persona p){
        model.setModo(Application.MODO_EDITAR);
        model.setCurrent(p);
        model.commit();
        this.show();
    }
}
