#pragma once
#include <string>
#include <map>
#include "UIMenu.h"
#include <glm/glm.hpp>
#include "TextRenderer.h"
#include <map>

class GUI {
private:
	static GUI* m_instance;
	UIMenu* m_menu = nullptr;
	std::vector<UIObject*> m_UIObjectHierarchy;
	entt::registry registry;
public:
	static GUI& GetInstance() { return *m_instance; }
	static void Begin() {};
	static void End() {};
public:
	GLFWwindow* window = nullptr;
	GUI(GLFWwindow* window);
	glm::mat4 projection;
	void render();
	glm::vec2 getWindowSize();
	void updateEventInput();
	UIObject* createUIObject();
};