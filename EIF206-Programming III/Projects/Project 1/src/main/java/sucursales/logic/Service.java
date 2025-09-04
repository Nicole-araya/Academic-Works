package sucursales.logic;

import sucursales.data.Data;
import sucursales.data.XmlPersister;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Service {
    private static Service theInstance;

    public static Service instance(){
        if (theInstance == null){
            theInstance = new Service();
        }
        return theInstance;
    }

    private Data data;

    private Service(){
        try{
            data= XmlPersister.instance().load();
        }
        catch(Exception e){
            data =  new Data();
        }
    }

    public List<Empleado> empleadosSearch(String filtro){
        return data.getEmpleados().stream().filter(e->e.getNombre().contains(filtro))
                .sorted(Comparator.comparing(e -> e.getCedula()))
                .collect(Collectors.toList());
    }
    public List<Sucursal> sucursalesSearchName(String filtro){
        return data.getSucursales().stream().filter(e->e.getReferencia().contains(filtro))
                .sorted(Comparator.comparing(e -> e.getID()))
                .collect(Collectors.toList());
    }

    public void agregarEmpleado(Empleado emp)throws Exception{
        Empleado result = data.getEmpleados().stream().filter(e->e.getCedula().equals(emp.getCedula())).findFirst().orElse(null);
        if (result==null) data.getEmpleados().add(emp);
        else throw new Exception("Empleado ya existe");
    }

    public void agregarSucursal(Sucursal suc)throws Exception{
        Sucursal result = data.getSucursales().stream().filter(e->e.getID().equals(suc.getID())).findFirst().orElse(null);
        if (result==null) data.getSucursales().add(suc);
        else throw new Exception("Sucursal ya existe");
    }
    public Empleado getEmpleado(String cedula) throws Exception{
        Empleado result = data.getEmpleados().stream().filter(e->e.getCedula().equals(cedula)).findFirst().orElse(null);
        if (result!=null) return result;
        else throw new Exception("Empleado no existe");
    }

    public void empleadoDelete(Empleado empleado) throws Exception{
        Empleado result = data.getEmpleados().stream().filter(e->e.getCedula().equals(empleado.getCedula())).findFirst().orElse(null);
        if (result!=null) data.getEmpleados().remove(empleado);
        else throw new Exception("Empleado no existe");
    }
    public void empleadoUpdate(Empleado empleado) throws Exception{
        Empleado result;
        try{
            result = this.getEmpleado(empleado.cedula);
            data.getEmpleados().remove(result);
            data.getEmpleados().add(empleado);
        }catch (Exception e) {
            throw new Exception("Empleado no existe");
        }
    }

    public Sucursal getSucursal(String cod) throws Exception{
        Sucursal result = data.getSucursales().stream().filter(e->e.getID().equals(cod)).findFirst().orElse(null);
        if (result!=null) return result;
        else throw new Exception("Sucursal no existe");
    }

    public void sucursalDelete(Sucursal suc) throws Exception{
        Sucursal result = data.getSucursales().stream().filter(e->e.getID().equals(suc.getID())).findFirst().orElse(null);
        if (result!=null) data.getSucursales().remove(suc);
        else throw new Exception("Sucursal no existe");
    }
    public void sucursalUpdate(Sucursal suc) throws Exception{
        Sucursal result;
        try{
            result = this.getSucursal(suc.id);
            data.getSucursales().remove(result);
            data.getSucursales().add(suc);
        }catch (Exception e) {
            throw new Exception("Sucursal no existe");
        }
    }

    public List<Sucursal> getSucursales(){
        return data.getSucursales();
    }

    public void store(){
        try {
            XmlPersister.instance().store(data);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

