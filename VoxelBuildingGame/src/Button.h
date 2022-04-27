#pragma once
#include "SpriteRenderer.h"
#include "Physics/Transform.h"
#include "AABB.h"
#include <glm/vec4.hpp>
#include "RectTransform.h"

class Button {
private:
	typedef void(*eventFunction)();
	eventFunction m_eventOnClick = nullptr;
	void onHover();
	void outHover();
	bool isOnHover = false;

	glm::vec2 position;
	glm::vec2 size;
public:
	class ColorTransition {
	public:
		glm::vec4 colorHover{ 0.75f,0.75f,0.75f, 1.f };
		glm::vec4 colorNormal{ 1.f};
	};

	Button() {}
	AABB aabb;
	RectTransform transform;
	std::string title = "Emty Title";
	glm::vec4 color{ 1.f,1.f,1.f,1.f };
	ColorTransition colors;
	
	SpriteRenderer* spriteRender;
	glm::vec2 getpos() {
		return aabb.getpos();
	}
	void setup(glm::vec2 pos, glm::vec2 size, glm::vec2 pivot);
	void update();
	void updateEventInput();
	void bindOnClick(eventFunction refFunction);
};