package com.example.dtos.user;

public class LoginResponse {
    private String id;
    private String name;

    public LoginResponse() {}

    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
}
