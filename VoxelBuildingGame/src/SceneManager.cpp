#include "SceneManager.h"
#include <iostream>

SceneManager* SceneManager::instance = nullptr;

void SceneManager::init() {
	for (auto scene : m_scenes) {
		if (scene->isActive() == false) {
			continue;
		}
		scene->init();
	}
}
void SceneManager::addExistScene(SceneGame* scene) {
	scene->index = m_scenes.size();


	if (m_scenes.empty()) {
		scene->setActive(true);
	}
	m_scenes.push_back(scene);
}
void SceneManager::beforeUpdate() {
	for (auto scene : m_scenes) {
		if (scene->isActive() == false) {
			continue;
		}
		scene->beforeUpdate();
	}
}
void SceneManager::lastUpdate() {
	for (auto scene : m_scenes) {
		if (scene->isActive() == false) {
			continue;
		}
		scene->lastUpdate();
	}
}
void SceneManager::update() {
	for (auto scene : m_scenes) {
		if (scene->isActive() == false) {
			continue;
		}
		scene->update();
	}
}
void SceneManager::render() {
	for (auto scene : m_scenes) {
		if (scene->isActive() == false) {
			continue;
		}
		scene->render();
	}
}