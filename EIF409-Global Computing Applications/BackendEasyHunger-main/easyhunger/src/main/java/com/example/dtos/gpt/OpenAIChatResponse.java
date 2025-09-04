package com.example.dtos.gpt;

import java.util.List;
import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class OpenAIChatResponse {
    List<Choices> choices;

    public OpenAIChatResponse(List<Choices> choice) {
        this.choices = choice;
    }

    public List<Choices> getChoices() {
        return choices;
    }

    public void setChoice(List<Choices> choices) {
        this.choices = choices;
    }

    public OpenAIChatResponse() {
    }
}
