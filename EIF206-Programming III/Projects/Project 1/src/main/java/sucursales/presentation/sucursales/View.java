package sucursales.presentation.sucursales;

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

    private JTextField IDField;
    private JTextField NombreField;
    private JButton AgregarButton;
    private JTable SucursalesField;
    private JPanel panel;
    private JButton borrarbutton;
    private JTextField ReferFiled;
    private JButton Buscarbutton;
    private JLabel ReferLabel;
    private JPanel mapa;
    private JLabel mapaLabel;
    private JButton PDFbutton;
    private JTextField LugarFiedl;

    public JPanel getPanel() {
        return panel;
    }

    Controller controller;
    Model model;
    Color cb, cf;

    public View() {
        Image mapaImage;
        Image PDFImage;
        try {
            mapaImage = ImageIO.read(new File("src/main/java/recursos/mapa.png"));
            PDFImage = ImageIO.read(new File("src/main/java/recursos/pdf.png"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        mapaImage = mapaImage.getScaledInstance(680, 625, 0);
        mapaLabel.setIcon(new ImageIcon(mapaImage));

        PDFImage = PDFImage.getScaledInstance(15,15,0);
        PDFbutton.setIcon(new ImageIcon(PDFImage));

        AgregarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.preAgregar();
            }
        });

        Buscarbutton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                cb = Buscarbutton.getBackground();
                cf = Buscarbutton.getForeground();
                Buscarbutton.setBackground(Color.GRAY);
                Buscarbutton.setForeground(Color.WHITE);
            }
        });
        Buscarbutton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseExited(MouseEvent e) {
                Buscarbutton.setBackground(cb);
                Buscarbutton.setForeground(cf);
            }
        });

        borrarbutton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                cb = borrarbutton.getBackground();
                cf = borrarbutton.getForeground();
                borrarbutton.setBackground(Color.GRAY);
                borrarbutton.setForeground(Color.WHITE);
            }
        });
        borrarbutton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseExited(MouseEvent e) {
                borrarbutton.setBackground(cb);
                borrarbutton.setForeground(cf);
            }
        });

        AgregarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                cb = AgregarButton.getBackground();
                cf = AgregarButton.getForeground();
                AgregarButton.setBackground(Color.GRAY);
                AgregarButton.setForeground(Color.WHITE);
            }
        });
        AgregarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseExited(MouseEvent e) {
                AgregarButton.setBackground(cb);
                AgregarButton.setForeground(cf);
            }
        });
        borrarbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                int row = SucursalesField.getSelectedRow();
                controller.borrar(row);
            }
        });
        SucursalesField.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    int row = SucursalesField.getSelectedRow();
                    controller.editar(row);
                }
            }
        });
        Buscarbutton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                controller.buscar(ReferFiled.getText());
            }
        });

        PDFbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    controller.imprimir();
                    if (Desktop.isDesktopSupported()) {
                        File myFile = new File("Sucursales.pdf");
                        Desktop.getDesktop().open(myFile);
                    }
                } catch (Exception ex) {
                }
            }
        });
    }

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

    public void update(Observable updatedModel, Object parametros) {
        int[] cols = {TableModel.CODIGO, TableModel.REFERANCIA, TableModel.DIRECCION, TableModel.ZONAJE};
        SucursalesField.setModel(new TableModel(cols, model.getSucursales()));
        SucursalesField.setRowHeight(30);
        agreganPin();
        this.panel.revalidate();
    }

    public void agreganPin() {

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

            Image finalPinAzul = pinAzul;
            newLabel.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseEntered(MouseEvent e) {
                    Image pinRojo;
                    try {
                        pinRojo = ImageIO.read(new File("src/main/java/recursos/SucursalSel.png"));
                    } catch (IOException ec) {
                        throw new RuntimeException(ec);
                    }
                    pinRojo = pinRojo.getScaledInstance(40,40, 0);

                    newLabel.setIcon(new ImageIcon(pinRojo));
                }
                @Override
                public void mouseExited(MouseEvent e) {
                    newLabel.setIcon(new ImageIcon(finalPinAzul));
                }
            });
        }
    }
}

