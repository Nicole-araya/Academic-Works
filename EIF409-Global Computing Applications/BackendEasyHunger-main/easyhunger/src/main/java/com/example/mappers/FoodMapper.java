package com.example.mappers;
import com.example.dtos.food.FoodResponse;
import com.example.dtos.food.FoodRequest;
import com.example.entities.FoodEntity;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.factory.Mappers;

@Mapper
public interface FoodMapper {

    FoodMapper INSTANCE = Mappers.getMapper(FoodMapper.class);


    FoodResponse toDTO(FoodEntity entity);

    @Mapping(target = "id", ignore = true)
    FoodEntity toEntity(FoodRequest dto);

}
