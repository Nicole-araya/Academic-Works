package com.example.dtos.preload;

public class PreloadFoodResponse {
    private final String id;
    private final String name;
    private final String category;
    private final String typeQuantity;
    private final double price;

    public PreloadFoodResponse(String id, String name, String category, String typeQuantity, double price) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.typeQuantity = typeQuantity;
        this.price = price;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getCategory() {
        return category;
    }

    public String getTypeQuantity() {
        return typeQuantity;
    }

    public double getPrice() {
        return price;
    }
}
