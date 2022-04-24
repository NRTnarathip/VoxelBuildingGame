#include "SceneMainMenu.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include "CameraManager.h"
#include "ClientEngine.h";
#include "GUI.h"
void onClickPlay() {
	printf("click play\n");
}
void SceneMainMenu::init() {
	cameraCanvas = CameraManager::GetInstance().newCamera();
	cameraCanvas->setupCameraOrtho();

	setupMainMenu();
}
void SceneMainMenu::setupMainMenu() {
	//setup button main menu
	auto btnPlay = GUI::NewButton("play", "Play");
	btnPlay->bindOnClick(onClickPlay);
}
void SceneMainMenu::update() {
	
}
void SceneMainMenu::render() {
	int winWidth, winHeight;
	glfwGetWindowSize(ClientEngine::GetInstance().window->glfwWindow, &winWidth, &winHeight);
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["sprite"];
	shaderSprite->Bind();
	for (auto elemSprite : res->m_sprites) {
		auto sprite = elemSprite.second;

		//temp sprite renderer
		auto spriteRenderer = new SpriteRenderer();
		spriteRenderer->sprite = sprite;

		auto model = glm::mat4(1.f);
		auto pos = glm::vec2(-0.5f, -0.5f);
		auto size = glm::vec2(sprite->refTexture->GetWidth(), sprite->refTexture->GetHeight());
		model = glm::translate(model, glm::vec3(pos, 0.f));
		model = glm::scale(model, glm::vec3(1.f, 1.f, 1.f));

		shaderSprite->SetMat4("model", model);
		spriteRenderer->draw();

		delete spriteRenderer;
	}
}