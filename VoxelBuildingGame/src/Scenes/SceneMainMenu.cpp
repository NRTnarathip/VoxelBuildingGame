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
	auto res = ResourceManager::GetInstance();
	//setup button main menu
	auto menu = UIMenu::GetInstance();
	auto bgLobby = menu->createContainer("background_lobby", {960 ,540}, {1920, 1080});
	auto cont = menu->createContainer("mainmenu", { 960 ,540 }, { 980, 750 });

	auto btnPlay = new Button("play");
	btnPlay->setup({ 0, 0 }, { 80, 80 });
	btnPlay->spriteRender->sprite = res->m_sprites["bgMainMenu"];
	btnPlay->title = "Play";
	btnPlay->bindOnClick([]{
		printf("Click Play\n");
	});
	auto btnSetting = new Button("setting");
	btnSetting->setup({ 90, 0}, { 80, 80 });
	btnSetting->spriteRender->sprite = res->m_sprites["bgMainMenu"];
	btnSetting->title = "Setting";
	btnSetting->bindOnClick([] {
		printf("Click Setting\n");
	});
	auto bgSprite = new SpriteRenderer(res->m_sprites["bgMainMenu"]);
	bgSprite->rect.size = glm::vec2(1920, 1080);
	bgSprite->rect.position = glm::vec2(0, 0);
	bgSprite->rect.pivot = glm::vec2(0,0);
	cont->addButton(btnPlay);
	cont->addButton(btnSetting);

	bgLobby->addSprite("lobby", bgSprite);
}
void SceneMainMenu::update() {
	
}
void SceneMainMenu::render() {
	//render gui
	GUI& gui = GUI::GetInstance();
	gui.render();
}