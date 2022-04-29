#include "RectTransform.h"
#include "UIObject.h"

glm::vec2 RectTransform::getPosition() {
	auto pos = getLocalPositionViaPivot();
	//if find UIObject Rect or found Rect UIContainer
	if (parent) {
		pos += parent->getPosition();
		pos += getoffs();
	}
	return pos;
}
glm::vec2 RectTransform::getLocalPositionViaPivot() {
	return position - getoffs();
}