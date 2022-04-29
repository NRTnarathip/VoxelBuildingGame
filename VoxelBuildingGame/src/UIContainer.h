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
	UIContainer() {
		auto entity = registry.create();
		m_uiObject = new UIObject();
		m_uiObject->g_registry = &registry;
		m_uiObject->m_entity = entity;
		m_uiObject->name = "UI Container";
	}
	UIObject* m_uiObject = nullptr;

	entt::registry registry;
	std::vector<UIObject*> m_uiObjects;
	std::vector<Button*> m_buttons;
	int order = 0;

	void render(float zOrder);
	UIObject* createUIObject();
	UIObject* createButton(std::string name);
	UIObject* createImage();
};