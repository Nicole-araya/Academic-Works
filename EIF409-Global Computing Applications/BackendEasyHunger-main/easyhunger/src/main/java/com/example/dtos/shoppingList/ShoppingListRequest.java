package com.example.dtos.shoppingList;

public class ShoppingListRequest {
    private final String shoppingPlan;
    private final String userId;

    public ShoppingListRequest() {
        this.shoppingPlan = "";
        this.userId = "";
    }

    public String getShoppingPlan() {
        return shoppingPlan;
    }
    public String getUserId() {
        return userId;
    }
}
