#pragma once
#include <Component/GameObject.h>
class Component : public GameObject {
private:
	GameObject* ref_gameObject;
public:
	virtual void init() {};
	virtual void update() {};
	virtual void draw() {};
};