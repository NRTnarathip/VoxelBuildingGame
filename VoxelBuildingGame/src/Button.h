#pragma once
#include "SpriteRenderer.h"
#include "Physics/Transform.h"
#include "AABB.h"
#include <glm/vec4.hpp>
#include "RectTransform.h"
#include "Image.h"
#include "UIComponent.h"

class Button : public UIComponent {
private:
	void onHover();
	void outHover();
	bool isOnHover = false;
public:
	typedef void(*functionPointer)();
	functionPointer m_eventOnClick = nullptr;

	class ColorTransition {
	public:
		glm::vec4 colorHover{ 0.75f,0.75f,0.75f, 1.f };
		glm::vec4 colorNormal{ 1.f};
	};
	Button() {}
	Button(std::string name) {
		this->name = name;
	}
	std::string title = "Emty Title";
	std::string name = "emty_button";
	glm::vec4 color{ 1.f,1.f,1.f,1.f };
	ColorTransition colors;
	void updateEventInput();
	void bindOnClick(functionPointer refFunction);
};