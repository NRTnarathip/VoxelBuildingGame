#include <Component/GameObject.h>
#include <World.h>

template<typename T> 
void GameObject::addComponent<T>(T component) {
	World::GetInstance()->getRegistry().emplace<T>(m_entity);
};

template<typename T>
T& GameObject::getComponent<T>() {
	World::GetInstance()->getRegistry().get<T>(m_entity);
};

Transform* GameObject::getChildIndex(int index) {
	if (index >= childs.size()) { return nullptr; }
	return childs[index];
};