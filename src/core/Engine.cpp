#include "Engine.h"
#include <iostream>

Engine::Engine() {
    window = new Window(800, 600, "Game Engine");
    isRunning = true;
}

Engine::~Engine() {
    delete window;
}

void Engine::Run() {
    while (isRunning && !window->ShouldClose()) {
        window->PollEvents(); // Processa entrada do usuário

        // Aqui vamos adicionar o sistema de renderização futuramente

        window->SwapBuffers();
    }
}
