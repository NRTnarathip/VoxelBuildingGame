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
	auto contentMainMenu = menu->createContainer("mainmenu", { 0 ,0 }, { 800, 600});
	contentMainMenu->rect.position.y = -140.f;
	{
		auto button = contentMainMenu->createButton("play");
		button->rect.size = { 220, 60 };
		button->rect.position = { 0, 80 };
		auto img = button->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		auto text = button->getComponent<UIText>();
		text->text = "Play";
		button->swapOrderComponent(img, text);
		button->swapOrderComponent(img, text);

		button = contentMainMenu->createButton("setting");
		button->rect.size = { 220, 60 };
		img = button->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		text = button->getComponent<UIText>();
		text->text = "Setting";


		auto buttonExit = contentMainMenu->createButton("exit");
		buttonExit->rect.size = { 220, 60 };
		buttonExit->rect.position = { 0, -80 };
		img = buttonExit->getComponent<Image>();
		img->sprite = res->getSprite("gui/button_0");
		text = buttonExit->getComponent<UIText>();
		text->text = "Exit";
		auto cButton = buttonExit->getComponent<Button>();
		//cButton->bindOnClick(exit);
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