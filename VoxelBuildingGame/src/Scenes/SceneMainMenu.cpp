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
	auto contentMainMenu = menu->createContainer("mainmenu", { 960 ,540 }, { 980, 750 });

	auto buttonPlay = contentMainMenu->createButton("play");
	buttonPlay->rect.size = {200,40};
	auto imageBtnPlay = buttonPlay->getComponent<Image>();
	imageBtnPlay->sprite = res->m_sprites["button_0"];

	/*btnPlay->setup({ 40, 40 }, { 80, 80 });
	btnPlay->title = "Play";
	btnPlay->bindOnClick([]{
		printf("Click Play\n");
	});*/

}
void SceneMainMenu::update() {
	
}
void SceneMainMenu::render() {
	//render gui
	GUI& gui = GUI::GetInstance();
	gui.render();
}