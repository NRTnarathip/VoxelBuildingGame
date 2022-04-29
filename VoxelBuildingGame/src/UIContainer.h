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
#include "UIText.h"


class UIContainer {
public:
	UIContainer(std::string containerName,glm::vec2 pos, glm::vec2 size) : name(containerName){
		rect.size = size;
		rect.position = pos;
	}
	std::string name;
	RectTransform rect;
	entt::registry registry;
	std::vector<UIObject*> m_uiObjects;
	std::vector<Button*> m_buttons;
	int order = 0;

	void render(float zOrder);
	UIObject* createUIObject();
	UIObject* createButton(std::string name);
	UIObject* createImage();
};