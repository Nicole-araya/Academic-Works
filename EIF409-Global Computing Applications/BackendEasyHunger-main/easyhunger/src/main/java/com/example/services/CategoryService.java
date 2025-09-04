package com.example.services;

import com.example.dtos.category.CategoryResponse;
import com.example.entities.CategoryEntity;
import com.example.mappers.CategoryMapper;
import com.example.repository.CategoryRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class CategoryService {

    @Autowired
    private CategoryRepository categoryRepository;

    public List<CategoryResponse> obtenerCategorias() {
        List<CategoryEntity> categorias = categoryRepository.findAll();
        return categorias.stream().map(CategoryMapper.INSTANCE::toDTO).collect(Collectors.toList());
    }

}
