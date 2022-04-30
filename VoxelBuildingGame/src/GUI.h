#pragma once
#include <string>
#include <map>
#include "UIMenu.h"
#include <glm/glm.hpp>
#include "TextRenderer.h"

class GUI {
private:
	static GUI* m_instance;
	UIMenu* m_menu = nullptr;

	int renderZOrderIndexNow = 0;
	float unitZOrderPerRender = 0.f;
	int totalZOrderRegistry = 0;
public:
	static GUI& GetInstance() { return *m_instance; }
	static void Begin() {};
	static void End() {};
	static float GetRenderZOrder() { return m_instance->getRenderZOrder(); }
public:
	GLFWwindow* window = nullptr;
	GUI(GLFWwindow* window);
	glm::mat4 projection;
	void render();
	glm::vec2 getWindowSize();
	void updateEventInput();
	float getRenderZOrder();
	void registryRenderZOrder();

};