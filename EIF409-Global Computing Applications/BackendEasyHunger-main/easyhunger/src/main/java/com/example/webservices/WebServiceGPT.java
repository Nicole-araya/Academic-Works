package com.example.webservices;

import com.example.dtos.food.FoodUserRequest;
import com.example.dtos.gpt.TranscripionRequest;
import com.example.dtos.user.UserIdRequest;
import com.example.services.GPTService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;

@RestController
@RequestMapping("${url.ia}")
public class WebServiceGPT {
    @Autowired
    GPTService gptService;

    @GetMapping("/getMealPlan")
    public String crearPlainMealPlan() throws IOException, InterruptedException {
        return gptService.generatePlainPlan();
    }
    @GetMapping("/getRecipe")
    public String crearPlainRecipe() throws IOException, InterruptedException {
        return gptService.generatePlainRecipes();
    }
    @GetMapping("/getShoppingList")
    public String crearPlainShoppingList() throws IOException, InterruptedException {
        return gptService.generatePlainShoppingList();
    }

    @PostMapping("/getCustomMealPlan")
    public String crearMealPlan(@RequestBody FoodUserRequest request) throws IOException, InterruptedException {
        return gptService.generateCustomPlan(request);
    }
    @PostMapping("/getCustomRecipe")
    public String crearRecipe(@RequestBody FoodUserRequest request) throws IOException, InterruptedException {
        return gptService.generateCustomRecipes(request);
    }
    @PostMapping("/getCustomShoppingList")
    public String crearShoppingList(@RequestBody FoodUserRequest request) throws IOException, InterruptedException {
        return gptService.generateCustomShoppingList(request);
    }

    @PostMapping("/postInventoryVoice")
    public String crearInventarioVoz(@RequestPart("audio")MultipartFile audio) throws IOException, InterruptedException {
        return gptService.inventoryByVoice(audio);
    }

    @PostMapping("/postInventoryText")
    public String crearInventarioText(@RequestBody TranscripionRequest request) throws IOException, InterruptedException {
        return gptService.generateFood(request.getText());
    }

}
