#pragma once
#include <string>
#include <map>
#include "UIMenu.h"
#include <glm/glm.hpp>
#include "TextRenderer.h"

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