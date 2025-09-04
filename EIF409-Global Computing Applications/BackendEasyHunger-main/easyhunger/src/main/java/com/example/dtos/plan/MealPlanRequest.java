package com.example.dtos.plan;

public class MealPlanRequest {
    private final String mealPlan;
    private final String userId;

    public MealPlanRequest(String mealPlan, String userId) {
        this.mealPlan = mealPlan;
        this.userId = userId;
    }

    public MealPlanRequest() {
        this.mealPlan = "";
        this.userId = "";
    }

    public String getMealPlan() {
        return mealPlan;
    }

    public String getUserId() {
        return userId;
    }
}
