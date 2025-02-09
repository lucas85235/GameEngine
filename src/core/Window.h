#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    void PollEvents();
    void SwapBuffers();
    bool ShouldClose();

private:
    GLFWwindow* window;
};

#endif
