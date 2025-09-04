package com.example.dtos.shoppingList;

public class ShoppingListDeleteRequest {
    private String shoppingPlanId;

    public ShoppingListDeleteRequest() {}

    public ShoppingListDeleteRequest(String shoppingPlanId) {
        this.shoppingPlanId = shoppingPlanId;
    }

    public String getShoppingPlanId() {
        return shoppingPlanId;
    }

    public void setShoppingPlanId(String shoppingPlanId) {
        this.shoppingPlanId = shoppingPlanId;
    }
}
