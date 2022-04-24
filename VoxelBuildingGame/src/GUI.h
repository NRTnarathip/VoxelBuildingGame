#pragma once
#include <string>
#include <map>
#include "Button.h"

class GUI {
private:
	static GUI m_instance;
	std::map<std::string, Button*> m_buttons;
public:
	GUI();
	static void Begin() {};
	static void End() {};
	static Button* NewButton(std::string keyName, std::string title);
};