#include "MyGUI.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <stdio.h>

void MyGUI::SetupImGui(Game* game) {
    this->game = game;
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(game->window->glfwWindow, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}
void MyGUI::NewFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}
void MyGUI::Update() {
    //main impl
    ShowExampleAppLayout(&m_showExampleAppLayout);
}
void MyGUI::Render() {
    //// Rendering
    auto window = game->window->glfwWindow;
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void MyGUI::ShowExampleAppLayout(bool* p_open)
{
    ImGui::SetNextWindowSize(ImVec2(0, 0), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Scene Entity", p_open, ImGuiWindowFlags_MenuBar))
    {
        static int selected = 0;
        static Entity* selectEntity = nullptr;
        // Left
        {
            ImGui::BeginChild("left pane", ImVec2(180, 0), true);
            int entityIndex = 0;
            for (auto &e : game->sceneMain->entities)
            {
                // FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
                char label[128];
                std::string entityName = e->GetName();

                sprintf(label, "%s", entityName.c_str());
                if (ImGui::Selectable(label, selected == entityIndex)) {
                    selected = entityIndex;
                    selectEntity = e.get();
                }
                entityIndex++;
            }
            ImGui::EndChild();
        }
        ImGui::SameLine();

        // Right
        if (selectEntity)
        {
            ImGui::BeginGroup();
            ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
            ImGui::Text("Entity %s", selectEntity->GetName().c_str());
            ImGui::Separator();
            if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
            {
                if (ImGui::BeginTabItem("Transform"))
                {
                    std::string pos[3];
                    pos[0] = std::to_string(selectEntity->transform.position.x);
                    pos[1] = std::to_string(selectEntity->transform.position.y);
                    pos[2] = std::to_string(selectEntity->transform.position.z);
                    std::string scale[3];
                    scale[0] = std::to_string(selectEntity->transform.scale.x);
                    scale[1] = std::to_string(selectEntity->transform.scale.y);
                    scale[2] = std::to_string(selectEntity->transform.scale.z);
                    std::string rotate[3];
                    rotate[0] = std::to_string(selectEntity->transform.rotation.x);
                    rotate[1] = std::to_string(selectEntity->transform.rotation.y);
                    rotate[2] = std::to_string(selectEntity->transform.rotation.z);

                    ImGui::Text("Position X:%s Y:%s Z:%s", pos[0].c_str(), pos[1].c_str(), pos[2].c_str());
                    ImGui::Text("Scale X:%s Y:%s Z:%s", scale[0].c_str(), scale[1].c_str(), scale[2].c_str());
                    ImGui::Text("Rotation X:%s Y:%s Z:%s", rotate[0].c_str(), rotate[1].c_str(), rotate[2].c_str());
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
            ImGui::EndChild();
            ImGui::EndGroup();
        }
    }
    ImGui::End();
}
void MyGUI::CleanUp() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}