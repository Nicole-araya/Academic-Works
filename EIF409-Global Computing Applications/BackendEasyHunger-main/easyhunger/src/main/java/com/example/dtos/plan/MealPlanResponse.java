package com.example.dtos.plan;

public class MealPlanResponse {
    private final String id;
    private final String mealPlan;
    private final String userId;

    public MealPlanResponse(String id, String mealPlan, String userId) {
        this.id = id;
        this.mealPlan = mealPlan;
        this.userId = userId;
    }
    public String getId() {
        return id;
    }
    public String getMealPlan() {
        return mealPlan;
    }
    public String getUserId() {
        return userId;
    }
}
