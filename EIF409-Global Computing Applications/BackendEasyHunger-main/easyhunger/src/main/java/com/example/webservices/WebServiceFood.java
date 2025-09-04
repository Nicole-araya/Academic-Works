package com.example.webservices;

import com.example.dtos.food.*;
import com.example.services.FoodService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("${url.food}")
public class WebServiceFood {
    @Autowired
    private FoodService foodService;

    @PostMapping("/getfoods")
    public List<FoodResponse> obtenerProductos(@RequestBody FoodUserRequest request) {
        return foodService.obtenerTodosLosProductos(request);
    }

    @PostMapping("/getfood")
    public FoodResponse obtenerProducto(@RequestBody FoodIdRequest request) {
        return foodService.obtenerProductoPorId(request.getId());
    }

    @PostMapping("/postfood")
    public Boolean crearProducto(@RequestBody FoodRequest producto) {
        return foodService.crearProducto(producto);
    }

    @PutMapping("/updatefood")
    public Boolean editarProducto(@RequestBody UpdatedFoodRequest producto) {
        return foodService.editarProducto(producto);
    }

    @PutMapping("/updatequantity")
    public Boolean editarProducto(@RequestBody UpdateQuantityFoodRequest producto) {
        return foodService.editarCantidadProducto(producto);
    }

    @DeleteMapping("/deletefood")
    public Boolean eliminarProducto(@RequestBody FoodIdRequest producto) {
        return foodService.eliminarProducto(producto);
    }
}
