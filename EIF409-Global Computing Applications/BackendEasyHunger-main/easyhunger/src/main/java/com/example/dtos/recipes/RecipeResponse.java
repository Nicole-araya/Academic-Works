package com.example.dtos.recipes;

public class RecipeResponse {
    private String id;
    private String name;
    private String time;
    private String calories;
    private String ingredients;
    private String steps;
    private String difficulty;

    public RecipeResponse(String id, String name, String time, String calories, String ingredients, String steps, String difficulty) {
        this.id = id;
        this.name = name;
        this.time = time;
        this.calories = calories;
        this.ingredients = ingredients;
        this.steps = steps;
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

    public String getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(String difficulty) {
        this.difficulty = difficulty;
    }

    public RecipeResponse() {
    }
}

