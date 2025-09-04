package com.example.repository;

import com.example.entities.PreloadFoodEntity;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PreloadFoodRepository extends MongoRepository<PreloadFoodEntity, String> {
}
