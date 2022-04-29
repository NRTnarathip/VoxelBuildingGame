#include "RectTransform.h"
#include "UIObject.h"
//is useonly just UIContainer as parent and UICompoent as child
glm::vec2 RectTransform::getPosition() {
	auto pos = position;
	if (parent) {
		pos += parent->getLocalPositionViaPivot();
	}
	return pos;
}
glm::vec2 RectTransform::getLocalPositionViaPivot() {
	return position - getoffs();
}