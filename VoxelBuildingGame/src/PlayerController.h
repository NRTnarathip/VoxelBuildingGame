#pragma once
#include <ChunkManager.h>
#include <Component.h>

class PlayerController : public Component {
private:
	static PlayerController* instance;
public:
	PlayerController();
	static PlayerController* GetInstance();
	void init();
	void start();
	void update();
	float speedMove = 3.f;
	float speedRun = 64.f; 
	// Handles camera inputs
	void UpdateInputs();
};