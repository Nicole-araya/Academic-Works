package com.example.dtos.user;

public class RegisterRequest {

    private final String name;
    private final String email;
    private final String password;

    public RegisterRequest() {
        this.name = "";
        this.email = "";
        this.password = "";
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getPassword() {
        return password;
    }
}
