package sucursales.presentation.Sucursal;

import sucursales.Application;
import sucursales.logic.Sucursal;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.IOException;
import java.util.Objects;
import java.util.Observable;
import java.util.Observer;

public class View implements Observer {
    private JPanel panel;
    private JPanel mapa;
    private JTextField codField;
    private JTextField referField;
    private JTextField direcField;
    private JTextField zonajeField;
    private JLabel codlabel;
    private JLabel referlabel;
    private JLabel direclabel;
    private JButton Guardarbutton;
    private JButton Cancelarbutton;
    private JLabel mapaLabel;
    private JLabel zonajelabel;
    private JLabel chirulito;

    Controller controller;
    Model model;

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
                if (validate()) {

                    Sucursal s = take();
                    try {
                        controller.guardar(s);
                    } catch (Exception ex) {
                        JOptionPane.showMessageDialog(panel, ex.getMessage(), "ERROR", JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        });
        Cancelarbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.hide();
            }
        });
        mapaLabel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int x_ = (int) mapaLabel.getMousePosition().getX();
                int y_ = (int) mapaLabel.getMousePosition().getY();

                mapaLabel.setLayout(null);
                Image pinAzul;
                try {
                    pinAzul = ImageIO.read(new File("src/main/java/recursos/Sucursal.png"));
                } catch (IOException ec) {
                    throw new RuntimeException(ec);
                }
                pinAzul = pinAzul.getScaledInstance(40, 40, 0);

                chirulito.setBounds(x_, y_, 40, 40);

                chirulito.setIcon(new ImageIcon(pinAzul));
                mapaLabel.add(chirulito);
                mapaLabel.revalidate();
                mapaLabel.repaint();

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
    public void update(Observable updatedModel, Object parametros) {
        Sucursal current = model.getCurrent();
        this.codField.setEnabled(model.getModo() == Application.MODO_AGREGAR);
        this.codField.setText(current.getID());
        referField.setText(current.getReferencia());
        direcField.setText(current.getDireccion());
        if(model.getModo()==1)zonajeField.setText(String.valueOf(current.getZonaje()));
        else zonajeField.setText("");
        mapaLabel.removeAll();
        mapaLabel.repaint();
        mapaLabel.revalidate();
        this.panel.validate();
    }

    public Sucursal take() {
        Sucursal s = new Sucursal();
        s.setID(codField.getText());
        s.setReferencia(referField.getText());
        s.setDireccion(direcField.getText());
        s.setZonaje(Double.parseDouble(zonajeField.getText()));

        s.getPosition().add(chirulito.getX());
        s.getPosition().add(chirulito.getY());

        return s;
    }


    private boolean validate() {
        boolean valid = true;
        if (codField.getText().isEmpty()) {
            valid = false;
            codlabel.setBorder(Application.BORDER_ERROR);
            codlabel.setToolTipText("Codigo requerido");
        } else {
            codlabel.setBorder(null);
            codlabel.setToolTipText(null);
        }

        if (referField.getText().length() == 0) {
            valid = false;
            referlabel.setBorder(Application.BORDER_ERROR);
            referlabel.setToolTipText("Referencia requerido");
        } else {
            referlabel.setBorder(null);
            referlabel.setToolTipText(null);
        }

        if (direcField.getText().isEmpty()) {
            valid = false;
            direclabel.setBorder(Application.BORDER_ERROR);
            direclabel.setToolTipText("Direccion requerida");
        } else {
            direclabel.setBorder(null);
            direclabel.setToolTipText(null);

        }
        if (zonajeField.getText().isBlank()) {
            valid = false;
            zonajelabel.setBorder(Application.BORDER_ERROR);
            zonajelabel.setToolTipText("Zonaje requerida");
        } else {
            zonajelabel.setBorder(null);
            zonajelabel.setToolTipText(null);

        }
        if(Objects.equals(chirulito.getBounds(), new Rectangle(0, 10, 0, 0))){
            valid = false;
            mapaLabel.setBorder(Application.BORDER_ERROR);
            mapaLabel.setToolTipText("Ubicacion en mapa requerida");
            mapaLabel.repaint(); mapaLabel.revalidate();
        }else {
            mapaLabel.setBorder(null);
            mapaLabel.setToolTipText(null);
        }

        return valid;
    }
}