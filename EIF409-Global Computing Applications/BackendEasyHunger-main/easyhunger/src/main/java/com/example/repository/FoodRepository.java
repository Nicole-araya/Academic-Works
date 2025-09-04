package com.example.repository;

import com.example.entities.FoodEntity; // Ensure this class exists under this package or adjust the path
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.mongodb.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface FoodRepository extends MongoRepository<FoodEntity, String> {

    @Query
    Optional<FoodEntity> findById(String id);

    @Query
    void deleteById(String id);
}
