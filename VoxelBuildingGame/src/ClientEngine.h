#pragma once


#include <Game.h>
#include <GraphicSetting.h>

class ClientEngine {
private:
	static ClientEngine* refThis;
public:
	ClientEngine();
	static ClientEngine* GetInstance();
	GraphicSetting graphicSetting;
	Game* game = nullptr;
	Window* window = nullptr;
	int initialOpenGL();
	int initialShader();

	void launch();
	void exit();
};