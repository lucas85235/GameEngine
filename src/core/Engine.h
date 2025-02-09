#ifndef ENGINE_H
#define ENGINE_H

#include "Window.h"

class Engine {
public:
    Engine();
    ~Engine();

    void Run(); // Loop principal do jogo

private:
    Window* window;
    bool isRunning;
};

#endif
