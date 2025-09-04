package com.example.mappers;

import com.example.dtos.plan.MealPlanRequest;
import com.example.dtos.plan.MealPlanResponse;
import com.example.entities.MealPlanEntity;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;
import org.mapstruct.factory.Mappers;

@Mapper
public interface MealPlanMapper {
    MealPlanMapper INSTANCE = Mappers.getMapper(MealPlanMapper.class);

    MealPlanResponse toDTO(MealPlanEntity entity);

    @Mapping(target = "id", ignore = true)
    MealPlanEntity toEntity(MealPlanRequest dto);
}
