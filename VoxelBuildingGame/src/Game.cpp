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

#include "Scenes/SceneMainGame.h"
#include "Scenes/SceneMainMenu.h"
#include "GUI.h"



//functin prototype
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

//static variable
Game* Game::instance = nullptr;
//cass Window
unsigned int Window::width = 0;
unsigned int Window::height = 0;

//class Time
double Time::deltaTime = 0.0;
double Time::lastTime = 0.0;
int Time::fps = 0;
double Time::lastTimeFPS = 0;
float Time::framesPerSecond = 0.f;

Game::Game(Window * win) {
    instance = this;
    window = win;
}
Window::Window(const char* newTitle) {
    titleName = newTitle;
}
void Game::UpdateInFrame() {
    counterTime();
    processInput();
    //procress GUI Event
    GUI& gui = GUI::GetInstance();
    gui.updateEventInput();

    beforeUpdate();
    update();
    lastUpdate();
    render();
}
void Game::init() {
    //setup core base all
    sceneManager = new SceneManager();
    //setup core addond

    //setup scene main menu, game
    auto mainMenu = new SceneMainMenu("Main Menu");
    auto mainGame = new SceneMainGame("Main Game");
    sceneManager->addExistScene(mainMenu);
    sceneManager->addExistScene(mainGame);

    //implement engine core base
    sceneManager->init();

    ////create world
       //world = new World();
   /* chManager = new ChunkManager();
    genMeshChunk = new GenMeshChunk();*/
    //world->init();
    ////create system manager
    //chManager->init(glm::vec3(0, 0, 0));
    //genMeshChunk->init(chManager);

}
void Game::render() {
    glClearColor(0.f, 0.0f, 0.0f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    sceneManager->render();
    //auto shaders = resourceManager->m_shaders;
    //CameraManager::GetInstance().uploadCameraMatrixToShader(shaders[0]);
    //chManager->render();
    //world->render();

     // Swap the back buffer with the front buffer
    glfwSwapBuffers(window->glfwWindow);
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
    sceneManager->beforeUpdate();

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
    sceneManager->lastUpdate();
}
void Game::update() { //update every frame
    //order call function!!!
    //world update
    //
    //test event input 
   
    

    sceneManager->update();
    //world->update(Time::lastTime);

    ////update chunk manager
    //auto* camera = CameraManager::GetCurrentCamera();
    //chManager->update();
    //genMeshChunk->update();
}

void Game::processInput()
{
    auto glWindow = window->glfwWindow;
    if (glfwGetKey(glWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(glWindow, true);
}