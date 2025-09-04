package Personas.Presentation.main;

import javax.swing.*;
import java.util.Observable;
import java.util.Observer;

public class View implements Observer {

    private JTabbedPane tabbedPane;

    Controller controller;
    Model model;

    public JTabbedPane getPanel() {
        return tabbedPane;
    }

    public void setController(Controller controller) {
        this.controller = controller;
    }

    public void setModel(Model model) {
        this.model = model;
        model.addObserver(this);
    }

    @Override
    public void update(Observable o, Object arg) {

    }
}
