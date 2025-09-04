package com.example.mappers;

import com.example.dtos.preload.PreloadFoodNameResponse;
import com.example.dtos.preload.PreloadFoodResponse;
import com.example.entities.PreloadFoodEntity;
import org.mapstruct.Mapper;
import org.mapstruct.factory.Mappers;

@Mapper
public interface PreloadFoodMapper {
    PreloadFoodMapper INSTANCE = Mappers.getMapper(PreloadFoodMapper.class);

    PreloadFoodResponse toDTO(PreloadFoodEntity entity);

    PreloadFoodNameResponse toNameDTO(PreloadFoodEntity entity);
}
