#include "RectTransform.h"
#include "UIObject.h"

glm::vec2 RectTransform::getPosition() {
	auto pos = position - getoffs();
	//if find UIObject Rect or found Rect UIContainer
	if (parent) {
		pos += parent->getPosition();
	}
	return pos;
}
glm::vec2 RectTransform::getLocalPosition() {
	return position - getoffs();
}