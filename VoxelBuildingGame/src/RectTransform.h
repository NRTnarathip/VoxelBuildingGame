#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class RectTransform {
private:
	glm::vec2 getoffs() {
		return pivot * getsize();
	}
public:
	glm::vec2 position{ 0, 0 };
	glm::vec2 pivot{ 0.5f, 0.5f };
	glm::vec2 size{ 100, 100 };//width, height
	glm::vec2 scale{ 1.f, 1.f };
	float rotation = 0.f;

	//Get Position : equation position * getoffs();
	glm::vec2 getpos() {
		return position - getoffs();
	}
	//Get Size Width, Height : equation size * scale;
	glm::vec2 getsize() {
		return size * scale;
	}
};