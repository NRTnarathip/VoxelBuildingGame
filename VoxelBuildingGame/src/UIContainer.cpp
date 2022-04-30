#include "UIContainer.h"
#include "ResourceManager.h"
#include "UIText.h"
#include "GUI.h"

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
	auto gui = &GUI::GetInstance();
	auto newObject = gui->createUIObject();
	newObject->rect.parent = &rect;
	rect.childs.push_back(&newObject->rect);
	return newObject;
}
