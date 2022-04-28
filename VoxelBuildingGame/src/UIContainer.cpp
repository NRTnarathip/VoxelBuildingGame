#include "UIContainer.h"
#include "ResourceManager.h"

void UIContainer::addButton(Button* btn) {
	btn->parent = this;
	m_buttons.emplace(btn->name, btn);
	btn->aabb = AABB(btn->transform.getpos() + transform.getpos(),
		btn->transform.getsize() * transform.scale);
}
void UIContainer::addSprite(std::string spriteName, SpriteRenderer* sprite) {
	m_spriteRenders.emplace(spriteName, sprite);
}
void UIContainer::render(float zOrder) {
	printf("zOrder: %f | order %d \n",zOrder, order);
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["sprite"];

	for (auto elemButton : m_buttons) {
		auto button = elemButton.second;
		auto spriteRender = button->spriteRender;

		auto btnTransform = button->transform;
		auto pos = btnTransform.getpos();
		auto size = btnTransform.getsize();

		pos += transform.getpos();
		size *= transform.scale;

		auto model = glm::mat4(1.f);
		model = glm::translate(model, glm::vec3(pos, zOrder));
		model = glm::scale(model, glm::vec3(size, 1.f));
		shaderSprite->SetMat4("model", model);
		shaderSprite->SetVec4("color", button->color);
		spriteRender->draw();
	}

	for (auto elem : m_spriteRenders) {
		auto sp = elem.second;
		auto rect = sp->rect;

		auto pos = rect.getpos();
		auto size = rect.getsize();

		pos += transform.getpos();
		size *= transform.scale;

		auto model = glm::mat4(1.f);
		model = glm::translate(model, glm::vec3(pos, zOrder));
		model = glm::scale(model, glm::vec3(size, 1.f));
		shaderSprite->SetMat4("model", model);
		shaderSprite->SetVec4("color", sp->color);
		sp->draw();
	}
}
