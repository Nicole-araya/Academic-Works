package sucursales.presentation.empleados;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.IOException;
import java.util.Observable;
import java.util.Observer;

public class View implements Observer {
    private JPanel panel;
    private JTextField nombreFld;
    private JButton BuscarButton;
    private JButton AgregarButton;
    private JTable empleadosFld;
    private JLabel nombreLbl;
    private JButton borrarbutton;
    private JButton PDFbutton;
    private JTextField IDField;

    Color cb, cf;

    public View() {

        Image PDFImage;
        try {
            PDFImage = ImageIO.read(new File("src/main/java/recursos/pdf.png"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        PDFImage = PDFImage.getScaledInstance(15,15,0);
        PDFbutton.setIcon(new ImageIcon(PDFImage));

        BuscarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.buscar(nombreFld.getText());
            }
        });
        AgregarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                controller.preAgregar();
            }
        });
        empleadosFld.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    int row = empleadosFld.getSelectedRow();
                    controller.editar(row);
                }
            }
        });
        borrarbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int row = empleadosFld.getSelectedRow();
                controller.borrar(row);
            }
        });

        BuscarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                cb = BuscarButton.getBackground();
                cf = BuscarButton.getForeground();
                BuscarButton.setBackground(Color.GRAY);
                BuscarButton.setForeground(Color.WHITE);
            }
        });
        BuscarButton.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseExited(MouseEvent e) {
                BuscarButton.setBackground(cb);
                BuscarButton.setForeground(cf);
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
        PDFbutton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    controller.imprimir();
                    if (Desktop.isDesktopSupported()) {
                        File myFile = new File("Empleados.pdf");
                        Desktop.getDesktop().open(myFile);
                    }
                } catch (Exception ex) {
                }
            }
        });

    }

    public JPanel getPanel() {
        return panel;
    }

    Controller controller;
    Model model;

    public void setController(Controller controller) {
        this.controller = controller;
    }

    public void setModel(Model model) {
        this.model = model;
        model.addObserver(this);
    }

    @Override
    public void update(Observable updatedModel, Object parametros) {
        int[] cols = {TableModel.CEDULA, TableModel.NOMBRE, TableModel.TELEFONO, TableModel.SALARIO, TableModel.SUCURSAL, TableModel.ZONAJE, TableModel.SALARIOTOTAL};
        empleadosFld.setModel(new TableModel(cols, model.getEmpleados()));
        empleadosFld.setRowHeight(30);
        this.panel.revalidate();
    }

}