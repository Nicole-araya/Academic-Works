package com.example.services;

import com.example.dtos.preload.PreloadFoodNameResponse;
import com.example.dtos.preload.PreloadFoodRequest;
import com.example.dtos.preload.PreloadFoodResponse;
import com.example.entities.PreloadFoodEntity;
import com.example.mappers.PreloadFoodMapper;
import com.example.repository.PreloadFoodRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class PreloadFoodService {
    @Autowired
    private PreloadFoodRepository preloadFoodRepository;

    public List<PreloadFoodNameResponse> obtenerNamesPreloadFoods () {
        List<PreloadFoodEntity> recetas = preloadFoodRepository.findAll();
        return recetas.stream().map(PreloadFoodMapper.INSTANCE::toNameDTO).collect(Collectors.toList());
    }

    public List<PreloadFoodResponse> obtenerPreloadFoodsIds (PreloadFoodRequest request) {
        List<PreloadFoodEntity> recetas = preloadFoodRepository.findAllById(request.getFoodsIds());
        return recetas.stream().map(PreloadFoodMapper.INSTANCE::toDTO).collect(Collectors.toList());
    }
}
