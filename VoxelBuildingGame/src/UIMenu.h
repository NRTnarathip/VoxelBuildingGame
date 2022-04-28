#pragma once
#include <glm/vec2.hpp>
#include <map>
#include <string>
#include <vector>
#include "Button.h"
#include "UIContainer.h"

class UIMenu {
private:
	static UIMenu* m_instance;
public:
	UIMenu() {
		m_instance = this;
	}
	std::map<std::string, UIContainer*> m_containers;

	static auto GetInstance() { return m_instance; }
	UIContainer* createContainer(std::string containerName, glm::vec2 pos, glm::vec2 size);
};