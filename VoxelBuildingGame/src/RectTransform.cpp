#include "RectTransform.h"
#include "UIObject.h"
//is useonly just UIContainer as parent and UICompoent as child
glm::vec2 RectTransform::inceptGetPosition() {
	auto pos = getLocalPositionViaPivot();
	if (parent) {
		pos += parent->inceptGetPosition();
	}
	return pos;
}
glm::vec2 RectTransform::getPosition() {
	return inceptGetPosition() + getoffs();
}
glm::vec2 RectTransform::getLocalPositionViaPivot() {
	return position - getoffs();
}