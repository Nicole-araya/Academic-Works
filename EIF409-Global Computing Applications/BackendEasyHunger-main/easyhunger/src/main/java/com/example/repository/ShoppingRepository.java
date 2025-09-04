package com.example.repository;

import com.example.entities.ShoppingEntity;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.data.mongodb.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface ShoppingRepository extends MongoRepository<ShoppingEntity, String> {
    @Query
    List<ShoppingEntity> findAllByUserId(String userId);
}
