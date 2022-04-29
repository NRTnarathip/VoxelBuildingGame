#include "RectTransform.h"
#include "UIObject.h"

glm::vec2 RectTransform::getPosition() {
	auto pos = position;
	//if find UIObject Rect or found Rect UIContainer
	if (parent) {
		pos += parent->getPosition();
	}
	return pos;
}
glm::vec2 RectTransform::getPositionViaPivot() {
	auto pos = getLocalPositionViaPivot();
	//if find UIObject Rect or found Rect UIContainer
	if (parent) {
		pos += parent->getPositionViaPivot();
	}
	return pos;
}
glm::vec2 RectTransform::getLocalPositionViaPivot() {
	return position - getoffs();
}