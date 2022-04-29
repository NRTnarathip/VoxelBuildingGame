#pragma once
#include "UIComponent.h"
#include <string>

class UIText : public UIComponent {
public:
	UIText() {};
	std::string text = "empty text";
	void render();
};