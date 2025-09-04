package com.example.dtos.recipes;

public class RecipeRequest {
    private final String name;
    private final String time;
    private final String calories;
    private final String ingredients;
    private final String steps;
    private String difficulty;
    private String userId;

    public RecipeRequest(String name, String time, String calories, String ingredients, String steps, String difficulty, String userId  ) {
        this.name = name;
        this.time = time;
        this.calories = calories;
        this.ingredients = ingredients;
        this.steps = steps;
        this.difficulty = difficulty;
        this.userId = userId;
    }

    public String getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(String difficulty) {
        this.difficulty = difficulty;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public String getSteps() {
        return steps;
    }

    public String getIngredients() {
        return ingredients;
    }

    public String getCalories() {
        return calories;
    }

    public String getTime() {
        return time;
    }

    public String getName() {
        return name;
    }
}

