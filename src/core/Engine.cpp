#include "Engine.h"
#include <iostream>

Engine::Engine() {
    window = new Window(800, 600, "Game Engine");
    renderer = new Renderer();
    isRunning = true;
}

Engine::~Engine() {
    delete renderer;
    delete window;
}

void Engine::Run() {
    while (isRunning && !window->ShouldClose()) {
        window->PollEvents(); // Get user inputs

        renderer->ClearScreen();
        renderer->RenderTriangle();

        window->SwapBuffers();
    }
}
