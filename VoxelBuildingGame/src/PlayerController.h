#pragma once
#include <ECS.h>
#include <World.h>
#include <Camera.h>
#include <ChunkManager.h>
#include <GenerateMeshChunk.h>
class PlayerController : public Component {
private:
	static PlayerController* refThis;
public:
	static PlayerController* GetInstance();
	Camera* camera = nullptr;
	void init();
	void start();
	void update();
	float speedMove = 3.f;
	float speedRun = 64.f; 
	// Handles camera inputs
	void UpdateInputs();
	World* world = nullptr;
};