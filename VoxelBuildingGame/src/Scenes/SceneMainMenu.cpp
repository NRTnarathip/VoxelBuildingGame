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
	auto contentBG = menu->createContainer("lobby_background", {960 ,540}, {1920, 1080});
	auto contentMainMenu = menu->createContainer("mainmenu", { 960 ,540 }, { 800, 600});
	{
		auto buttonPlay = contentMainMenu->createButton("play");
		buttonPlay->rect.size = {200, 40};
		auto imageBtnPlay = buttonPlay->getComponent<Image>();
		imageBtnPlay->sprite = res->getSprite("gui/button_0");

		auto uiText = buttonPlay->addComponent<UIText>(new UIText());
	}
	{
		/*auto obj = contentBG->createImage();
		auto image = obj->getComponent<Image>();
		image->sprite = res->getSprite("gui/lobby_background");
		obj->rect.size = contentBG->rect.size;
		obj->rect.position = contentBG->rect.size / 2.f;*/
	}
}
void SceneMainMenu::update() {
	
}
void SceneMainMenu::render() {
	//render gui
	GUI& gui = GUI::GetInstance();
	gui.render();
}