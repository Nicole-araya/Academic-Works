package sucursales.presentation.AcercaDe;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.TitledBorder;
import javax.swing.plaf.FontUIResource;
import javax.swing.text.StyleContext;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.IOException;
import java.util.Locale;


public class View {
    private JPanel panel;
    private JPanel imgPanel;
    private JLabel imgLabel;
    Image img;
    public View() {

        try {
            img = ImageIO.read(new File("src/main/java/recursos/imag.png"));

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        img = img.getScaledInstance(500, 500, 0);
        imgLabel.setIcon(new ImageIcon(img));
        imgLabel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {

                if (e.getClickCount() == 2) {
                    imgLabel.setIcon(new ImageIcon(img));
                }
                else{
                    Image stonk;
                try {
                    stonk=ImageIO.read(new File("src/main/java/recursos/Stonk.png"));
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
                stonk=stonk.getScaledInstance(500, 500, 0);
                imgLabel.setIcon(new ImageIcon(stonk));
            }}
        });
    }

    public JPanel getPanel() {
        return panel;
    }

}
