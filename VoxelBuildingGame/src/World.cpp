#include <World.h>
#include <Game.h>
#include "Physics/Transform.h"
#include <CameraManager.h>
#include <Component/GameObject.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <Component/GameObject.h>
#include "PlayerController.h"

World* World::instance = nullptr;
void World::init() {
	tickLastTime = Time::lastTime;

	Camera* mainCame = CameraManager::GetInstance().newCamera();
	CameraManager::GetInstance().switchCamera(mainCame);

	auto* player = spawnGameObject();
	player->addComponent<PlayerController>();

	auto* zombie = spawnGameObject();
	auto* zombie2 = spawnGameObject();
}
void World::tick() {

}
void World::update(float timeNow) {
	//update sun direction before render chunk
	/*Shader* def = Game::ref->shaders.defaultShader;
	def->Bind();
	def->SetVec3("sunDirect", lighting.sunDirect);
	def->SetFloat("sunIntensity", lighting.sunIntensity);*/
	if (timeNow - tickLastTime > tickUseTime) {
		tickLastTime = timeNow;
		tickCountter++;
		tick();
	}

	//update general component
	for (auto gameObject : m_gameObjects) {
		auto entityID = gameObject->getEntity();
		auto comps = gameObject->getAllComponents();
		for (auto c : comps) {
			c->update();
		}
	}
}

GameObject* World::spawnGameObject() {
	entt::entity newEntity = m_registry.create();
	auto* newGameobject = &m_registry.emplace<GameObject>(newEntity);
	newGameobject->setEntityID(newEntity);
	newGameobject->name ="New GameObject(" + std::to_string((uint32_t)newEntity) + ")";

	m_gameObjects.push_back(newGameobject);
	return newGameobject;
}
