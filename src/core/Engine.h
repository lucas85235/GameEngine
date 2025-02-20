#ifndef ENGINE_H
#define ENGINE_H

#include "Window.h"

class Engine {
public:
    static Engine& Instance();

    void Run();
    void Stop();

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseCallback(GLFWwindow* window, double xpos, double ypos);
    static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

private:
    Engine();
    ~Engine();

    Engine(const Engine&) = delete;              // Proíbe cópia
    Engine& operator=(const Engine&) = delete;   // Proíbe atribuição

    Window* window;
    Renderer* renderer;
    Camera* camera;

    bool isRunning;

    float lastFrameTime;
    float deltaTime;

    float lastX;
    float lastY;
    bool firstMouse;
    bool canRotateCamera;

    void ProcessInput();
};

#endif
