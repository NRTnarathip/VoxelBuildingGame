#pragma once
#include <ChunkManager.h>
#include <ECS.h>

class Lighting {
public:
	glm::vec3 sunDirect = glm::vec3(0.f, -1.f, 0.f);
	float sunIntensity = 1.0f;
};
class World {
private:
	//update 20 tick per 1 second;
	//1 tick use 1000/20;s, 50 second per tick
	int tickRate = 40;
	// 0.025 second
	const float tickUseTime = 1.f / tickRate;
	unsigned int tickCountter = 0;
	
	float tickLastTime =0.f;
public:
	static World* ref;
	Entity* refClient = nullptr;
	//base func
	void init();
	void start();
	void tick();
	void update(float timeNow);//update every frame
	Lighting lighting;
};