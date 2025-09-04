package com.example.services;

import com.example.dtos.food.UpdateQuantityFoodRequest;
import com.example.dtos.shoppingList.ShoppingListDeleteRequest;
import com.example.dtos.shoppingList.ShoppingListRequest;
import com.example.dtos.shoppingList.ShoppingListResponse;
import com.example.dtos.shoppingList.ShoppingListUpdateRequest;
import com.example.dtos.user.UserIdRequest;
import com.example.entities.FoodEntity;
import com.example.entities.ShoppingEntity;
import com.example.mappers.ShoppingMapper;
import com.example.repository.ShoppingRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class ShoppingService {
    @Autowired
    private ShoppingRepository shoppingRepository;

    public List<ShoppingListResponse> obtenerShoppingListDelUsuario(UserIdRequest userIdRequest){
        List<ShoppingEntity> shoppingEntities = shoppingRepository.findAllByUserId(userIdRequest.getUserId());
        return shoppingEntities.stream().map(ShoppingMapper.INSTANCE::toDTO).collect(Collectors.toList());
    }

    public Boolean crearShopping (ShoppingListRequest request) {
        ShoppingEntity entity = ShoppingMapper.INSTANCE.toEntity(request);
        return shoppingRepository.save(entity) != null;
    }

    public Boolean editarShopping (ShoppingListUpdateRequest request) {
        ShoppingEntity entity = shoppingRepository.findById(request.getShoppingPlanId()).orElse(null);
        if (entity == null) {return false;}
        entity.setShoppingPlan(request.getShoppingPlan());
        shoppingRepository.save(entity);
        return true;
    }

    public boolean eliminarShoppingPlan (ShoppingListDeleteRequest request) {
        shoppingRepository.deleteById(request.getShoppingPlanId());
        return true;
    }
}
