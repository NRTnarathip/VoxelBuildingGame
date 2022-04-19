#include <World.h>
#include <Game.h>
#include "Physics/Transform.h"
#include <CameraManager.h>
#include <Component/GameObject.h>
#include <iostream>
#include <string>
#include <stdio.h>

World* World::instance = nullptr;
void World::init() {

}
void World::start() {
	tickLastTime = Time::lastTime;

	Camera* mainCame = CameraManager::GetInstance().newCamera();
	CameraManager::GetInstance().switchCamera(mainCame);

	auto player = registry.create();
	
	//Transform transform;
	auto gameObject = registry.emplace<GameObject>(player);
	gameObject.name = "Player";
	registry.emplace<Camera*>(player, mainCame);
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
}

const entt::entity& World::addEntity(const char* entityName) {
	const auto& entity = registry.create();
	registry.emplace<Transform>(entity);
	return entity;
}

GameObject& World::spawnGameObject() {
	entt::entity newEntity = m_registry.create();
	auto newGameobject = m_registry.emplace<GameObject>(newEntity);
	newGameobject.name ="New GameObject(" + std::to_string((uint32_t)newEntity) + ")";
	return newGameobject;
}
