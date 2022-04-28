#pragma once
#include "SpriteRenderer.h"
#include "Physics/Transform.h"
#include "AABB.h"
#include <glm/vec4.hpp>
#include "RectTransform.h"
#include "Image.h"
#include "UIObject.h"

class UIContainer;

class Button : public UIComponent {
private:
	typedef void(*eventFunction)();
	eventFunction m_eventOnClick = nullptr;
	void onHover();
	void outHover();
	bool isOnHover = false;
public:
	class ColorTransition {
	public:
		glm::vec4 colorHover{ 0.75f,0.75f,0.75f, 1.f };
		glm::vec4 colorNormal{ 1.f};
	};
	Button() {}
	Button(std::string name) {
		this->name = name;
	}
	AABB aabb;
	std::string title = "Emty Title";
	std::string name = "emty_button";
	glm::vec4 color{ 1.f,1.f,1.f,1.f };
	ColorTransition colors;
	void setup(glm::vec2 pos, glm::vec2 size);
	void update();
	void updateEventInput();
	void bindOnClick(eventFunction refFunction);
};