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
	auto contentMainMenu = menu->createContainer("mainmenu", { 960 ,540 }, { 440, 440});
	{
		auto button = contentMainMenu->createButton("play");
		button->rect.position = {220, 220};
		button->rect.size = {200, 40};
		printf("y%f \n", button->rect.position.y);
		auto img = button->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		auto text = button->getComponent<UIText>();
		text->text = "Play";

		button = contentMainMenu->createButton("setting");
		button->rect.size = { 200, 40 };
		button->rect.position = { 220, 220 };
		button->rect.position.y -= 40 + 20;
		img = button->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		text = button->getComponent<UIText>();
		text->text = "Setting";

		button = contentMainMenu->createButton("exit");
		button->rect.size = { 200, 40 };
		button->rect.position = { 220, 220 };
		button->rect.position.y -= (40 * 2) + 20*2;
		img = button->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		text = button->getComponent<UIText>();
		text->text = "Exit";
		auto comp = button->getComponent<Button>();
		//comp->bindOnClick(exit);
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