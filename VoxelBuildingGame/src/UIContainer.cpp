#include "UIContainer.h"
#include "ResourceManager.h"
#include "UIText.h"

UIObject* UIContainer::createButton(std::string name) {
	auto object = createUIObject();
	object->name = name;

	auto button = object->addComponent<Button>(new Button(name));
	auto image = object->addComponent<Image>(new Image());
	auto uiText = object->addComponent<UIText>(new UIText());
	m_buttons.push_back(button);

	//addjust position line vertical
	return object;
}
UIObject* UIContainer::createImage() {
	auto object = createUIObject();
	object->addComponent<Image>(new Image());
	return object;
}
UIObject* UIContainer::createUIObject() {
	auto entity = registry.create();
	auto newObject = new UIObject();
	newObject->g_registry = &registry;
	newObject->m_entity = entity;
	newObject->rect.parent = &rect;
	m_uiObjects.push_back(newObject);
	return newObject;
}
void UIContainer::render(float zOrder) {
	for (auto object : m_uiObjects) {
		object->render();
	}
}
