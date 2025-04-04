#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Camera.h"
#include "Mesh.h"

struct WindowProperties {
    int screenX = -1;
    int screenY = -1;
    const char* title = "";
};

class Window {
public:
    Window(WindowProperties _properties = WindowProperties());
    ~Window();

    //	GL Context
    //----------------------------------------------
    int         InitGL();
    bool        IsGL();
    void        UpdateGL();
    void        RenderGL();
    void        CloseGL();
    GLFWwindow* GetGLFWwindow();

    // TIME
    // ---------------------------------------
    double      getTimeSec();
    double      getTime();
    double      getDelta();

    // todo: to remove later
    void ClearScreen();
    void RenderMesh(Mesh *mesh, Camera& camera, float aspectRatio);

private:
    WindowProperties properties;
    GLFWwindow* window;
    Shader* shader;
};

#endif
