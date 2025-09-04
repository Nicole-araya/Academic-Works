package com.example.services;

import com.example.dtos.food.FoodResponse;
import com.example.dtos.food.FoodUserRequest;
import com.example.dtos.gpt.ChatMessage;
import com.example.dtos.gpt.OpenAIChatRequest;
import com.example.dtos.gpt.OpenAIChatResponse;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

@Service
public class GPTService {

    private final String apiKey = System.getenv("KEY");

    @Autowired
    FoodService foodService;

    public String generatePlainPlan() throws IOException, InterruptedException {
        String prompt = "Genera un plan de comidas como un JSON puro y valido,"+
                "sin explicaciones, sin comillas y sin encerrarlo en bloques de código como ```json."+
                "Sigue la siguiente estructura:"+
                "{monday: {breakfast, lunch, dinner}, tuesday: {breakfast, lunch, dinner}, "+
                "wednesday: {breakfast, lunch, dinner}, thursday: {breakfast, lunch, dinner}, "+
                "friday: {breakfast, lunch, dinner}, saturday: {breakfast, lunch, dinner}, "+
                "sunday: {breakfast, lunch, dinner}}. "+
                "Llena cada comida con una opción saludable y equilibrada, asegurándote de variar los ingredientes"+
                "a lo largo de la semana. Hazlo en un string.";

        ChatMessage message = new ChatMessage("user", prompt);
        List<ChatMessage> messages = new ArrayList<>();
        messages.add(message);
        OpenAIChatRequest openRequest = new OpenAIChatRequest("gpt-4.1-nano", messages);

        String body = openRequest.toString();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/chat/completions"))
                .headers("Content-Type", "application/json")
                .headers("Authorization", "Bearer "+apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(body))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response =  client.send(request, HttpResponse.BodyHandlers.ofString());

        ObjectMapper objectMapper = new ObjectMapper();

        OpenAIChatResponse openAIResponse = objectMapper.readValue(response.body(), OpenAIChatResponse.class);
        String modelMessage = openAIResponse.getChoices().getFirst().getMessage().getContent();

        return modelMessage.trim();
    }

    public String generatePlainShoppingList() throws IOException, InterruptedException {
        String prompt = "Genera una lista de compras quincenal para una persona como un JSON valido y puro,"+
                "sin explicaciones, sin comillas y sin encerrarlo en bloques de código como ```json."+
                "Sigue la siguiente estructura:"+
                "{\\\"lista\\\": \\\"producto:cantidad\\n\\\"}" +
                "Basate en producto-cantidad en el siguiente ejemplo:"+
                "manzana:5\\npera:2\\nleche:1"+
                "Asegúrate de que el valor de lista sea un string"+
                "Llena cada producto con una opción saludable y equilibrada, asegurándote de variar los ingredientes.";

        ChatMessage message = new ChatMessage("user", prompt);
        List<ChatMessage> messages = new ArrayList<>();
        messages.add(message);
        OpenAIChatRequest openRequest = new OpenAIChatRequest("gpt-4.1-nano", messages);

        String body = openRequest.toString();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/chat/completions"))
                .headers("Content-Type", "application/json")
                .headers("Authorization", "Bearer "+apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(body))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response =  client.send(request, HttpResponse.BodyHandlers.ofString());

        ObjectMapper objectMapper = new ObjectMapper();

        OpenAIChatResponse openAIResponse = objectMapper.readValue(response.body(), OpenAIChatResponse.class);
        String modelMessage = openAIResponse.getChoices().getFirst().getMessage().getContent();

        return modelMessage.trim();
    }

    public String generatePlainRecipes() throws IOException, InterruptedException {
        String prompt = "Genera una receta como un JSON puro y valido,"+
                "sin explicaciones, sin comillas y sin encerrarlo en bloques de código como ```json."+
                "Sigue la siguiente estructura:"+
                "{calories,ingredients,name,steps,time,difficulty}. No respondas listas, dame las respuestas como strings"+
                "Haz una receta saludable y equilibrada. Hazlo en un string.";

        ChatMessage message = new ChatMessage("user", prompt);
        List<ChatMessage> messages = new ArrayList<>();
        messages.add(message);
        OpenAIChatRequest openRequest = new OpenAIChatRequest("gpt-4.1-nano", messages);

        String body = openRequest.toString();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/chat/completions"))
                .headers("Content-Type", "application/json")
                .headers("Authorization", "Bearer " + apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(body))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

        ObjectMapper objectMapper = new ObjectMapper();

        OpenAIChatResponse openAIResponse = objectMapper.readValue(response.body(), OpenAIChatResponse.class);
        String modelMessage = openAIResponse.getChoices().getFirst().getMessage().getContent();

        return modelMessage.trim();
    }

    public String generateFood(String transcription) throws IOException, InterruptedException {
        String prompt = "A partir de la siguiente información: " + transcription +
                ", genera únicamente un JSON valido (sin explicaciones, sin comillas alrededor de las claves, sin bloques de código como ```json). " +
                "El JSON debe seguir esta estructura exacta: "+
                "{\\\"foods\\\": [{name, category, typeQuantity, quantity, expirationDate, price}]}. " +
                "Si algún campo está ausente o no se puede determinar claramente, usa 0 para valores numéricos y \\\" \\\" (cadena vacía) para texto. " +
                "Ignora cualquier elemento que no sea un alimento o producto comestible, no escribiendo nada en el json de esa entrada. "+
                "Si no se detecta ningún alimento o producto comestible, devuelve {\\\"foods\\\": []}";

        ChatMessage message = new ChatMessage("user", prompt);
        List<ChatMessage> messages = new ArrayList<>();
        messages.add(message);
        OpenAIChatRequest openRequest = new OpenAIChatRequest("gpt-4.1-nano", messages);

        String body = openRequest.toString();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/chat/completions"))
                .headers("Content-Type", "application/json")
                .headers("Authorization", "Bearer "+apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(body))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response =  client.send(request, HttpResponse.BodyHandlers.ofString());

        ObjectMapper objectMapper = new ObjectMapper();

        OpenAIChatResponse openAIResponse = objectMapper.readValue(response.body(), OpenAIChatResponse.class);
        String modelMessage = openAIResponse.getChoices().getFirst().getMessage().getContent();

        return modelMessage.trim();
    }

    public String inventoryByVoice(MultipartFile audio) throws IOException, InterruptedException {
        String boundary = "----OpenAIBoundary";
        String LINE_FEED = "\r\n";

        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        OutputStreamWriter writer = new OutputStreamWriter(baos, StandardCharsets.UTF_8);

        // Escribe la parte del archivo
        writer.append("--").append(boundary).append(LINE_FEED);
        writer.append("Content-Disposition: form-data; name=\"file\"; filename=\"")
                .append(audio.getOriginalFilename()).append("\"").append(LINE_FEED);
        writer.append("Content-Type: ").append(audio.getContentType()).append(LINE_FEED);
        writer.append(LINE_FEED);
        writer.flush();
        baos.write(audio.getBytes());
        writer.append(LINE_FEED);
        writer.flush();

        // Escribe el modelo a utilizar
        writer.append("--").append(boundary).append(LINE_FEED);
        writer.append("Content-Disposition: form-data; name=\"model\"").append(LINE_FEED);
        writer.append(LINE_FEED);
        writer.append("gpt-4o-mini-transcribe").append(LINE_FEED);
        writer.flush();

        // Finaliza el body
        writer.append("--").append(boundary).append("--").append(LINE_FEED);
        writer.close();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/audio/transcriptions"))
                .header("Authorization", "Bearer " + apiKey)
                .header("Content-Type", "multipart/form-data; boundary=" + boundary)
                .POST(HttpRequest.BodyPublishers.ofByteArray(baos.toByteArray()))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

        // Parsear el resultado
        ObjectMapper objectMapper = new ObjectMapper();
        JsonNode jsonResponse = objectMapper.readTree(response.body());
        String transcription = jsonResponse.get("text").asText();

        return this.generateFood(transcription);
    }

    public String generateCustomPlan(FoodUserRequest userId) throws IOException, InterruptedException {

        String foodsByUser = foodService.obtenerTodosLosProductos(userId).toString();

        String prompt = "Genera un plan de comidas como un JSON puro y valido, "+
                "sin explicaciones, sin comillas y sin encerrarlo en bloques de código como ```json. "+
                "Basandote en la siguiente lista de comidas: "+ foodsByUser + " ignora la primera parte, el id del producto. "+
                "Sigue la siguiente estructura:"+
                "{monday: {breakfast, lunch, dinner}, tuesday: {breakfast, lunch, dinner}, "+
                "wednesday: {breakfast, lunch, dinner}, thursday: {breakfast, lunch, dinner}, "+
                "friday: {breakfast, lunch, dinner}, saturday: {breakfast, lunch, dinner}, "+
                "sunday: {breakfast, lunch, dinner}}. "+
                "Llena cada comida con una opción saludable y equilibrada, asegurándote de variar los ingredientes"+
                "a lo largo de la semana. Hazlo en un string.";

        ChatMessage message = new ChatMessage("user", prompt);
        List<ChatMessage> messages = new ArrayList<>();
        messages.add(message);
        OpenAIChatRequest openRequest = new OpenAIChatRequest("gpt-4.1-nano", messages);

        String body = openRequest.toString();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/chat/completions"))
                .headers("Content-Type", "application/json")
                .headers("Authorization", "Bearer "+apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(body))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response =  client.send(request, HttpResponse.BodyHandlers.ofString());

        ObjectMapper objectMapper = new ObjectMapper();

        OpenAIChatResponse openAIResponse = objectMapper.readValue(response.body(), OpenAIChatResponse.class);
        String modelMessage = openAIResponse.getChoices().getFirst().getMessage().getContent();

        return modelMessage.trim();
    }

    public String generateCustomShoppingList(FoodUserRequest userId) throws IOException, InterruptedException {
        String foodsByUser = foodService.obtenerTodosLosProductos(userId).toString();

        String prompt = "Genera una lista de compras quincenal para una persona como un JSON valido y puro,"+
                "sin explicaciones, sin comillas y sin encerrarlo en bloques de código como ```json."+
                "Basandote en la siguiente lista de comidas: "+ foodsByUser + " ignora la primera parte, el id del producto. "+
                "Sigue la siguiente estructura:"+
                "{\\\"lista\\\": \\\"producto:cantidad\\n\\\"}" +
                "Basate en producto-cantidad en el siguiente ejemplo:"+
                "manzana:5\\npera:2\\nleche:1"+
                "Asegúrate de que el valor de lista sea un string"+
                "Llena cada producto con una opción saludable y equilibrada, asegurándote de variar los ingredientes.";

        ChatMessage message = new ChatMessage("user", prompt);
        List<ChatMessage> messages = new ArrayList<>();
        messages.add(message);
        OpenAIChatRequest openRequest = new OpenAIChatRequest("gpt-4.1-nano", messages);

        String body = openRequest.toString();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/chat/completions"))
                .headers("Content-Type", "application/json")
                .headers("Authorization", "Bearer "+apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(body))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response =  client.send(request, HttpResponse.BodyHandlers.ofString());

        ObjectMapper objectMapper = new ObjectMapper();

        OpenAIChatResponse openAIResponse = objectMapper.readValue(response.body(), OpenAIChatResponse.class);
        String modelMessage = openAIResponse.getChoices().getFirst().getMessage().getContent();

        return modelMessage.trim();
    }

    public String generateCustomRecipes(FoodUserRequest userId) throws IOException, InterruptedException {
        String foodsByUser = foodService.obtenerTodosLosProductos(userId).toString();

        String prompt = "Genera una receta como un JSON puro y valido,"+
                "sin explicaciones, sin comillas y sin encerrarlo en bloques de código como ```json."+
                "Basandote en la siguiente lista de comidas: "+ foodsByUser + " ignora la primera parte, el id del producto. "+
                "Sigue la siguiente estructura:"+
                "{calories,ingredients,name,steps,time,difficulty}. No respondas listas, dame las respuestas como strings"+
                "Haz una receta saludable y equilibrada. Hazlo en un string.";

        ChatMessage message = new ChatMessage("user", prompt);
        List<ChatMessage> messages = new ArrayList<>();
        messages.add(message);
        OpenAIChatRequest openRequest = new OpenAIChatRequest("gpt-4.1-nano", messages);

        String body = openRequest.toString();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.openai.com/v1/chat/completions"))
                .headers("Content-Type", "application/json")
                .headers("Authorization", "Bearer " + apiKey)
                .POST(HttpRequest.BodyPublishers.ofString(body))
                .build();

        HttpClient client = HttpClient.newHttpClient();
        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

        ObjectMapper objectMapper = new ObjectMapper();

        OpenAIChatResponse openAIResponse = objectMapper.readValue(response.body(), OpenAIChatResponse.class);
        String modelMessage = openAIResponse.getChoices().getFirst().getMessage().getContent();

        return modelMessage.trim();
    }
}
