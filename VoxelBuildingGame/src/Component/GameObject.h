#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Physics/Transform.h"
#include <string>
#include <vector>
#include <entt/entt.hpp>
#include "ComponentManager.h"

class ComponentManager;

class GameObject {
private:
	std::vector<Transform*> childs;
	Transform* parent;
	entt::entity m_entity;
	entt::registry* g_registry;
	std::vector<Component*> m_components;
public:
	GameObject();
	std::string name;
	Transform transform;
public:
	template<typename TypeComponent>
	TypeComponent* addComponent() {
		auto &newComponent = g_registry->emplace<TypeComponent>(m_entity);
		m_components.push_back(&newComponent);
		//ComponentManager::GetInstance()->components.push_back(&newComponent);
		return &newComponent;
	};
	template<typename TypeComponent>
	TypeComponent* getComponent() const {
		return g_registry->get<TypeComponent>(m_entity);
	};
	std::vector<Component*> getAllComponents() {
		return m_components;
	}
	Transform* getParent() const { return parent; };
	Transform* getChildIndex(int index) const;

	void setEntityID(entt::entity id) { m_entity = id; };
	entt::entity getEntity() const { return m_entity; }
};

#endif
