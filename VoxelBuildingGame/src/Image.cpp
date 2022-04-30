#include "Image.h"
#include "ResourceManager.h"
#include "GUI.h"
Image::Image() {
	GUI::GetInstance().registryRenderZOrder();
}
void Image::render() {
	//printf("render image index %d\n", GUI::GetInstance().renderZOrderIndex);
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["sprite"];
	auto rect = m_uiObject->rect;
	auto model = glm::mat4(1.f);
	model = glm::translate(model, glm::vec3(rect.getPosition() - rect.getoffs(), GUI::GetInstance().getRenderZOrder()));
	model = glm::scale(model, glm::vec3(rect.getsize() , 1.f));

	shaderSprite->Bind();
	shaderSprite->SetMat4("model", model);
	shaderSprite->SetVec4("color", color);
	draw();
	shaderSprite->UnBind();
}