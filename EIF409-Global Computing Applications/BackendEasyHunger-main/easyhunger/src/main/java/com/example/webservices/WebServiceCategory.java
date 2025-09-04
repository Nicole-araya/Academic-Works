package com.example.webservices;

import com.example.dtos.category.CategoryResponse;
import com.example.services.CategoryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("${url.category}")
public class WebServiceCategory {

    @Autowired
    private CategoryService categoryService;

    @GetMapping("/getcategories")
    public List<CategoryResponse> obtenerCategorias() {
        return categoryService.obtenerCategorias();
    }

}
