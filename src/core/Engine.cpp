#include "Engine.h"
#include "../graphics/ModelLoader.h"
#include <iostream>

// ------------------- Singleton Implementation -------------------
Engine& Engine::Instance() {
    static Engine instance;
    return instance;
}

// ------------------- Constructor and Destructor -------------------
Engine::Engine() : lastX(400), lastY(300), firstMouse(true) {
    WindowProperties props;
    props.screenX = 1920;
    props.screenY = 1080;
    props.title = "Game Engine";

    window = new Window(props);
    camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
    isRunning = true;

    glfwSetKeyCallback(window->GetGLFWwindow(), KeyCallback);
    glfwSetCursorPosCallback(window->GetGLFWwindow(), MouseCallback);
    glfwSetScrollCallback(window->GetGLFWwindow(), ScrollCallback);

    glfwSetInputMode(window->GetGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

Engine::~Engine() {
    delete camera;
    delete window;
}

// ------------------- Main Game Loop -------------------
void Engine::Run() {
    Mesh* model = ModelLoader::LoadOBJ("assets/models/Lowpoly_tree_sample.obj");

    if (!model) {
        std::cerr << "❌ Falha ao carregar o modelo." << std::endl;
        return;
    }

    while (isRunning && window->IsGL()) {
        float currentFrame = glfwGetTime();

        window->UpdateGL(); // Get user inputs
        ProcessInput();

        // todo: Remove or improve this
        window->ClearScreen();
        window->RenderMesh(model, *camera, 1.5f);

        window->RenderGL();
    }
}

void Engine::Stop() {
    isRunning = false;
}

// ------------------- Input Handling -------------------
void Engine::ProcessInput() {    
    float velocity = 2.5f * window->getDelta();

    canRotateCamera = glfwGetMouseButton(window->GetGLFWwindow(), 0);

    if (glfwGetKey(window->GetGLFWwindow(), GLFW_KEY_W) == GLFW_PRESS)
        camera->ProcessKeyboard(FORWARD, velocity);
    if (glfwGetKey(window->GetGLFWwindow(), GLFW_KEY_S) == GLFW_PRESS)
        camera->ProcessKeyboard(BACKWARD, velocity);
    if (glfwGetKey(window->GetGLFWwindow(), GLFW_KEY_A) == GLFW_PRESS)
        camera->ProcessKeyboard(LEFT, velocity);
    if (glfwGetKey(window->GetGLFWwindow(), GLFW_KEY_D) == GLFW_PRESS)
        camera->ProcessKeyboard(RIGHT, velocity);
}

// ------------------- Static Callbacks -------------------
void Engine::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Engine& engine = Engine::Instance();

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        engine.Stop();
    }
}

void Engine::MouseCallback(GLFWwindow* window, double xpos, double ypos) {
    Engine& engine = Engine::Instance();

    if (!engine.canRotateCamera) 
        return;

    if (engine.firstMouse) {
        engine.lastX = xpos;
        engine.lastY = ypos;
        engine.firstMouse = false;
    }

    float xoffset = xpos - engine.lastX;
    float yoffset = engine.lastY - ypos;

    engine.lastX = xpos;
    engine.lastY = ypos;

    engine.camera->ProcessMouseMovement(xoffset, yoffset);
}

void Engine::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    Engine& engine = Engine::Instance();

    engine.camera->Zoom -= (float)yoffset;
    if (engine.camera->Zoom < 1.0f)
        engine.camera->Zoom = 1.0f;
    if (engine.camera->Zoom > 45.0f)
        engine.camera->Zoom = 45.0f;
}
