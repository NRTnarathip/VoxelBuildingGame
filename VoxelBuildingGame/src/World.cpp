#include <World.h>
#include <Game.h>
#include "Physics/Transform.h"
#include <CameraManager.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <GameObject.h>
#include "PlayerController.h"
#include "Physics/BoxCollision.h"


World* World::instance = nullptr;
void World::init() {
	tickLastTime = Time::lastTime;

	Camera* mainCame = CameraManager::GetInstance().newCamera();
	CameraManager::SwitchCamera(mainCame);

	auto* player = spawnGameObject();
	player->transform.position = glm::vec3(0,85,0);
	player->addComponent<PlayerController>();
	auto* boxCollision = player->addComponent<BoxCollision>();

	auto* zombie = spawnGameObject();
	auto* zombie2 = spawnGameObject();

	//update general component
	for (auto gameObject : m_gameObjects) {
		auto comps = gameObject->getAllComponents();
		for (auto c : comps) {
			c->init();
		}
	}
}
void World::tick() {
	////update general component
	//for (auto gameObject : m_gameObjects) {
	//	auto comps = gameObject->getAllComponents();
	//	for (auto c : comps) {
	//		c->tick();
	//	}
	//}
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
