package com.example.mappers;

import com.example.dtos.user.LoginResponse;
import com.example.dtos.user.RegisterRequest;
import com.example.entities.UserEntity;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;

@Mapper
public interface UserMapper {
    UserMapper INSTACE = Mappers.getMapper(UserMapper.class);

    LoginResponse toDto(UserEntity user);

    UserEntity toEntity(RegisterRequest dto);

}
