#pragma once
#include "Physics/Transform.h"
#include "Sprite.h"

class SpriteRenderer {
public:
	Sprite *sprite = nullptr;
	Transform transform;
	void draw();
};