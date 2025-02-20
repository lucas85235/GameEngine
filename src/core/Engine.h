#ifndef ENGINE_H
#define ENGINE_H

#include "Window.h"

class Engine {
public:
    Engine();
    ~Engine();

    void Run();

private:
    Window* window;
    Renderer* renderer;
    bool isRunning;
};

#endif
