package com.example.dtos.preload;

import java.util.List;

public class PreloadFoodRequest {
    private final List<String> foodsIds;

    public PreloadFoodRequest(List<String> foodsIds) {
        this.foodsIds = foodsIds;
    }

    public PreloadFoodRequest() {
        this.foodsIds = null;
    }

    public List<String> getFoodsIds() {
        return foodsIds;
    }
}
