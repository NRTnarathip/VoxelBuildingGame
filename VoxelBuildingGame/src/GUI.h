#pragma once
#include <string>
#include <map>
#include "Button.h"

class GUI {
private:
	static GUI m_instance;
	std::map<std::string, Button*> m_buttons;

public:
	static GUI& GetInstance() { return m_instance; }
	static void Begin() {};
	static void End() {};
public:
	GUI();
	void render();
	glm::vec2 getWindowSize();
	void updateEventInput();
	Button* newButton(std::string keyName);
};