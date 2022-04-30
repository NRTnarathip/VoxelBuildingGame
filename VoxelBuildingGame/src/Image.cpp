#include "Image.h"
#include "ResourceManager.h"

void Image::render() {
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["sprite"];
	auto rect = m_uiObject->rect;
	auto pos = rect.getPosition();
	auto size = rect.getsize();

	auto zOrder = -0.2f;
	auto model = glm::mat4(1.f);
	model = glm::translate(model, glm::vec3(pos - rect.getoffs(), zOrder));
	model = glm::scale(model, glm::vec3(size, 1.f));

	shaderSprite->Bind();
	shaderSprite->SetMat4("model", model);
	shaderSprite->SetVec4("color", color);
	draw();
	shaderSprite->UnBind();
}