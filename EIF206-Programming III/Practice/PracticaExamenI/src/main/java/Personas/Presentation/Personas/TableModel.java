package Personas.Presentation.Personas;

import Personas.Logic.Persona;
import com.itextpdf.layout.element.Image;

import java.util.List;
import javax.swing.*;
import javax.swing.table.AbstractTableModel;

public class TableModel extends AbstractTableModel implements javax.swing.table.TableModel {

    List<Persona> rows;
    int[] cols;
    String[] colNames = new String[5];

    public TableModel(int[] cols,List<Persona> rows){
        initColNames();
        this.cols=cols;
        this.rows=rows;

    }

    public static final int CEDULA=0;
    public static final int NOMBRE=1;
    public static final int EDAD=2;
    public static final int SEXO=3;
    public static final int ESTADO=4;

    private void initColNames() {
        colNames[CEDULA]= "Cedula";
        colNames[NOMBRE]= "Nombre";
        colNames[EDAD]= "Edad";
        colNames[SEXO]= "Sexo";
        colNames[ESTADO]= "Estado Civil";

    }

    public String getColumnName(int col){
        return colNames[cols[col]];
    }

    @Override
    public int getRowCount() {
        return rows.size();
    }

    @Override
    public int getColumnCount() {
        return cols.length;
    }

    @Override
    public Object getValueAt(int row, int col) {
        Persona per = rows.get(row);

        switch (cols[col]){
            case CEDULA: return per.getId();
            case NOMBRE: return per.getNombre();
            case EDAD: return per.getEdad();
            case SEXO: return ImageIcon.class; // no c
            case ESTADO: return  per.getEstCivil();
            default: return "";
        }
    }


    private Icon sexo(Persona p){
        String file="";
        if(p.getSexo()=="Femenino") file="f.png";
        if(p.getSexo()=="Masculino") file="m.png";
        return new ImageIcon(getClass().getResource("src/main/java/Personas/recursos/"+file));

    }
}
