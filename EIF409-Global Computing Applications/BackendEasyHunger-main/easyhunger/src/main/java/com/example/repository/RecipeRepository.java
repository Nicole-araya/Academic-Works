package com.example.repository;

import com.example.entities.RecipesEntity;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.mongodb.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface RecipeRepository extends MongoRepository<RecipesEntity, String> {
    @Query
    void deleteById(String id);

    List<RecipesEntity> findAllByUserId(String userId);
}
