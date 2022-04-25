#pragma once
#include "SpriteRenderer.h"
#include "Physics/Transform.h"
#include "AABB.h"

class Button {
private:
	typedef void(*eventFunction)();
	eventFunction m_eventOnClick = nullptr;

	glm::vec2 size{ 80, 80 };
	glm::vec2 position{ 0,0 };
public:
	Button() {}
	AABB aabb;
	std::string title = "Emty Title";
	glm::vec2 pivot{0.5f, 0.5f};
	
	SpriteRenderer* spriteRender;
	glm::vec2 getsize() {
		return size;
	}
	glm::vec2 getpos() {
		return position - (size * pivot);
	}
	void update();
	void setSize(glm::vec2 size);
	void setPos(glm::vec2 pos);
	void init(glm::vec2 pos, glm::vec2 size);
	void updateEventInput();
	void bindOnClick(eventFunction refFunction);
};