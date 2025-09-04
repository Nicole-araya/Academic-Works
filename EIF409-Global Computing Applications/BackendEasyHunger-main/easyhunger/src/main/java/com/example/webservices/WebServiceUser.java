package com.example.webservices;

import com.example.dtos.user.LoginRequest;
import com.example.dtos.user.LoginResponse;
import com.example.dtos.user.RegisterRequest;
import com.example.services.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("${url.user}")
public class WebServiceUser {
    @Autowired
    private UserService userService;

    @PostMapping("/login")
    public LoginResponse login(@RequestBody LoginRequest request) {
        return userService.login(request);
    }
    @PostMapping("/register")
    public LoginResponse register(@RequestBody RegisterRequest request) {
        return userService.register(request);
    }

}
