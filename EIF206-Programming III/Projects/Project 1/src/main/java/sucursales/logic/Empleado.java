package sucursales.logic;
import jakarta.xml.bind.annotation.XmlAccessType;
import jakarta.xml.bind.annotation.XmlAccessorType;
import jakarta.xml.bind.annotation.XmlIDREF;

import javax.lang.model.type.NullType;

@XmlAccessorType(XmlAccessType.FIELD)
public class Empleado {
    String cedula;
    String nombre;
    int telefono;
    double salario;
    @XmlIDREF
    Sucursal sucursal;

    public Empleado(String cedula, String nombre,int tel,double salar,Sucursal suc) {
        this.cedula = cedula;
        this.nombre = nombre;
        telefono=tel;
        salario=salar;
        sucursal=suc;
    }

    public Empleado() {
        this("","",0,0,null);
    }

    public String getCedula() {
        return cedula;
    }
    public Sucursal getSucursal() {
        return sucursal;
    }
    public void setCedula(String cedula) {
        this.cedula = cedula;
    }
    public void setSucursal(Sucursal s) {
        this.sucursal = s;
    }
    public void setTelefono(int tele) {
        this.telefono = tele;
    }
    public void setSalario(double sala) {
        this.salario = sala;
    }
    public String getNombre() {
        return nombre;
    }
    public int getTelefono() {
        return telefono;
    }
    public double getSalario() {
        return salario;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double salarioTotal(){ return ((salario*(sucursal.getZonaje()/100))+salario);}
}
