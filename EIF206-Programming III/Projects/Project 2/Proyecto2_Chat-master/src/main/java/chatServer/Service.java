package chatServer;

import chatProtocol.User;
import chatProtocol.IService;
import chatProtocol.Message;
import chatServer.data.Data;
import chatServer.data.UsuarioDao;

import java.util.List;

public class Service implements IService{

   // private Data data;
    private UsuarioDao userDao;
    public Service() {
       // data =  new Data();
        userDao=new UsuarioDao();
    }


    public void post(Message m){
        // if wants to save messages, ex. recivier no logged on
    }
    
    public User login(User p) throws Exception {
        //for(User u:data.getUsers()) if(p.equals(u)) return u;
        //throw new Exception("User does not exist");
        return userDao.read(p.getId());

    }
    public void register(User u) throws Exception{
       userDao.create(u);
    }
    public void logout(User p) throws Exception{
        //nothing to do
    }
    public User checkContact(User user){
        try {
            return userDao.read(user.getId());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public List<User> getContactos(){
        return null;
    }

    @Override
    public List<User> contactosSearch(String filtro) {
        return null;
    }
}
