#include <World.h>
#include <Game.h>

World* World::ref = nullptr;

void World::init() {
	ref = this;
}
void World::start() {
	tickLastTime = Time::lastTime;
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
