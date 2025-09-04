package com.example.entities;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document("Recipes")
public class RecipesEntity {
    @Id
    private String id;

    private String name;
    private String time;
    private String calories;
    private String ingredients;
    private String steps;
    private String userId;
    private String difficulty;

    public RecipesEntity(String id, String name, String time, String calories, String ingredients, String steps, String userId, String difficulty) {
        this.id = id;
        this.name = name;
        this.time = time;
        this.calories = calories;
        this.ingredients = ingredients;
        this.steps = steps;
        this.userId = userId;
        this.difficulty = difficulty;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getTime() {
        return time;
    }

    public void setTime(String time) {
        this.time = time;
    }

    public String getCalories() {
        return calories;
    }

    public void setCalories(String calories) {
        this.calories = calories;
    }

    public String getIngredients() {
        return ingredients;
    }

    public void setIngredients(String ingredients) {
        this.ingredients = ingredients;
    }

    public String getSteps() {
        return steps;
    }

    public void setSteps(String steps) {
        this.steps = steps;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public String getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(String difficulty) {
        this.difficulty = difficulty;
    }
}
