package com.example.services;

import com.example.dtos.user.LoginRequest;
import com.example.dtos.user.LoginResponse;
import com.example.dtos.user.RegisterRequest;
import com.example.entities.UserEntity;
import com.example.mappers.UserMapper;
import com.example.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {
    @Autowired
    private UserRepository userRepository;

    public LoginResponse login(LoginRequest loginRequest) {
        UserEntity user = userRepository.findByEmailAndPassword(
                loginRequest.getEmail(),
                loginRequest.getPassword()
        );
        if (user == null) {
            return null;
        }
        return UserMapper.INSTACE.toDto(user);
    }

    public LoginResponse register(RegisterRequest request) {
        UserEntity user = UserMapper.INSTACE.toEntity(request);
        userRepository.save(user);
        return UserMapper.INSTACE.toDto(user);
    }

}
