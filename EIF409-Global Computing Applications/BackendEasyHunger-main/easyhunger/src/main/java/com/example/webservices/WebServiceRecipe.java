package com.example.webservices;

import com.example.dtos.recipes.RecipeIdRequest;
import com.example.dtos.recipes.RecipeRequest;
import com.example.dtos.recipes.RecipeResponse;
import com.example.dtos.recipes.RecipeUserRequest;
import com.example.services.RecipeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("${url.recipe}")
public class WebServiceRecipe {
    @Autowired
    private RecipeService recipeService;

    @PostMapping("/getrecipes")
    public List<RecipeResponse> obtenerRecetas(@RequestBody RecipeUserRequest request) {
        return recipeService.obtenerRecetas(request);
    }

    @PostMapping("/getrecipe")
    public RecipeResponse obtenerReceta(@RequestBody RecipeIdRequest request) {
        return recipeService.obtenerRecetaPorId(request.getId());
    }
    @PostMapping("/postrecipe")
    public Boolean crearReceta(@RequestBody RecipeRequest request) {
        return recipeService.crearReceta(request);
    }

    @DeleteMapping("/deleterecipe")
    public Boolean eliminarReceta(@RequestBody RecipeIdRequest request) {
        return recipeService.eliminarReceta(request.getId());
    }
}
