#include "Window.h"
#include <iostream>
#include <chrono>
#include <thread>

// Common global variables
//----------------------------------------------------
struct timespec time_start;

static double elapseTime = 0.0;
static double delta = 0.0;
static double FPS = 0.0;
static double restSec = 0.0167; // default 60fps

// todo: create time script for this function
void sleep_ms(uint64_t value) {
    std::this_thread::sleep_for(std::chrono::microseconds(value));
}

Window::Window(WindowProperties _prop) {
    properties = _prop;
    InitGL();
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
    delete shader;
}

int Window::InitGL() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(-1);
    }

    window = glfwCreateWindow(properties.screenX, properties.screenY, properties.title, NULL, NULL);

    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    std::cout << "Initializing Renderer..." << std::endl;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return 0;
    }

    // todo: move this to other script?
    shader = new Shader("shaders/vertex_shader.vert", "shaders/fragment_shader.frag");
    std::cout << "Renderer initialized successfully!" << std::endl;
}

bool Window::IsGL() {
    return !glfwWindowShouldClose(window);
}

void Window::UpdateGL() {
    // UPDATE TIME
    double now = getTimeSec();
    float diff = now - elapseTime;
    if (diff < restSec) {
        sleep_ms(int((restSec - diff) * 1000000));
        now = getTimeSec();
    }

    delta = now - elapseTime;
    elapseTime = now;

    static int frame_count = 0;
    static double lastTime = 0.0;
    frame_count++;
    lastTime += delta;
    if (lastTime >= 1.) {
        FPS = double(frame_count);
        frame_count = 0;
        lastTime -= 1.;
    }

    // EVENTS
    glfwPollEvents();
}

void Window::RenderGL() {
    glfwSwapBuffers(window);
}

void Window::CloseGL() {
    glfwSetWindowShouldClose(window, GL_TRUE);
    glfwTerminate();
}

GLFWwindow* Window::GetGLFWwindow() {
    return window;
}

// TIME
// ---------------------------------------

double Window::getTimeSec() {
    timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    timespec temp;
    if ((now.tv_nsec-time_start.tv_nsec)<0) {
        temp.tv_sec = now.tv_sec-time_start.tv_sec-1;
        temp.tv_nsec = 1000000000+now.tv_nsec-time_start.tv_nsec;
    } else {
        temp.tv_sec = now.tv_sec-time_start.tv_sec;
        temp.tv_nsec = now.tv_nsec-time_start.tv_nsec;
    }
    return double(temp.tv_sec) + double(temp.tv_nsec/1000000000.);
}

double  Window::getTime() { return elapseTime;}
double  Window::getDelta() { return delta; }

// TO REMOVE
// ---------------------------------------

// todo: remove this, and replace in the mesh, draw or fvo/vbo
void Window::ClearScreen() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

// todo: improve this create draw component or scene scene system
void Window::RenderMesh(Mesh *mesh, Camera& camera, float aspectRatio) {
    shader->Use();

    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 projection = camera.GetProjectionMatrix(aspectRatio);

    shader->SetUniformMatrix4fv("view", &view[0][0]);
    shader->SetUniformMatrix4fv("projection", &projection[0][0]);

    mesh->Draw();
}
