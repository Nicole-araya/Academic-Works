package chatProtocol;

import java.io.Serializable;

public class Message implements Serializable{
    User sender;
    User receiver;
    String message;

    public User getReceiver() {
        return receiver;
    }

    public void setReceiver(User receiver) {
        this.receiver = receiver;
    }

    public Message() {
    }

    public Message(User sedner,String message, User rece) {
        this.sender = sedner;
        receiver=rece;
        this.message = message;
    }

    public User getSender() {
        return sender;
    }

    public void setSender(User sender) {
        this.sender = sender;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
    
}
