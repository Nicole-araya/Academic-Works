package com.example.services;

import com.example.dtos.recipes.RecipeRequest;
import com.example.dtos.recipes.RecipeResponse;
import com.example.dtos.recipes.RecipeUserRequest;
import com.example.entities.RecipesEntity;
import com.example.mappers.RecipeMapper;
import com.example.repository.RecipeRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class RecipeService {
    @Autowired
    private RecipeRepository recipeRepository;

    public RecipeResponse obtenerRecetaPorId(String id) {
        RecipesEntity receta = recipeRepository.findById(id).orElse(null);
        return RecipeMapper.INSTANCE.toDTO(receta);
    }

    public List<RecipeResponse> obtenerRecetas (RecipeUserRequest request) {
        List<RecipesEntity> recetas = recipeRepository.findAllByUserId(request.getUserId());
        return recetas.stream().map(RecipeMapper.INSTANCE::toDTO).collect(Collectors.toList());
    }

    public Boolean crearReceta (RecipeRequest request) {
        RecipesEntity receta = RecipeMapper.INSTANCE.toEntity(request);
        return recipeRepository.save(receta) != null;
    }

    public Boolean eliminarReceta (String id) {
        recipeRepository.deleteById(id);
        return true;
    }

}
