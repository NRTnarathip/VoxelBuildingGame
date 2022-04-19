#include <Game.h>
#include <ChunkManager.h>
#include <Texture.h>
#include <PlayerController.h>
#include <Mesh.h>
#include <stb/stb_image.h>
#include <ClientEngine.h>
#include "Input.h"
#include <entt/entt.hpp>
#include <CameraManager.h>
//functin prototype
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

//static variable
Game* Game::ref = nullptr;
World* Game::world = nullptr;
//cass Window
unsigned int Window::width = 0;
unsigned int Window::height = 0;

//class Time
double Time::deltaTime = 0.0;
double Time::lastTime = 0.0;
int Time::fps = 0;
double Time::lastTimeFPS = 0;
float Time::framesPerSecond = 0.f;

Game::Game(Window * win) : registry() {
    ref = this;
    window = win;
}
Window::Window(const char* newTitle) {
    titleName = newTitle;
}
void Game::init() {
    //create world
    world = new World();
    world->init();
    const auto& player = world->addEntity("Player");
    //create system manager
    chManager = new ChunkManager();
    
    genMeshChunk = new GenMeshChunk();
}
void Game::render() {
    chManager->render();
}
void Game::printCounter() {
    printf("FPS %d\n", Time::fps);
    printf("Render Triangle Count %d\n", Mesh::triangleGPU);
}
void Game::counterTime() { 
    //update deltatime
    double currentTime = glfwGetTime();
    Time::deltaTime = currentTime - Time::lastTime;
    Time::lastTime = currentTime;
    ++Time::framesPerSecond;

    if (currentTime - Time::lastTimeFPS > 1.0f)
    {
        Time::lastTimeFPS = currentTime;
        Time::fps = (int)Time::framesPerSecond;
        Time::framesPerSecond = 0;

        printCounter();
    }
}
void Game::start() {
    world->start();
    chManager->start();
    genMeshChunk->start(chManager);
}
void Game::beforeUpdate() {
    inputDebug();
}
void Game::inputDebug() {
    int scancode = glfwGetKeyScancode(GLFW_KEY_X);
    int stateReloadTexture = glfwGetKey(window->glfwWindow, GLFW_KEY_F3);
    if (stateReloadTexture == GLFW_PRESS)
    {
        printf("f3 keydown\n");
    }
}
void Game::lastUpdate() {
}
void Game::update() { //update every frame
    //order call function!!!
    //world update
    //
    //test event input 
    world->update(Time::lastTime);

    //update chunk manager
    auto* camera = CameraManager::GetCurrentCamera();
    chManager->update(camera->Postition, ClientEngine::GetInstance().graphicSetting.renderDistance);
    genMeshChunk->update();
}

void Game::checkDestroyEntity() {
}

void Game::processInput()
{
    auto glWindow = window->glfwWindow;
    if (glfwGetKey(glWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(glWindow, true);
}