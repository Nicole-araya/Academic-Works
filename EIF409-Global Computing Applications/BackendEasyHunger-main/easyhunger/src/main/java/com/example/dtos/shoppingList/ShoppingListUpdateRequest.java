package com.example.dtos.shoppingList;

public class ShoppingListUpdateRequest {
    private String shoppingPlanId;
    private String shoppingPlan;

    public ShoppingListUpdateRequest() {}

    public ShoppingListUpdateRequest(String shoppingPlanId, String shoppingPlan) {
        this.shoppingPlanId = shoppingPlanId;
        this.shoppingPlan = shoppingPlan;
    }

    public String getShoppingPlan() {
        return shoppingPlan;
    }

    public void setShoppingPlan(String shoppingPlan) {
        this.shoppingPlan = shoppingPlan;
    }

    public String getShoppingPlanId() {
        return shoppingPlanId;
    }

    public void setShoppingPlanId(String shoppingPlanId) {
        this.shoppingPlanId = shoppingPlanId;
    }
}
