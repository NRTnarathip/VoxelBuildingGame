#pragma once
#include "SceneGame.h"
#include <vector>
#include <iostream>

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
	template<typename T>
	T* getScene(int index) {
		return dynamic_cast<T*>(m_scenes[index]);
	};
	void addExistScene(SceneGame* scene);
};