package Personas.Presentation.Persona;

import Personas.Application;
import Personas.Logic.Persona;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Observable;
import java.util.Observer;

public class View implements Observer {
    private JPanel panel;
    private JTextField idField;
    private JTextField nombreField;
    private JCheckBox femeninoCheckBox;
    private JCheckBox masculinoCheckBox;
    private JComboBox estadocomboBox;
    private JLabel estadoLable;
    private JLabel sexoLabel;
    private JLabel idLabel;
    private JLabel nombreLabel;
    private JLabel edadLabel;
    private JTextField edadField;
    private JButton guardarButton;
    private JButton cancelarButton;

    Controller controller;
    Model model;

    public JPanel getPanel() {
        return panel;
    }

    public Controller getController() {
        return controller;
    }

    public void setController(Controller controller) {
        this.controller = controller;
    }

    public Model getModel() {
        return model;
    }

    public void setModel(Model model) {
        this.model = model;
        model.addObserver(this);
    }

    public View(){

        guardarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(validate()){
                    Persona p=take();
                    try {
                        controller.guardar(p);
                    } catch (Exception ex) {
                        JOptionPane.showMessageDialog(panel,ex.getMessage());
                    }
                }
            }
        });
        cancelarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.hide();
            }
        });
    }

    @Override
    public void update(Observable o, Object arg) {
        Persona current=model.getCurrent();
        this.idField.setEnabled(model.getModo()==Application.MODO_AGREGAR);
        this.idField.setText(current.getId());
        nombreField.setText(current.getNombre());
        if(model.getModo()==Application.MODO_EDITAR){
           edadField.setText(String.valueOf(current.getEdad()));
           if(current.getEstCivil()=="Solterx") estadocomboBox.setSelectedIndex(1);
           if(current.getEstCivil()=="Casadx") estadocomboBox.setSelectedIndex(2);
           if(current.getEstCivil()=="Divorciadx") estadocomboBox.setSelectedIndex(3);
           if(current.getEstCivil()=="Viudx") estadocomboBox.setSelectedIndex(4);
           if(current.getSexo()=="Femenino") {femeninoCheckBox.setSelected(true);;}
           else masculinoCheckBox.setSelected(true);
        } else {
            edadField.setText("");
            String vacio="";
            estadocomboBox.setSelectedItem(vacio);

            //NO ME FUNCIONO x'd  me doy.. ;-;
            femeninoCheckBox.setSelected(false);
            masculinoCheckBox.setSelected(false);

        }
        this.panel.validate();
    }

    public Persona take(){
        Persona per=new Persona();
        per.setId(idField.getText());
        per.setNombre(nombreField.getText());
        per.setEdad(Integer.parseInt(edadField.getText()));
        if(femeninoCheckBox.isSelected()) per.setSexo("Femenino");
        if(masculinoCheckBox.isSelected()) per.setSexo("Masculino");
        per.setEstCivil((String) estadocomboBox.getSelectedItem());
        return per;
    }

    private boolean validate(){
        boolean valid=true;
        if(idField.getText().isEmpty()){
            valid=false;
            idLabel.setBorder(Application.BORDER_ERROR);
            idLabel.setToolTipText("ID requerido");
        }else{
            idLabel.setBorder(null);
            idLabel.setToolTipText(null);
        }
        if(nombreField.getText().isEmpty()){
            valid=false;
            nombreLabel.setBorder(Application.BORDER_ERROR);
            nombreLabel.setToolTipText("Nombre requerido");
        }else{
            nombreLabel.setBorder(null);
            nombreLabel.setToolTipText(null);
        }
        if(edadField.getText().isEmpty()){
            valid=false;
            edadLabel.setBorder(Application.BORDER_ERROR);
            edadLabel.setToolTipText("Edad requerido");
        }else{
            edadLabel.setBorder(null);
            edadLabel.setToolTipText(null);
        }
        if(!femeninoCheckBox.isSelected() && !masculinoCheckBox.isSelected()){
            valid=false;
            sexoLabel.setBorder(Application.BORDER_ERROR);
            sexoLabel.setToolTipText("Sexo requerido");
        }else{
            sexoLabel.setBorder(null);
            sexoLabel.setToolTipText(null);
        }

        if(estadocomboBox.getSelectedItem().toString().isEmpty()){
            valid=false;
            estadoLable.setBorder(Application.BORDER_ERROR);
            estadoLable.setToolTipText("Sexo requerido");
        }else{
            estadoLable.setBorder(null);
            estadoLable.setToolTipText(null);
        }


        return valid;
    }

}
