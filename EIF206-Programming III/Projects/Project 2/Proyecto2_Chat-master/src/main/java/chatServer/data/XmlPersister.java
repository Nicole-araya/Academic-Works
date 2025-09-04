package chatServer.data;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import jakarta.xml.bind.JAXBContext;
import jakarta.xml.bind.Marshaller;
import jakarta.xml.bind.Unmarshaller;
public class XmlPersister {
    private String path;
    private static XmlPersister theInstance;
    public static XmlPersister instance(){
        if (theInstance==null){
            theInstance=new XmlPersister("contactos.xml");
        }
        return theInstance;
    }

    public XmlPersister(String p) {
        path=p;
    }

    public Data load(String p) throws Exception{
        JAXBContext jaxbContext = JAXBContext.newInstance(Data.class);
        FileInputStream is = new FileInputStream(p+".xml");
        //FileInputStream is = new FileInputStream(this.getClass().getResource(path).getFile());
        Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
        Data result = (Data) unmarshaller.unmarshal(is);
        is.close();
        return result;
    }

    public void store(Data d, String p)throws Exception{
        JAXBContext jaxbContext = JAXBContext.newInstance(Data.class);
        FileOutputStream os = new FileOutputStream(p+".xml");
        Marshaller marshaller = jaxbContext.createMarshaller();
        marshaller.marshal(d, os);
        os.flush();
        os.close();
    }
}
