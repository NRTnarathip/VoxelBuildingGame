#pragma once
#include <string>
#include <map>
#include "Button.h"
#include "UIMenu.h"
#include <glm/glm.hpp>

class GUI {
private:
	static GUI m_instance;
	UIMenu* m_menu = nullptr;
public:
	static GUI& GetInstance() { return m_instance; }
	static void Begin() {};
	static void End() {};
public:
	GUI();
	glm::mat4 projection;

	void render();
	glm::vec2 getWindowSize();
	void updateEventInput();
};