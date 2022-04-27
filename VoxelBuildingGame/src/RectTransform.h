#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class RectTransform {
public:
	glm::vec2 position{ 0, 0 };
	glm::vec2 pivot{ 0.5f, 0.5f };
	glm::vec2 size{ 240, 40 };//width, height
	glm::vec2 scale{ 1.f, 1.f };
	float rotation = 0.f;
};