#pragma once
#include "SceneGame.h"
//forward
class Camera;

class SceneMainMenu : public SceneGame {
private:
	Camera* cameraCanvas = nullptr;
public:

	SceneMainMenu(std::string name) : SceneGame(name) {}
	void init();
	void update();
	void render();
};