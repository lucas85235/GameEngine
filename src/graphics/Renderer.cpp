#include "Renderer.h"
#include <iostream>

Renderer::Renderer() {
    std::cout << "Initializing Renderer..." << std::endl;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }

    shader = new Shader("shaders/vertex_shader.vert", "shaders/fragment_shader.frag");

    std::cout << "Renderer initialized successfully!" << std::endl;
}

Renderer::~Renderer() {
    delete shader;
}

void Renderer::ClearScreen() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::RenderMesh(Mesh& mesh, Camera& camera, float aspectRatio) {
    shader->Use();
 
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 projection = camera.GetProjectionMatrix(aspectRatio);
 
    shader->SetUniformMatrix4fv("view", &view[0][0]);
    shader->SetUniformMatrix4fv("projection", &projection[0][0]);
 
    mesh.Draw();
}
