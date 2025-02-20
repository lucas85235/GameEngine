#include "Renderer.h"
#include <iostream>

const float vertices[] = {
     0.0f,  0.5f, 0.0f,  
    -0.5f, -0.5f, 0.0f,  
     0.5f, -0.5f, 0.0f   
};

Renderer::Renderer() {
    std::cout << "Initializing Renderer..." << std::endl;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    shader = new Shader("shaders/vertex_shader.vert", "shaders/fragment_shader.frag");

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    std::cout << "Renderer initialized successfully!" << std::endl;
}

Renderer::~Renderer() {
    delete shader;
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Renderer::ClearScreen() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::RenderTriangle() {
    shader->Use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
