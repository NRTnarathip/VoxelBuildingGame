#pragma once
#include "RectTransform.h"
#include <string>
#include <map>
#include <vector>
#include "Button.h"
#include "SpriteRenderer.h"
#include "UIObject.h"
#include "Image.h"
#include "entt/entt.hpp"

class UIContainer {
public:
	entt::registry registry;
	std::vector<UIObject*> m_uiObjects;
	std::vector<Button*> m_buttons;
	RectTransform rect;
	int order = 0;

	void render(float zOrder);
	UIObject* createUIObject();
	UIObject* createButton(std::string name);
	UIObject* createImage();
};