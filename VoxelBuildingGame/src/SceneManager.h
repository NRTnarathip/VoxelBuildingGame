#pragma once
#include "SceneGame.h"
#include <vector>

class SceneManager {
private:
	static SceneManager* instance;
	std::vector<SceneGame*> m_scenes;
public:// Singleton
	SceneManager() { instance = this; }
	static SceneManager* GetInstance() { return instance; }
public:
	void switchScene(int index);
	void init();
	void beforeUpdate();
	void update();
	void lastUpdate();
	void render();
	SceneGame* getScene(int index);
	void addExistScene(SceneGame* scene);
};