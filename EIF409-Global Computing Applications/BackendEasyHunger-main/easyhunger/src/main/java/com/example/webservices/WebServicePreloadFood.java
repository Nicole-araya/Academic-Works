package com.example.webservices;

import com.example.dtos.preload.PreloadFoodNameResponse;
import com.example.dtos.preload.PreloadFoodRequest;
import com.example.dtos.preload.PreloadFoodResponse;
import com.example.services.PreloadFoodService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("${url.preload}")
public class WebServicePreloadFood {
    @Autowired
    private PreloadFoodService preloadFoodService;

    @GetMapping("/getNamespreloadFoods")
    public List<PreloadFoodNameResponse> obtenerNamesPreloadFoods() {
        return preloadFoodService.obtenerNamesPreloadFoods();
    }

    @PostMapping("/getpreloadFoodsIds")
    public List<PreloadFoodResponse> obtenerPreloadFoods(@RequestBody PreloadFoodRequest request) {
        return preloadFoodService.obtenerPreloadFoodsIds(request);
    }
}
