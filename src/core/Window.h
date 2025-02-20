#ifndef WINDOW_H
#define WINDOW_H

#include "../graphics/Renderer.h"

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void PollEvents();
    void SwapBuffers();
    bool ShouldClose();
    GLFWwindow* GetGLFWwindow();

private:
    GLFWwindow* window;
};

#endif
