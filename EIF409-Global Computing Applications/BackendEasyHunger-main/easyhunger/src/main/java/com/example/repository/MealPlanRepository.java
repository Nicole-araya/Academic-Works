package com.example.repository;

import com.example.entities.MealPlanEntity;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface MealPlanRepository  extends MongoRepository<MealPlanEntity, String> {

    MealPlanEntity findByUserId(String userId);
}
