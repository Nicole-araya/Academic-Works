package chatClient.logic;

import chatClient.presentation.Controller;
import chatServer.data.Data;
import chatServer.data.XmlPersister;
import chatProtocol.User;
import chatProtocol.Protocol;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import javax.swing.SwingUtilities;
import chatProtocol.IService;
import chatProtocol.Message;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class ServiceProxy implements IService{
    private static IService theInstance;
    public static IService instance(){
        if (theInstance==null){ 
            theInstance=new ServiceProxy();
        }
        return theInstance;
    }

    ObjectInputStream in;
    ObjectOutputStream out;
    Controller controller;
    Data data;


    public ServiceProxy() {
    }

    public void setController(Controller controller) {
        this.controller = controller;
    }

    Socket skt;
    private void connect() throws Exception{
        skt = new Socket(Protocol.SERVER,Protocol.PORT);
        out = new ObjectOutputStream(skt.getOutputStream() );
        out.flush();
        in = new ObjectInputStream(skt.getInputStream());    
    }

    private void disconnect() throws Exception{
        skt.shutdownOutput();
        skt.close();
    }
    public List<User> getContactos(){

        return data.getUsers();
    }

    public List<User> contactosSearch(String filtro){
        return data.getUsers().stream().filter(e->e.getNombre().contains(filtro))
                .sorted(Comparator.comparing(e -> e.getNombre()))
                .collect(Collectors.toList());
    }

    public User getContacto(String nombre) throws Exception{
        User result = data.getUsers().stream().filter(e->e.getNombre().equals(nombre)).findFirst().orElse(null);
        if (result!=null) return result;
        else throw new Exception("Contacto no existe");
    }
    public User login(User u) throws Exception{
        connect();
        try {
            out.writeInt(Protocol.LOGIN);
            out.writeObject(u);
            out.flush();
            int response = in.readInt();
            if (response==Protocol.ERROR_NO_ERROR){
                User u1=(User) in.readObject();
                this.start();
                try{
                   data= XmlPersister.instance().load(u1.getNombre());
                }
                catch(Exception e){
                    data =  new Data();
                }

                return u1;
            }
            else {
                disconnect();
                throw new Exception("No remote user");
            }            
        } catch (IOException | ClassNotFoundException ex) {
            return null;
        }
    }
    public User checkContact(User user){
        try {
            out.writeInt(Protocol.CONTACT);
            out.writeObject(user);
            out.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return null;
    }
    public void register(User u) throws Exception{
        connect();
        try {
            out.writeInt(Protocol.REGISTER);
            out.writeObject(u);
            out.flush();
            int response = in.readInt();
            if (response==Protocol.ERROR_NO_ERROR){
                disconnect();
            }
            else {
               disconnect();
                throw new Exception("No remote user");
            }
        }catch (IOException | ClassNotFoundException ex) {
        }
    }
    public void logout(User u) throws Exception{
        out.writeInt(Protocol.LOGOUT);
        out.writeObject(u);
        out.flush();
        XmlPersister.instance().store(data,u.getNombre());
        this.stop();
        this.disconnect();
    }
    
    public void post(Message message){
        try {
            out.writeInt(Protocol.POST);
            out.writeObject(message);
            out.flush();
        } catch (IOException ex) {
            
        }   
    }  

    // LISTENING FUNCTIONS
   boolean continuar = true;    
   public void start(){
        System.out.println("Client worker atendiendo peticiones...");
        Thread t = new Thread(new Runnable(){
            public void run(){
                listen();
            }
        });
        continuar = true;
        t.start();
    }
    public void stop(){
        continuar=false;
    }
    
   public void listen(){
        int method;
        while (continuar) {
            try {
                method = in.readInt();
                System.out.println("DELIVERY");
                System.out.println("Operacion: "+method);
                switch(method){
                case Protocol.DELIVER:
                    try {
                        Message message=(Message)in.readObject();
                        deliver(message);
                    } catch (ClassNotFoundException ex) {}
                    break;
                    case Protocol.CONTACT_RESPONSE:
                        User user= null;
                        try {
                            user = (User)in.readObject();
                            responseContact(user);

                        } catch (ClassNotFoundException e) {
                            throw new RuntimeException(e);
                        }
                        break;
                        case Protocol.ERROR_CONTACT:
                            throw new Exception("No exist user");
                }
                out.flush();
            } catch (IOException  ex) {
                continuar = false;
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
    }

    private void responseContact( final User user ){
        SwingUtilities.invokeLater(new Runnable(){
            public void run(){
                                           controller.senderContact(user);
                                       }
                                   }
        );
    }
   private void deliver( final Message message ){
      SwingUtilities.invokeLater(new Runnable(){
            public void run(){
               controller.deliver(message);
            }
         }
      );
   }
}
