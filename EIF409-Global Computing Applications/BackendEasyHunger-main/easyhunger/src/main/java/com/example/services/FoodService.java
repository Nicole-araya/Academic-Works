package com.example.services;

import com.example.dtos.food.*;
import com.example.entities.FoodEntity;
import com.example.entities.UserEntity;
import com.example.mappers.FoodMapper;
import com.example.repository.FoodRepository;
import com.example.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;


@Service
public class FoodService {
    @Autowired
    private FoodRepository foodRepository;
    @Autowired
    private UserRepository userRepository;

    public FoodResponse obtenerProductoPorId(String id) {
        FoodEntity producto = foodRepository.findById(id).orElse(null);
        return FoodMapper.INSTANCE.toDTO(producto);
    }

    public List<FoodResponse> obtenerTodosLosProductos (FoodUserRequest request) {
        UserEntity user = userRepository.findById(request.getUserId()).orElse(null);
        List<FoodEntity> productos = foodRepository.findAllById(user.getFoodIds());
        return productos.stream().map(FoodMapper.INSTANCE::toDTO).collect(Collectors.toList());
    }

    public Boolean crearProducto(FoodRequest request) {

        FoodEntity productoEntity = FoodMapper.INSTANCE.toEntity(request);
        productoEntity = foodRepository.save(productoEntity);

        // usuario
        UserEntity user = userRepository.findById(request.getUserId()).orElse(null);
        if (user == null) {
            return false; // O lanza excepción si prefieres
        }

        //Agregar el id de la comida al usuario
        List<String> foodIds = user.getFoodIds();
        if (foodIds == null) {
            foodIds = new ArrayList<>();
        }
        foodIds.add(productoEntity.getId());
        user.setFoodIds(foodIds);

        //Guardar usuario actualizado
        userRepository.save(user);

        return true;
    }

    public Boolean editarProducto (UpdatedFoodRequest request) {

        FoodEntity productoEntity = foodRepository.findById(request.getId()).orElse(null);
        if (productoEntity == null) {return false;}

        productoEntity.setName(request.getName());
        productoEntity.setCategory(request.getCategory());
        productoEntity.setTypeQuantity(request.getTypeQuantity());
        productoEntity.setQuantity(request.getQuantity());
        productoEntity.setExpirationDate(request.getExpirationDate());
        productoEntity.setPrice(request.getPrice());

        foodRepository.save(productoEntity);
        return true;
    }

    public Boolean editarCantidadProducto (UpdateQuantityFoodRequest request) {
        FoodEntity productoEntity = foodRepository.findById(request.getId()).orElse(null);
        if (productoEntity == null) {return false;}
        productoEntity.setQuantity(request.getQuantity());
        foodRepository.save(productoEntity);
        return true;
    }

    public Boolean eliminarProducto (FoodIdRequest request) {
        foodRepository.deleteById(request.getId());

        //Horrible si, ganas no
        List<UserEntity> usuarios = userRepository.findAll();
        for (UserEntity user : usuarios) {
            List<String> foodIds = user.getFoodIds();
            if (foodIds != null && foodIds.remove(request.getId())) {
                user.setFoodIds(foodIds);
                userRepository.save(user);
            }
        }
        return true;
    }
}
