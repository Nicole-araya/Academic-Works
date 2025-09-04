package Personas.Logic;

import Personas.Data.Data;
import Personas.Data.XmlPersister;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Service {

    private Data data;
    private static Service theInstance;

    public static Service instance(){
        if(theInstance==null){
            theInstance=new Service();
        }
        return theInstance;
    }

    private Service(){
        try{
            data= XmlPersister.instance().load();
        }catch(Exception e){
            data =  new Data();
        }
    }
    public void store(){
        try {
            XmlPersister.instance().store(data);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public List<Persona> personaSearch(String filtro){  //BUSCA X ID y devulve lista
        return data.getPersonas().stream().filter(p->p.getId().contains(filtro))
                .sorted(Comparator.comparing(p->p.getId())).collect(Collectors.toList());
    }
    public void agregarPersona(Persona pe)throws Exception{
        Persona per=data.getPersonas().stream().filter(p->p.getId().equals(pe.getId()))
                .findFirst().orElse(null);
        if(per==null) data.getPersonas().add(pe);
        else throw new Exception("Persona ya existe");
    }
    public Persona getPersona(String filtro)throws Exception{  //Buca x ID, devuelve empleado
        Persona per=data.getPersonas().stream().filter(p->p.getId().equals(filtro))
                .findFirst().orElse(null);
        if(per!=null) return per;
        else throw new Exception("Persona no existe");
    }
    public void personaDelete(Persona per)throws Exception{
        Persona pe=data.getPersonas().stream().filter(p->p.getId().equals(per.getId())).findFirst().orElse(null);
        if(pe!=null)data.getPersonas().remove(per);
        else throw new Exception("Persona no existe");
    }

    public void personaUpdate(Persona p)throws Exception{
        Persona per;
        try{
            per=this.getPersona(p.id);
            data.getPersonas().remove(per);
            data.getPersonas().add(p);
        }catch (Exception e){
            throw new Exception("Persona no existe");
        }
    }
}
