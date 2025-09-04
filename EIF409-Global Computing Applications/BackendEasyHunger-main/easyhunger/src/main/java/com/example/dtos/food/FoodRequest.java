package com.example.dtos.food;

public class FoodRequest{
    private final String name;
    private final String category;
    private final String typeQuantity;
    private final int quantity;
    private final String expirationDate;
    private final double price;
    private final String userId;

    public FoodRequest( String name, String category, String typeQuantity, int quantity, String expirationDate, double price, String userId){
        this.name = name;
        this.category = category;
        this.typeQuantity = typeQuantity;
        this.quantity = quantity;
        this.expirationDate = expirationDate;
        this.price = price;
        this.userId = userId;
    }

    @Override
    public String toString() {
        return String.format("%s - %s - %s - %s - %s", name, typeQuantity, quantity, expirationDate, price);
    }

    public String getCategory() {
        return category;
    }

    public String getName() {
        return name;
    }

    public String getTypeQuantity() {
        return typeQuantity;
    }

    public int getQuantity() {
        return quantity;
    }

    public String getExpirationDate() {
        return expirationDate;
    }

    public double getPrice() {
        return price;
    }

    public String getUserId() {return userId;}
}


