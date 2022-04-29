#include "UIMenu.h"
#include <glm/glm.hpp>
#include "ResourceManager.h"

UIMenu* UIMenu::m_instance = nullptr;

UIContainer* UIMenu::createContainer(std::string containerName, glm::vec2 pos, glm::vec2 size) {
	auto newContainer = new UIContainer();
	newContainer->m_uiObject->rect.position = pos;
	newContainer->m_uiObject->rect.size = size;
	newContainer->order = m_containers.size();

	m_containers.emplace(containerName, newContainer);
	return newContainer;
}
