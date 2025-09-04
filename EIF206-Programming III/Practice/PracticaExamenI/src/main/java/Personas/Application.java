package Personas;

import Personas.Presentation.Persona.Controller;
import Personas.Presentation.Persona.Model;
import Personas.Presentation.Persona.View;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class Application {
    public static void main(String[] args) {
        try {
            UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");}
        catch (Exception ex) {};

        Model permodel=new Model();
        View perview=new View();
        personaController=new Controller(perview,permodel);

        Personas.Presentation.Personas.Model persModel=new Personas.Presentation.Personas.Model();
        Personas.Presentation.Personas.View persView=new Personas.Presentation.Personas.View();
        personasController=new Personas.Presentation.Personas.Controller(persView,persModel);

        Personas.Presentation.main.Model mainModel=new Personas.Presentation.main.Model();
        Personas.Presentation.main.View mainView=new Personas.Presentation.main.View();
        mainController=new Personas.Presentation.main.Controller(mainView,mainModel);

        mainView.getPanel().add("Personas",persView.getPanel());

        window = new JFrame();
        window.setSize(400,300);
        window.setExtendedState(JFrame.MAXIMIZED_BOTH);
        window.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        window.setTitle("NicoleAraya_PracticaExamenI");
        window.setVisible(true);
        mainController.show();
    }
    public static Personas.Presentation.main.Controller mainController;
    public static Personas.Presentation.Persona.Controller personaController;
    public static Personas.Presentation.Personas.Controller personasController;
    public static JFrame window;
    public static  final int  MODO_AGREGAR=0;
    public static final int MODO_EDITAR=1;
    public static Border BORDER_ERROR = BorderFactory.createMatteBorder(0, 0, 2, 0, Color.RED);
}
