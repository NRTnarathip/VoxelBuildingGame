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
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["sprite"];

	int elemIndex = 0;
	for (auto object : m_uiObjects) {
		auto image = object->getComponent<Image>();
		auto rectOjbect = &object->rect;

		auto pos = rectOjbect->getPosition();
		auto size = rectOjbect->getsize();
		auto model = glm::mat4(1.f);
		float zOrderOfElem = ((float)elemIndex / m_uiObjects.size()) * zOrder;
		zOrderOfElem += zOrder;
		model = glm::translate(model, glm::vec3(pos - rectOjbect->getoffs(), zOrderOfElem));
		model = glm::scale(model, glm::vec3(size, 1.f));

		shaderSprite->Bind();
		shaderSprite->SetMat4("model", model);
		shaderSprite->SetVec4("color", image->color);
		image->draw();
		shaderSprite->UnBind();

		object->render();

		elemIndex++;
	}
}
