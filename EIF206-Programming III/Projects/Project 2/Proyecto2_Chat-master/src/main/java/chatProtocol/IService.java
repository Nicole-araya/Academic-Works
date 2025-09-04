package chatProtocol;

import java.util.List;

public interface IService {
    public User login(User u) throws Exception;
    public void logout(User u) throws Exception;
    public void register(User u) throws Exception;
    public void post(Message m);
    public User checkContact(User user);

    public List<User> getContactos();

    List<User> contactosSearch(String filtro);
}
