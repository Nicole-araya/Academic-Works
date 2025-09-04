package com.example.mappers;

import com.example.dtos.recipes.RecipeRequest;
import com.example.dtos.recipes.RecipeResponse;
import com.example.entities.RecipesEntity;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.factory.Mappers;

@Mapper
public interface RecipeMapper {
    RecipeMapper INSTANCE = Mappers.getMapper(RecipeMapper.class);

    RecipeResponse toDTO(RecipesEntity entity);

    @Mapping(target = "id", ignore = true)
    RecipesEntity toEntity(RecipeRequest dto);
}
