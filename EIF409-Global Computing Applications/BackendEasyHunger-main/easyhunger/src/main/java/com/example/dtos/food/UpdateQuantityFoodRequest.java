package com.example.dtos.food;

public class UpdateQuantityFoodRequest{
    private final String id;
    private final int quantity;

    public UpdateQuantityFoodRequest() {
        this.id = "";
        this.quantity = 0;
    }

    public UpdateQuantityFoodRequest(String id, int quantity) {
        this.id = id;
        this.quantity = quantity;
    }

    public String getId() {
        return id;
    }

    public int getQuantity() {
        return quantity;
    }
}
