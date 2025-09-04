package com.example.entities;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document("MealPlan")
public class MealPlanEntity {
    @Id
    private String id;
    private String mealPlan;
    private String userId;

    public MealPlanEntity(String id, String mealPlan, String userId) {
        this.id = id;
        this.mealPlan = mealPlan;
        this.userId = userId;
    }

    public String getId() {return id;}
    public String getMealPlan() {return mealPlan;}
    public String getUserId() {return userId;}
    public void setId(String id) {this.id = id;}
    public void setMealPlan(String mealPlan) {this.mealPlan = mealPlan;}
    public void setUserId(String userId) {this.userId = userId;}
}
