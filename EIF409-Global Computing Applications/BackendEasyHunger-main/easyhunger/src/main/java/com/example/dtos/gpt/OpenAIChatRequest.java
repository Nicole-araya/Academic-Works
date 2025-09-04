package com.example.dtos.gpt;

import java.util.List;
import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class OpenAIChatRequest {
    String model;
    List<ChatMessage> messages;

    public OpenAIChatRequest(String model, List<ChatMessage> messages) {
        this.model = model;
        this.messages = messages;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public List<ChatMessage> getMessages() {
        return messages;
    }

    public void setMessages(List<ChatMessage> messages) {
        this.messages = messages;
    }

    @Override
    public String toString() {
        return "{\"model\":\"" + model + '\"' +
                ", \"messages\":" + messages.toString() +
                "}";
    }

    public OpenAIChatRequest() {
    }
}
