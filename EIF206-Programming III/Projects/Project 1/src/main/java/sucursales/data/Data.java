package sucursales.data;

import sucursales.logic.Empleado;
import sucursales.logic.Sucursal;
import jakarta.xml.bind.annotation.XmlAccessType;
import jakarta.xml.bind.annotation.XmlAccessorType;
import jakarta.xml.bind.annotation.XmlRootElement;
import java.util.ArrayList;
import java.util.List;
@XmlRootElement
@XmlAccessorType(XmlAccessType.FIELD)
public class Data {
    private List<Empleado> empleados;
    private List<Sucursal> sucursales;
    public Data() {
        empleados = new ArrayList<>();
        sucursales=new ArrayList<>();

    }

    public List<Empleado> getEmpleados() {
        return empleados;
    }

    public List<Sucursal> getSucursales() {
        return sucursales;
    }

    public void setSucursales(List<Sucursal> sucursales){this.sucursales=sucursales;}

    public void setEmpleados(List<Empleado> empleados) {
        this.empleados = empleados;
    }


}
