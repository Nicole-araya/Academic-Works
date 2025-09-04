package com.example.mappers;

import com.example.dtos.category.CategoryResponse;
import com.example.entities.CategoryEntity;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.factory.Mappers;

@Mapper
public interface CategoryMapper {

    CategoryMapper INSTANCE = Mappers.getMapper(CategoryMapper.class);

    CategoryResponse toDTO(CategoryEntity entity);

    @Mapping(target = "id", ignore = true)
    CategoryEntity toEntity(CategoryResponse dto);
}
