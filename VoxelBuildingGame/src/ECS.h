#pragma once
#include <iostream>
#include <bitset>
#include <memory>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <Renderer/shaderClass.h>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <Mesh.h>

class Component;
class Entity;
class Transform;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() {
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
private:
	bool active = true;
public:
	bool isActive() { return active; }
	bool SetActive(bool v) { active = v; }
	//Referance Entity
	Entity* entity = nullptr;
	//For Initial When Entity Has Load Or Create Like Awak
	virtual void init() {};
	//run when run before first frame
	virtual void start() {};
	//Update General
	virtual void update() {}; 
	//Update physic, Collision Box,Sphere,Rigidbody
	virtual void updatePhysic() {};
	virtual void lastUpdate() {};
	virtual void render() {};
	virtual ~Component() {};
};

class Transform {
public:
	Entity* parent = nullptr;
	glm::vec3 position = glm::vec3(0.0f,0.f,0.f);
	glm::vec3 rotation = glm::vec3(0.0f,0.f,0.f);
	glm::vec3 scale = glm::vec3(1.0f);
	float angle = 0.f;
	float rotate = 0.f;
};
class Entity {
private:
	bool needDestroy = false;
	std::string name ="New Object";
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;
	ComponentBitSet componentBitSet;
	ComponentArray componentArray = {};
public:
	Mesh* mesh = nullptr;
	Transform transform;
	Shader* shader = nullptr;
	std::string GetName() const { return name; };
	void SetName(std::string newName) { name = newName;  };
	//don't care if it's active or not active
	//run before start()
	void InitComponentAll() {
		for (auto& c : components) {
			c->init();
		}
	};
	void StartComponentAll() {
		for (auto& c : components) {
			c->start();
		}
	}
	void UpdatePhysicAll() {
		for (auto& c : components) {
			c->updatePhysic();
		}
	}
	void UpdateComponentAll() {
		for (auto& c : components) {
			c->update();
		}
	}
	void LastUpdateAll() {
		for (auto& c : components) {
			c->lastUpdate();
		}
	};
	bool IsNeedDestroy() {
		return needDestroy;
	}
	void Render();
	bool IsActive() const { return active; }
	bool Destroy() {
		active = false; 
		needDestroy = true;
	}

	template <typename T> bool hasComponent() const {
		return componentBitSet[getComponentTypeID<T>];
	}
	template <typename T,typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;
		return *c;
	}
	template<typename T> T& getComponent() const {
		auto ptr(componentArray[getComponentTypeID<T>() ]);
		return *static_cast<T*>(ptr);
	}
}; 
class Scene {
private:
	const char *name = "New Scene";
public:
	Scene(const char* sceneName) {
		name = sceneName;
	};
	void initComponentAll() {
		for (auto& e : entities) {
			e->InitComponentAll();
		}
	};

	void startComponentAll() {
		for (auto& e : entities) {
			if (e->IsActive()) {
				e->StartComponentAll();
			}
		}
	}
	void lastUpdateComponentAll() {
		for (auto& e : entities) {
			if (e->IsActive())
				e->LastUpdateAll();
		}
	}
	void updateComponentAll() {
		for (auto& e : entities) {
			e->UpdateComponentAll();
		}
	};
	void updatePhysicAll() {
		for (auto& e : entities) {
			e->UpdatePhysicAll();
		}
	};
	void renderEntity() {
		for (auto& e : entities) {
			if (e->IsActive()) {
				e->Render();
			}
		}
	}
	std::vector<std::unique_ptr<Entity>> entities;
	void checkDestroyEntity() {
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[] (const std::unique_ptr<Entity>& mobject) {
				return !mobject->IsActive();
			}), std::end(entities));
	}
	Entity& addGameObject(std::string name) {
		Entity* obj = new Entity();
		std::unique_ptr<Entity> uPtr{ obj };
		entities.emplace_back(std::move(uPtr));
		obj->SetName(name);
		return *obj;
	}
};
