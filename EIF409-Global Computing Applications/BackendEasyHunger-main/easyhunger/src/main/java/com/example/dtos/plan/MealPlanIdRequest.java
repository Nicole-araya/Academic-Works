package com.example.dtos.plan;

public class MealPlanIdRequest {
    
    private final String userId;
    public MealPlanIdRequest(String userId) {
        this.userId = userId;
    }
    public MealPlanIdRequest() {
        this.userId = "";
    }
    public String getUserId() {
        return userId;
    }
}
