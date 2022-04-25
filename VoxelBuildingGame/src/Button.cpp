#include "Button.h"
#include "Input.h"
#include "Physics/BoxCollision.h"

void Button::setPos(glm::vec2 pos) {
	position = pos;
	aabb.position = position;
}
void Button::init(glm::vec2 pos, glm::vec2 size) {
	setPos(pos);
	setSize(size);
}
void Button::setSize(glm::vec2 size) {
	this->size = size;
	aabb.size = size;
}
void Button::update()
{

}

void Button::updateEventInput()
{
	auto& input = Input::GetInstance();
	auto mousePos = input.getMousePosition();
	bool isInSection = aabb.isInSection(mousePos);

	if (isInSection) {
		if (input.onMouseDown(0)) {
			if(m_eventOnClick) m_eventOnClick();

			printf("on click Button: %s\n", title.c_str());
		}
	}
}

void Button::bindOnClick(eventFunction refFunction)
{
	m_eventOnClick = refFunction;
}
