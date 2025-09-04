package com.example.mappers;

import com.example.dtos.shoppingList.ShoppingListRequest;
import com.example.dtos.shoppingList.ShoppingListResponse;
import com.example.entities.ShoppingEntity;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;

@Mapper
public interface ShoppingMapper {
    ShoppingMapper INSTANCE = Mappers.getMapper(ShoppingMapper.class);

    ShoppingListResponse toDTO(ShoppingEntity shoppingEntity);

    ShoppingEntity toEntity(ShoppingListRequest dto);
}
