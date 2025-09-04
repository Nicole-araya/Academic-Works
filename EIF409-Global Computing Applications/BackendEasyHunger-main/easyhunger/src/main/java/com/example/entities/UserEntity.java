package com.example.entities;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

import java.util.List;

@Document("User")
public class UserEntity {
    @Id
    private String id;

    private String name;
    private String email;
    private String password;

    private List<String> foodIds; //INVENTARIO

    public UserEntity(String id, String name, String email, String password, List<String> foodIds) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.password = password;
        this.foodIds = foodIds;
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

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public List<String> getFoodIds() {
        return foodIds;
    }

    public void setFoodIds(List<String> foodIds) {
        this.foodIds = foodIds;
    }
}
