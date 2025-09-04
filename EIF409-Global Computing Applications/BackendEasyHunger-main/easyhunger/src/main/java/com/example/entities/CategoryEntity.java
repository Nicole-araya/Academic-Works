package com.example.entities;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document("ExpirationCategory")
public class CategoryEntity {
    @Id
    private String id;

    private String name;
    private String measure;
    private int expiration;
    private String location;

    public CategoryEntity(String id, String name, String measure, int expiration, String location) {
        this.id = id;
        this.name = name;
        this.measure = measure;
        this.expiration = expiration;
        this.location = location;
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

    public String getMeasure() {
        return measure;
    }

    public void setMeasure(String measure) {
        this.measure = measure;
    }

    public int getExpiration() {
        return expiration;
    }

    public void setExpiration(int expiration) {
        this.expiration = expiration;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }
}
