package Personas.Presentation.Personas;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.util.Observable;
import java.util.Observer;

public class View implements Observer {
    private JPanel panel;
    private JTextField idField;
    private JButton buscarButton;
    private JButton agregarButton;
    private JButton borrarButton;
    private JButton pdfButton;
    private JTable personasTable;

    Controller controller;
    Model model;

    public View(){


        agregarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.preAgregar();
            }
        });
        borrarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int row=personasTable.getSelectedRow();
                controller.borrar(row);
            }
        });
        pdfButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    controller.imprimir();
                    if(Desktop.isDesktopSupported()){
                        File myFile=new File("Personas.pdf");
                        Desktop.getDesktop().open(myFile);
                    }
                } catch (Exception ex) {
                }
            }
        });
        buscarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.buscar(idField.getText());
            }
        });
        personasTable.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    int row = personasTable.getSelectedRow();
                    controller.editar(row);
                }
            }
        });
    }
    public JPanel getPanel() {
        return panel;
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
        int[] cols = {TableModel.CEDULA, TableModel.NOMBRE, TableModel.EDAD, TableModel.SEXO, TableModel.ESTADO};
        personasTable.setModel(new TableModel(cols, model.getPersonas()));
        personasTable.setRowHeight(30);
        this.panel.revalidate();
    }
}
