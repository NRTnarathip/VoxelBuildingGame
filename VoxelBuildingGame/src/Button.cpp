#include "Button.h"
#include "Input.h"
#include "Physics/BoxCollision.h"

void Button::setup(glm::vec2 pos, glm::vec2 size)
{
	/*image = new Image();
	rect.position = pos;
	rect.size = size;
	image->rect.parent = &rect;*/
	
}
void Button::update()
{

}

void Button::updateEventInput()
{
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
void Button::bindOnClick(eventFunction refFunction)
{
	m_eventOnClick = refFunction;
}
