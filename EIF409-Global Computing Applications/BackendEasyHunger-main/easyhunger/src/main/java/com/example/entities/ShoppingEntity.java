package com.example.entities;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document("ShoopingList")
public class ShoppingEntity {
    @Id
    private String id;

    private String shoppingPlan;
    private String userId;

    public ShoppingEntity(String id, String shoppingPlan, String userId) {
        this.id = id;
        this.shoppingPlan = shoppingPlan;
        this.userId = userId;
    }

    public String getId() {return id;}
    public String getShoppingPlan() {return shoppingPlan;}
    public String getUserId() {return userId;}

    public void setId(String id) {this.id = id;}
    public void setShoppingPlan(String shoppingPlan) {this.shoppingPlan = shoppingPlan;}
    public void setUserId(String userId) {this.userId = userId;}
}
