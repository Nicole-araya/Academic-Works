package com.example.entities;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;


@Document("Foods")
public class FoodEntity {
    @Id
    private String id;

    private String name;
    private String category;
    private String typeQuantity;
    private int quantity;
    private String expirationDate;
    private double price;

    public FoodEntity(String id, String name, String category, String typeQuantity, int quantity, String expirationDate, double price) {
        this.id = id;
        this.name = name;
        this.category = category;
        this.typeQuantity = typeQuantity;
        this.quantity = quantity;
        this.expirationDate = expirationDate;
        this.price = price;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
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

    public String getTypeQuantity() {
        return typeQuantity;
    }

    public void setTypeQuantity(String typeQuantity) {
        this.typeQuantity = typeQuantity;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public String getExpirationDate() {
        return expirationDate;
    }

    public void setExpirationDate(String expirationDate) {
        this.expirationDate = expirationDate;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}
