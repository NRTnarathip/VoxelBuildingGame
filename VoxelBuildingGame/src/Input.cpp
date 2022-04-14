#include "Input.h"
#include <iostream>
#include "ClientEngine.h"

Input *Input::instance = nullptr;

void Input::initMap() {
    
}
bool Input::isKey(int keyCode) {
    auto* glfwWindow = ClientEngine::GetInstance().window->glfwWindow;
    int state = glfwGetKey(glfwWindow, keyCode);
    return state == GLFW_PRESS;
}
bool Input::isKeyDown(int keyCode) {
    auto* glfwWindow = ClientEngine::GetInstance().window->glfwWindow;
    int state = glfwGetKey(glfwWindow, keyCode);
    if (state == GLFW_PRESS) {
        if (arrKeyDowns[keyCode] == 0) {
            arrKeyDowns[keyCode] = 1;
            return true;
        }
        return false;
    }
    arrKeyDowns[keyCode] = 0;
    return false;
}
bool Input::isKeyUp(int keyCode) {
    auto* glfwWindow = ClientEngine::GetInstance().window->glfwWindow;
    int state = glfwGetKey(glfwWindow, keyCode);
    return state == GLFW_RELEASE;
}