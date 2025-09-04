package com.example.dtos.shoppingList;

public class ShoppingListResponse {
    private String id;
    private String shoppingPlan;


    public ShoppingListResponse(String id, String shoppingPlan) {
        this.id = id;
        this.shoppingPlan = shoppingPlan;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getShoppingPlan() {
        return shoppingPlan;
    }

    public void setShoppingPlan(String shoppingPlan) {
        this.shoppingPlan = shoppingPlan;
    }
}
