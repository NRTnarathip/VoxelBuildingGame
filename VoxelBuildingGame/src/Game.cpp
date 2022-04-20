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
    //setup core
    resourceManager = new ResourceManager();
    world = new World();
    chManager = new ChunkManager();
    genMeshChunk = new GenMeshChunk();
    auto defaultShader = resourceManager->addShader("src/Shader/defualt.vert", "src/Shader/defualt.frag");
    resourceManager->m_textures.push_back(new Texture("src/Texture/mcatlas.png", true, true, GL_REPEAT, GL_NEAREST));
    auto& graphicSetting = ClientEngine::GetInstance().graphicSetting;
    defaultShader->Bind();
    auto mcatlas = resourceManager->m_textures[0];
    defaultShader->SetVar("tex", 0);
    defaultShader->SetFloat("aoStrength", 0.45f);
    defaultShader->SetFloat("fogMin", graphicSetting.fogMin);
    defaultShader->SetFloat("fogMax", graphicSetting.fogMax);
    defaultShader->UnBind();

    resourceManager->addShader("src/Shader/gameobject.vert", "src/Shader/gameobject.frag");
    //create world
    world->init();
    //create system manager
    chManager->init(glm::vec3(0, 0, 0));
    genMeshChunk->init(chManager);
}
void Game::render() {
    auto shaders = resourceManager->m_shaders;
    CameraManager::GetInstance().uploadCameraMatrixToShader(shaders[0]);
    chManager->render();
    world->render();
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
    chManager->update();
    genMeshChunk->update();
}

void Game::processInput()
{
    auto glWindow = window->glfwWindow;
    if (glfwGetKey(glWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(glWindow, true);
}