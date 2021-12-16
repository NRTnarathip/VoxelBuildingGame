#include <World.h>
#include <Game.h>

World* World::ref = nullptr;

void World::init() {
	ref = this;
}
void World::start() {

}
void World::tick() {
	printf("tick world\n");
}
void World::update() {
	//update sun direction before render chunk
	Shader* def = Game::ref->shaders.defaultShader;
	def->Bind();
	def->SetVec3("sunDirect", lighting.sunDirect);
	def->SetFloat("sunIntensity", lighting.sunIntensity);

	float now = Game::ref->GetTime();
	if (now - tickLastTime > tickUseTime) {
		tickLastTime = now;
		tickCountter++;

		tick();
	}

}
