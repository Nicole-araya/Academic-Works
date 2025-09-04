package com.example;

import com.example.services.GPTService;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.data.mongodb.repository.config.EnableMongoRepositories;

@SpringBootApplication
@EnableMongoRepositories
public class EasyHungerApplication implements CommandLineRunner {

	public static void main(String[] args) {
		SpringApplication.run(EasyHungerApplication.class, args);
	}

    @Override
	public void run(String... args) throws Exception {
		GPTService service = new GPTService();
		service.generatePlainRecipes();
	}

}
