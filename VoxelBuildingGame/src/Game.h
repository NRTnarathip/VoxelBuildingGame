#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//my components
#include <ECS.h>
#include <World.h>
#include <Camera.h>
#include <GenerateMeshChunk.h>
#include <ChunkManager.h>

class Window;
class Game;
class Time;

class ShaderList {
public:
    Shader* defaultShader = nullptr;
    Texture *mcatlas = nullptr;
    Shader* skyShader = nullptr;
};
class Game {
private:
    int tickAmount = 20; //per second, 1000.0 / tickAmount
    float tickDelayTime = 1000.0f / tickAmount;
    void inputDebug();
public:
    Game(Window* win);
    static Game* ref;
    static World* world;
    Camera* cameraMain = NULL;
    Window* window = nullptr;
    Scene* sceneMain = nullptr;
    ChunkManager* chManager = 0;
    GenMeshChunk* genMeshChunk = 0;
    void counterTime();
    double GetTime() {
        return glfwGetTime();
    };
    //order of event functions visualised
    void init();
    void start();
    void beforeUpdate();//like fixed update
    void update();
    void lastUpdate();
    void checkDestroyEntity();
    //end
    void render();
    void processInput(GLFWwindow* window);

    void printCounter();
    ShaderList shaders;
};

class Window {
public:
    Window(const char* newTitle);
    GLFWwindow* glfwWindow = nullptr;
    static unsigned int width;
    static unsigned int height;
    const unsigned int initWidth = 1280;
    const unsigned int initHeight = 720;
    const char* titleName = "Marhcing Cube";
    float FOVdeg = 60.f;
    float nearPlane = 0.03f;
    float farPlane = 500.f;
};
class Time {
public:
    static double deltaTime;
    static double lastTime;
    static double lastTimeFPS;
    static float framesPerSecond;
    static int fps;
};