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
	GUI& gui = GUI::GetInstance();
	auto res = ResourceManager::GetInstance();
	//setup button main menu
	/*menu = UIMenu::GetInstance();
	menu.CreateContainer();*/

	auto btnPlay = gui.newButton("play");
	btnPlay->setup({ 40, 40 }, { 80, 80 }, {.5f, .5f});
	btnPlay->title = "Play";
	btnPlay->spriteRender->sprite = res->m_sprites["bgMainMenu"];
	btnPlay->bindOnClick([]{
		printf("Hey test bind on click\n");
	});
}
void SceneMainMenu::update() {
	
}
void SceneMainMenu::render() {
	//render gui
	GUI& gui = GUI::GetInstance();
	gui.render();
}