package sucursales.logic;

import jakarta.xml.bind.annotation.XmlAccessType;
import jakarta.xml.bind.annotation.XmlAccessorType;
import jakarta.xml.bind.annotation.XmlID;

import java.util.Vector;

@XmlAccessorType(XmlAccessType.FIELD)
public class Sucursal {
   @XmlID
    String id;
    String referencia;
    String direccion;
    double zonaje;

    private Vector<Integer> position;

    public Sucursal(String ced, String ref, String lug, double zon){
        referencia =ref;
        id=ced;
        direccion =lug;
        zonaje=zon;
        position = new Vector<>(2);
    }
    public Sucursal(){ this("","","",0.0);
    }
    public String getID() {
        return id;
    }

    public double getZonaje() {
        return zonaje;
    }

    public void setZonaje(double zonaje) {
        this.zonaje = zonaje;
    }

    public void setID(String cedula) {
        this.id = cedula;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String lug) {
        this.direccion = lug;
    }
    public String getReferencia() {
        return referencia;
    }

    public void setReferencia(String referencia) {
        this.referencia = referencia;
    }

    public Vector<Integer> getPosition() {return position;}

    public void setPosition(Vector<Integer> position) {this.position = position;}
}
