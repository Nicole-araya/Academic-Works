package com.example.dtos.gpt;
import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class Choices {
    ChatMessage message;

    public ChatMessage getMessage() {
        return message;
    }

    public void setMessage(ChatMessage message) {
        this.message = message;
    }

    public Choices(ChatMessage message) {
        this.message = message;
    }

    public Choices() {
    }
}
