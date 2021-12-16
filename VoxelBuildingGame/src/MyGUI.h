#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Game.h"

// Visual Studio warnings
#ifdef _MSC_VER
#pragma warning (disable: 4996)     // 'This function or variable may be unsafe': strcpy, strdup, sprintf, vsnprintf, sscanf, fopen
#pragma warning (disable: 26451)    // [Static Analyzer] Arithmetic overflow : Using operator 'xxx' on a 4 byte value and then casting the result to a 8 byte value. Cast the value to the wider type before calling operator 'xxx' to avoid overflow(io.2).
#endif

class MyGUI {
public:
    Game* game = nullptr;
    bool m_showExampleAppLayout = true;
    void SetupImGui(Game* game);//setup
    void ShowExampleAppLayout(bool* p_open);
    void NewFrame();
    void Update();
    void Render();
    void CleanUp();
};