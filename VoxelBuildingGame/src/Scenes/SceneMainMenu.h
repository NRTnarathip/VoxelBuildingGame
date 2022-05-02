#pragma once
#include "SceneGame.h"

//forward
class Camera;

class SceneMainMenu : public SceneGame {
public:
	SceneMainMenu(std::string name) : SceneGame(name) {}
	void setupMainMenu();

	void init();
	void update();
	void render();

	void exit();
};