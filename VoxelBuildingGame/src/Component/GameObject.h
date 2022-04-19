#pragma once
#include "Component/Component.h"
#include "Physics/Transform.h"
#include <string>
#include <list>
#include <vector>
#include <entt/entity/entity.hpp>
#include <Component/Object.h>
#include <World.h>

class GameObject {
private:
	std::vector<Transform*> childs;
	Transform* parent;
	entt::entity m_entity;
public:
	std::string name;
	Transform transform;
public:
	template<typename T>
	void addComponent<T>(T component);

	template<typename T>
	T& getComponent<T>();

	Transform* getParent() { return parent; };
	Transform* getChildIndex(int index);
};
