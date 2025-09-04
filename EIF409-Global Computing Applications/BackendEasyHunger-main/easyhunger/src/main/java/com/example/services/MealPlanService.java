package com.example.services;


import com.example.dtos.plan.MealPlanIdRequest;
import com.example.dtos.plan.MealPlanRequest;
import com.example.dtos.plan.MealPlanResponse;
import com.example.entities.MealPlanEntity;
import com.example.mappers.MealPlanMapper;
import com.example.repository.MealPlanRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class MealPlanService {
    @Autowired
    MealPlanRepository mealPlanRepository;

    public MealPlanResponse obtenerMealPlanPorId(String userId) {
        MealPlanEntity meal = mealPlanRepository.findByUserId(userId);
        System.out.println(meal.getMealPlan());
        return MealPlanMapper.INSTANCE.toDTO(meal);
    }

    public Boolean guardarMealPlan (MealPlanRequest request) {
        MealPlanEntity meal = MealPlanMapper.INSTANCE.toEntity(request);
        return mealPlanRepository.save(meal) != null;
    }

    public Boolean eliminarMeal (MealPlanIdRequest request) {
        mealPlanRepository.deleteById(request.getUserId());
        return true;
    }

}
