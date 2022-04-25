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
	auto btnPlay = gui.newButton("play");
	auto winsize = gui.getWindowSize();
	btnPlay->init( {80, 80}, { 80, 80 });
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