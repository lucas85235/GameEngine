#include "Engine.h"
#include <iostream>
#include <thread>
#include <chrono>

bool isRunning = true;

Engine::Engine() {
    std::cout << "Engine initialized!\n";
}

Engine::~Engine() {
    std::cout << "Engine shutting down.\n";
}

void Engine::Run() {
    while (isRunning) {
        std::cout << "Engine Running...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Engine::Stop() {
    isRunning = false;
}
