#pragma once
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
class Bounding {
public:
	Bounding() {};
	float leftTop;
	float leftDown;
	float rightTop;
	float rightDown;
	void update(glm::vec2 position, glm::vec2 size, glm::vec2 pivot) {
		glm::vec2 offs = pivot * size;
		leftTop = position.y - offs.y;
		leftDown = position.x - offs.x;
		rightDown = leftDown + size.x;
		rightTop = leftTop + size.y;
	}
	glm::vec2 topos() {
		return glm::vec2(leftDown, leftTop);
	}
};
class AABB {
private:
	glm::vec2 position;
	glm::vec2 size;
	glm::vec2 pivot;
	Bounding bounding;
public:
	
	AABB() {}
	AABB(glm::vec2 pos, glm::vec2 s, glm::vec2 pv) {
		position = pos;
		size = s;
		pivot = pv;

		bounding.update(pos,s,pivot);
	}

	void setpivot(glm::vec2 newPivot) {
		pivot = newPivot;
		bounding.update(position, size, pivot);
	}
	void setpos(glm::vec2 newPos) {
		position = newPos;
		bounding.update(position, size, pivot);
	}
	void setsize(glm::vec2 s) {
		size = s;
		bounding.update(position, size, pivot);
	}
	void updatebounding() {
		bounding.update(position, size, pivot);
	};
	glm::vec2 getpos() const { return position; }
	glm::vec2 getsize() const { return size; }
	glm::vec2 getpivot() const { return pivot; }
	auto getbounding() const { return bounding; }

	bool isInSection(glm::vec2 pos) {
		if (bounding.rightDown >= pos.x and pos.x >= bounding.leftDown
			and bounding.rightTop >= pos.y and pos.y >= bounding.leftTop) {
			return true;
		}
		return false;
	}
};