package com.example.dtos.category;

public class CategoryResponse {
    private final String name;
    private final String measure;
    private final int expiration;
    private final String location;

    public CategoryResponse(String name, String measure, int expiration, String location) {
        this.name = name;
        this.measure = measure;
        this.expiration = expiration;
        this.location = location;
    }

    public String getName() {
        return name;
    }

    public String getMeasure() {
        return measure;
    }

    public int getExpiration() {
        return expiration;
    }

    public String getLocation() {return location;}
}
