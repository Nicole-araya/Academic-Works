package com.example.webservices;

import com.example.dtos.food.FoodIdRequest;
import com.example.dtos.shoppingList.ShoppingListDeleteRequest;
import com.example.dtos.shoppingList.ShoppingListRequest;
import com.example.dtos.shoppingList.ShoppingListResponse;
import com.example.dtos.shoppingList.ShoppingListUpdateRequest;
import com.example.dtos.user.UserIdRequest;
import com.example.services.ShoppingService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("${url.shopping}")
public class WebServiceShopping {
    @Autowired
    private ShoppingService shoppingService;

    @PostMapping("/getShoppingListOfUser")
    public List<ShoppingListResponse> obtenerShoppingListDelUsuario(@RequestBody UserIdRequest userId) {return shoppingService.obtenerShoppingListDelUsuario(userId);}

    @PostMapping("/postShoppingList")
    public Boolean guardarShoppingList(@RequestBody ShoppingListRequest request) {
        return shoppingService.crearShopping(request);
    }

    @PutMapping("/updateShoppingList")
    public Boolean guardarShoppingList(@RequestBody ShoppingListUpdateRequest request) {
        return shoppingService.editarShopping(request);
    }

    @DeleteMapping("/deleteShoppingList")
    public Boolean eliminarShoppingList(@RequestBody ShoppingListDeleteRequest request) {
        return shoppingService.eliminarShoppingPlan(request);
    }
}
//:)