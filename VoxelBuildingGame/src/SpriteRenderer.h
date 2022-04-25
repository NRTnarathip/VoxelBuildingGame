#pragma once
#include "Physics/Transform.h"
#include "Sprite.h"
#include <glm/vec2.hpp>

class SpriteRenderer {
public:
	SpriteRenderer() {
		pivot = {0.5f, 0.5f};
	}
	Sprite *sprite = nullptr;
	Transform transform;
	glm::vec2 pivot;//range 0 -> 1
	void draw();
};