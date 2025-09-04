package chatClient.presentation;

import chatClient.logic.ServiceProxy;
import chatProtocol.Message;
import chatProtocol.User;

import java.util.ArrayList;
import java.util.List;

public class Controller {
    View view;
    Model model;
    
    ServiceProxy localService;
    
    public Controller(View view, Model model) {
        this.view = view;
        this.model = model;
        localService = (ServiceProxy)ServiceProxy.instance();
        localService.setController(this);
        view.setController(this);
        view.setModel(model);
    }

    public void login(User u) throws Exception{
        User logged=ServiceProxy.instance().login(u);
        if(ServiceProxy.instance().getContactos()!=null)
            model.setContactos(ServiceProxy.instance().getContactos());

        model.setCurrentUser(logged);
        model.commit(Model.USER+Model.CHAT);
    }
    public void register(User u) throws Exception {
        ServiceProxy.instance().register(u);
    }
    public void post(String text, int num){
        User receiver=searchUser(num);
        Message message = new Message();
        message.setMessage(text);
        message.setSender(model.getCurrentUser());
        message.setReceiver(receiver);
        ServiceProxy.instance().post(message);
        model.commit(Model.CHAT);

    }
    public User searchUser(int num) {
       return model.getContactos().get(num);
    }
    public void logout(){
        try {
            ServiceProxy.instance().logout(model.getCurrentUser());
            model.setMessages(new ArrayList<>());
            model.commit(Model.CHAT);
        } catch (Exception ex) {
        }
        model.setCurrentUser(null);
        model.commit(Model.USER+Model.CHAT);
    }
        
    public void deliver(Message message){
        model.messages.add(message);
        model.commit(Model.CHAT);       
    }
    public void addContact(User user) {
        ServiceProxy.instance().checkContact(user);
    }
    public void senderContact(User user) {
        model.getContactos().add(user);
        model.commit(Model.CHAT);
    }

    public void buscarContacto(String filtro){
        List<User> rows = ServiceProxy.instance().contactosSearch(filtro);
        model.setContactos(rows);
        model.commit(Model.CHAT);
    }
}
