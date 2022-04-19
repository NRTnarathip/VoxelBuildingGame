#pragma once
#include <ChunkManager.h>
#include "entt/entt.hpp"

class Lighting {
public:
	glm::vec3 sunDirect = glm::vec3(0.f, -1.f, 0.f);
	float sunIntensity = 1.0f;
};
class World {
private:
	static World* instance;
	//update 20 tick per 1 second;
	//1 tick use 1000/20;s, 50 second per tick
	int tickRate = 40;
	// 0.025 second
	const float tickUseTime = 1.f / tickRate;
	unsigned int tickCountter = 0;
	
	float tickLastTime =0.f;

	//entity system component
	entt::registry m_registry;
public:
	World() { instance = this; }
	static World* GetInstance() { return instance; }
	//base func
	void init();
	void start();
	void tick();
	void update(float timeNow);//update every frame

	//entity system
	entt::registry& getRegistry() { return m_registry; }
	GameObject& spawnGameObject();
	const entt::entity& addEntity(const char* entityName);
	Lighting lighting;

};