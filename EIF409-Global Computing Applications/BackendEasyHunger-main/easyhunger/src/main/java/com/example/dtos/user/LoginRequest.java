package com.example.dtos.user;

public class LoginRequest {
    private final String email;
    private final String password;

    public LoginRequest() {
        this.email = "";
        this.password = "";
    }

    public String getEmail() {
        return email;
    }

    public String getPassword() {
        return password;
    }
}
