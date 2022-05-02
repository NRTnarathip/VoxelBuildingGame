#pragma once
#include <string>
#include "entt/entt.hpp"
#include <iostream>


class SceneGame {
private:
	bool m_active = false;
public:
	SceneGame();
	SceneGame(std::string sceneNam);
	std::string name = "Unknow Scene";
	unsigned int index = 0;
	void setActive(bool state) {
		m_active = state;
	};
	bool isActive() const { return m_active; }
	virtual void init() {};
	virtual void beforeUpdate() {};
	virtual void update() {};
	virtual void lastUpdate() {};
	virtual void render() {};
public:
	entt::registry registry;
};