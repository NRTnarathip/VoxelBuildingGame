#include "Button.h"
#include "Input.h"
#include "Physics/BoxCollision.h"

void Button::updateEventInput()
{
	auto rect = m_uiObject->rect;
	auto aabb = AABB(rect.getPosition() - rect.getoffs(), rect.getsize());

	auto& input = Input::GetInstance();
	auto mousePos = input.getMousePosition();
	bool isMouseHover = aabb.isInSection(mousePos);

	if (isMouseHover) {
		if (input.onMouseDown(0)) {
			if(m_eventOnClick) m_eventOnClick();
		}
		if (isOnHover == false) {
			isOnHover = true;
			onHover();
		}
	}
	else {
		if (isOnHover) {
			isOnHover = false;
			outHover();
		}
	}
}
void Button::outHover() {
	m_uiObject->rect.scale = glm::vec2(1.f);
	color = colors.colorNormal;
}
void Button::onHover() {
	m_uiObject->rect.scale = glm::vec2(1.2f);
	color = colors.colorHover;
}
void Button::bindOnClick(functionPointer refFunction)
{
	m_eventOnClick = refFunction;
}
