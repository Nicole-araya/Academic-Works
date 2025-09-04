package com.example.webservices;

import com.example.dtos.plan.MealPlanIdRequest;
import com.example.dtos.plan.MealPlanRequest;
import com.example.dtos.plan.MealPlanResponse;
import com.example.services.MealPlanService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("${url.mealPlan}")
public class WebServiceMealPlan {
    @Autowired
    MealPlanService mealPlanService;

    @PostMapping("/getMealPlan")
    public MealPlanResponse obtenerMealPlan(@RequestBody MealPlanIdRequest request) {
        return mealPlanService.obtenerMealPlanPorId(request.getUserId());
    }

    @PostMapping("/postMealPlan")
    public Boolean guardarMealPlan(@RequestBody MealPlanRequest request) {
        return mealPlanService.guardarMealPlan(request);
    }

    @DeleteMapping("/deleteMealPlan")
    public Boolean eliminarMealPlan(@RequestBody MealPlanIdRequest request) {
        return mealPlanService.eliminarMeal(request);
    }
}
