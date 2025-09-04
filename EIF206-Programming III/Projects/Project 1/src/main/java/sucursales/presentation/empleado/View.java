package sucursales.presentation.empleado;

import sucursales.Application;
import sucursales.logic.Empleado;
import sucursales.logic.Sucursal;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.util.Observable;
import java.util.Observer;

public class View implements Observer {
    private JTextField idField;
    private JTextField nombrefield;
    private JPanel panel;
    private JLabel mapaLabel;
    private JLabel Idlabel;
    private JLabel NombreLabel;
    private JButton Guardarbutton;
    private JButton Cancelarbutton;
    private JTextField telefonoField;
    private JLabel TeleLbl;
    private JTextField SalarioField;
    private JLabel SalarLabl;
    private JLabel SucursalLbl;
    private JTextField sucursalField;
    private JPanel mapa;

    public View() {
        Image mapaImage;
        try {
            mapaImage = ImageIO.read(new File("src/main/java/recursos/mapa.png"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        mapaImage = mapaImage.getScaledInstance(680, 625, 0);
        mapaLabel.setIcon(new ImageIcon(mapaImage));

        Guardarbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(validate()){
                    Empleado n = take(sucursal);
                    try {
                        controller.guardar(n);
                    } catch (Exception ex) {
                        JOptionPane.showMessageDialog(panel, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                    }
            }}
        });
        Cancelarbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.hide();
            }
        });
    }

    public JPanel getPanel() {
        return panel;
    }

    Controller controller;
    Model model;

    Sucursal sucursal;

    public void setController(Controller controller) {
        this.controller = controller;
    }

    public void setModel(Model model) {
        this.model = model;
        model.addObserver(this);
    }
    public Controller getController() {
        return controller;
    }

    public Model getModel() {
        return model;
    }
    @Override
    public void update(Observable updatedModel, Object parametros) {
        Empleado current = model.getCurrent();
        this.idField.setEnabled(model.getModo() == Application.MODO_AGREGAR);
        this.idField.setText(current.getCedula());
        nombrefield.setText(current.getNombre());

        if(model.getModo()==1){
            telefonoField.setText(String.valueOf(current.getTelefono()));
            SalarioField.setText(String.valueOf(current.getSalario()));
        } else { telefonoField.setText("");  SalarioField.setText("");
            sucursalField.setText("");}
        agregarSucursalPin();
        if(model.getModo()==1) {
            sucursalField.setForeground(Color.RED);
            sucursalField.setText(current.getSucursal().getReferencia());
        }else{
        sucursalField.setForeground(Color.black);
        sucursalField.setText("");}

        this.panel.validate();
    }

    public Empleado take(Sucursal s) {
        Empleado e = new Empleado();
        e.setCedula(idField.getText());
        e.setNombre(nombrefield.getText());
        e.setTelefono(Integer.parseInt(telefonoField.getText()));
        e.setSalario(Double.parseDouble(SalarioField.getText()));
        e.setSucursal(s);
        return e;
    }

    private boolean validate() {
        boolean valid = true;
        if (idField.getText().isEmpty()) {
            valid = false;
            Idlabel.setBorder(Application.BORDER_ERROR);
            Idlabel.setToolTipText("Id requerido");
        } else {
            Idlabel.setBorder(null);
            Idlabel.setToolTipText(null);
        }
        if (nombrefield.getText().length() == 0) {
            valid = false;
            NombreLabel.setBorder(Application.BORDER_ERROR);
            NombreLabel.setToolTipText("Nombre requerido");
        } else {
            NombreLabel.setBorder(null);
            NombreLabel.setToolTipText(null);
        }
        if (telefonoField.getText().length() == 0) {
            valid = false;
            TeleLbl.setBorder(Application.BORDER_ERROR);
            TeleLbl.setToolTipText("Telefono requerido");
        } else {
            TeleLbl.setBorder(null);
            TeleLbl.setToolTipText(null);
        }
        if (SalarioField.getText().length() == 0) {
            valid = false;
            SalarLabl.setBorder(Application.BORDER_ERROR);
            SalarLabl.setToolTipText("Salario requerido");
        } else {
            SalarLabl.setBorder(null);
            SalarLabl.setToolTipText(null);
        }
        if(sucursalField.getText().isEmpty()){
            valid = false;
            SucursalLbl.setBorder(Application.BORDER_ERROR);
            mapaLabel.setBorder(Application.BORDER_ERROR);
            SucursalLbl.setToolTipText("Sucursal requerido");

        }else {
            SucursalLbl.setBorder(null);
            mapaLabel.setBorder(null);
            SucursalLbl.setToolTipText(null);
        }


        //TODO validar un click en el mapaLabel
        return valid;
    }

    public void agregarSucursalPin(){

        Image pinAzul;
        try {
            pinAzul = ImageIO.read(new File("src/main/java/recursos/Sucursal.png"));
        } catch (IOException ec) {
            throw new RuntimeException(ec);
        }

        mapaLabel.removeAll();
        mapaLabel.repaint();
        mapaLabel.revalidate();

        pinAzul = pinAzul.getScaledInstance(40, 40, 0);

        for (Sucursal sucursal_ : model.getSucursales()) {
            int x_ = sucursal_.getPosition().elementAt(0);
            int y_ = sucursal_.getPosition().elementAt(1);
            JLabel newLabel = new JLabel();
            newLabel.setBounds(x_, y_, 40, 40);

            newLabel.setToolTipText(sucursal_.getReferencia() +" "+sucursal_.getDireccion());

            newLabel.setIcon(new ImageIcon(pinAzul));
            mapaLabel.add(newLabel);

            mapaLabel.revalidate();
            mapaLabel.repaint();
            newLabel.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                        Image pinRojo;
                        try {
                            pinRojo = ImageIO.read(new File("src/main/java/recursos/SucursalSel.png"));
                        } catch (IOException ec) {
                            throw new RuntimeException(ec);
                        }

                        pinRojo = pinRojo.getScaledInstance(40, 40, 0);
                        newLabel.setIcon(new ImageIcon(pinRojo));

                        sucursal = sucursal_;

                        sucursalField.setForeground(Color.RED);
                        sucursalField.setText(sucursal.getReferencia());

                        mapaLabel.setBorder(null);
                        mapaLabel.setToolTipText(null);


                }
            });
        }
    }



}