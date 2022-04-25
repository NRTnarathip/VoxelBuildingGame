#pragma once
#include <glm/vec2.hpp>

class AABB {
public:
	AABB() {}
	AABB(glm::vec2 pos, glm::vec2 s) {
		position = pos;
		size = s;
	}
	glm::vec2 position;
	glm::vec2 size;
	bool isInSection(glm::vec2 pos) {
		if (position.x + size.x >= pos.x and pos.x >= position.x
			and position.y + size.y >= pos.y and pos.y >= position.y) {
			return true;
		}
		return false;
	}
	bool isInSection(AABB other) {
		if (position.x + size.x >= other.position.x and other.position.x + other.size.x >= position.x
			and position.y + size.y >= other.position.y and other.position.y + other.size.y >= position.y) {
			return true;
		}
		return false;
	}
};