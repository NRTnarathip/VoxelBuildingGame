#include "UIObject.h"
void UIObject::attachObject(UIObject* child) {
	rect.childs.push_back(&child->rect);
	child->rect.parent = &rect;
}