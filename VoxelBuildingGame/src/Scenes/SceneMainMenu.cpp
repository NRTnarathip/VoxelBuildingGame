#include "SceneMainMenu.h"
#include "GUI/Sprite.h"
#include "ResourceManager.h"
#include "CameraManager.h"
#include "ClientEngine.h";

void SceneMainMenu::init() {
	cameraCanvas = CameraManager::GetInstance().newCamera();
	cameraCanvas->setupCameraOrtho();
}
void SceneMainMenu::update() {
}
void SceneMainMenu::render() {
	int winWidth, winHeight;
	glfwGetWindowSize(ClientEngine::GetInstance().window->glfwWindow, &winWidth, &winHeight);
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["render2D"];
	shaderSprite->Bind();
	for (auto elemSprite : res->m_sprites) {
		auto sprite = elemSprite.second;

		auto model = glm::mat4(1.f);
		auto pos = glm::vec2(-0.5f, -0.5f);
		auto size = glm::vec2(sprite->refTexture->GetWidth(), sprite->refTexture->GetHeight());
		model = glm::translate(model, glm::vec3(pos, 0.f));
		model = glm::scale(model, glm::vec3(1.f, 1.f, 1.f));

		shaderSprite->SetMat4("model", model);
		sprite->draw();
	}
}