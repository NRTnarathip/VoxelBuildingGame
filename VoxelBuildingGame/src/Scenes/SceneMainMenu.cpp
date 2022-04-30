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
		auto button = contentMainMenu->createButton("setting");
		button->rect.size = { 220, 60 };
		auto img = button->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		auto text = button->getComponent<UIText>();
		text->text = "Setting";

		auto buttonExit = contentMainMenu->createButton("exit");
		button->attachObject(buttonExit);
		buttonExit->rect.size = { 220, 60 };

		img = buttonExit->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		text = buttonExit->getComponent<UIText>();
		text->text = "Exit";
		auto comp = buttonExit->getComponent<Button>();
	}
}
void SceneMainMenu::exit() {

}
void SceneMainMenu::update() {
	
}
void SceneMainMenu::render() {
	//render gui
	GUI& gui = GUI::GetInstance();
	gui.render();
}