#pragma once
#include "RectTransform.h"
#include "UIComponent.h"
#include "entt/entt.hpp"
#include <string>


class UIObject {
public:
	UIObject() {
		rect.m_uiObject = this;
	}
	std::string name = "Empty UI Object";
	entt::entity m_entity;
	entt::registry* g_registry = nullptr;
	RectTransform rect;

	template<typename TypeComponent>
	TypeComponent* addComponent(TypeComponent* component) {
		auto& newComponent = g_registry->emplace<TypeComponent>(m_entity, *component);
		newComponent.m_uiObject = this;
		return &newComponent;
	};
	template<typename TypeComponent>
	TypeComponent* getComponent() const {
		return &g_registry->get<TypeComponent>(m_entity);
	};
};