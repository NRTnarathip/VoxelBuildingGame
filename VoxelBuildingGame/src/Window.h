#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//is child from class ClientEngine;
class Window {
public:
    static Window* m_instance;
    static Window* GetInstance();
public:
    Window(const char* newTitle);
    GLFWwindow* window = nullptr;
    void onWindowResize(int width, int height);
    unsigned int width = 1280;
    unsigned int height = 720;
    const char* title = "Voxel Engine";
};