#pragma once
#include <Game.h>
#include <GraphicSetting.h>
#include "TextRenderer.h"

class Input;

class ClientEngine {
private:
	static ClientEngine* instance;
public:
	ClientEngine() {
		instance = this;
	}
	//Singletons should not be cloneable.
	ClientEngine(ClientEngine& other) = delete;
	static ClientEngine& GetInstance() { return *instance; }

	GraphicSetting graphicSetting;
	Game* game = nullptr;
	Window* window = nullptr;
	Input* m_input = nullptr;
	TextRenderer* m_textRenderer = nullptr;
	ResourceManager* m_resouceManager = nullptr;
	int initialOpenGL();
	void launch();
	void exit();
};