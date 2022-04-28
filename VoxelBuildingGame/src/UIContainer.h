#pragma once
#include "RectTransform.h"
#include <string>
#include <map>
#include "Button.h"
#include "SpriteRenderer.h"

class UIContainer {
public:
	RectTransform transform;
	int order = 0;
	std::map <std::string, Button* > m_buttons;
	std::map <std::string, SpriteRenderer* > m_spriteRenders;
	void addButton(Button* btn);
	void render(float zOrder);
	void addSprite(std::string spriteName, SpriteRenderer* sprite);
};