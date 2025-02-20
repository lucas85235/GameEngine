#include "Engine.h"
#include <iostream>

Engine::Engine() {
    window = new Window(1920, 1080, "Game Engine");
    renderer = new Renderer();
    camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f)); 
    isRunning = true;
}

Engine::~Engine() {
    delete renderer;
    delete camera;
    delete window;
}

void Engine::Run() {
    while (isRunning && !window->ShouldClose()) {
        window->PollEvents(); // Get user inputs

        renderer->ClearScreen();
        renderer->RenderTriangle(*camera, 1.5f);

        window->SwapBuffers();
    }
}
