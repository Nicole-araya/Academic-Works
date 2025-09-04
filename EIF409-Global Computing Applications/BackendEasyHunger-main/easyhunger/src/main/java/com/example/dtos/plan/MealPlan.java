package com.example.dtos.plan;

public class MealPlan {
    FoodTimes monday;
    FoodTimes tuesday;
    FoodTimes wednesday;
    FoodTimes thursday;
    FoodTimes friday;
    FoodTimes saturday;
    FoodTimes sunday;

    public FoodTimes getMonday() {
        return monday;
    }

    public void setMonday(FoodTimes monday) {
        this.monday = monday;
    }

    public FoodTimes getTuesday() {
        return tuesday;
    }

    public void setTuesday(FoodTimes tuesday) {
        this.tuesday = tuesday;
    }

    public FoodTimes getWednesday() {
        return wednesday;
    }

    public void setWednesday(FoodTimes wednesday) {
        this.wednesday = wednesday;
    }

    public FoodTimes getThursday() {
        return thursday;
    }

    public void setThursday(FoodTimes thursday) {
        this.thursday = thursday;
    }

    public FoodTimes getFriday() {
        return friday;
    }

    public void setFriday(FoodTimes friday) {
        this.friday = friday;
    }

    public FoodTimes getSaturday() {
        return saturday;
    }

    public void setSaturday(FoodTimes saturday) {
        this.saturday = saturday;
    }

    public FoodTimes getSunday() {
        return sunday;
    }

    public void setSunday(FoodTimes sunday) {
        this.sunday = sunday;
    }

    public MealPlan(FoodTimes monday, FoodTimes tuesday, FoodTimes thursday, FoodTimes friday, FoodTimes saturday, FoodTimes sunday, FoodTimes wednesday) {
        this.monday = monday;
        this.tuesday = tuesday;
        this.thursday = thursday;
        this.friday = friday;
        this.saturday = saturday;
        this.sunday = sunday;
        this.wednesday = wednesday;
    }

    public MealPlan() {
    }
}
