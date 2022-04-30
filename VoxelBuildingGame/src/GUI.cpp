#include "GUI.h"
#include "ClientEngine.h"
#include "Input.h"

GUI* GUI::m_instance = nullptr;

GUI::GUI(GLFWwindow* window) {
	m_instance = this;

	m_menu = new UIMenu();
	this->window = window;
}
glm::vec2 GUI::getWindowSize()
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	return glm::vec2(width, height);
}
void GUI::updateEventInput() {
	//update polling event mouse button
	for (auto elemContent : m_menu->m_containers) {
		auto content = elemContent.second;
		for (auto button : content->m_buttons) {
			button->updateEventInput();
		}
	}
}
//update value shader and renderer all UIContainer
void GUI::render() {
	//gl renderer for 2D;
	glDisable(GL_DEPTH_TEST);

	auto winSize = getWindowSize();
	projection = glm::mat4(1.f);
	projection = glm::ortho(0.f, winSize.x, 0.f, winSize.y);
	projection[2][2] = 1.f;

	auto res = ResourceManager::GetInstance();

	auto shaderSprite = res->m_shaders["sprite"];
	auto shText = res->m_shaders["text"];

	shaderSprite->Bind();
	shaderSprite->SetMat4("projection", projection);

	shText->Bind();
	shText->SetMat4("projection", projection);

	for (auto elemContain : m_menu->m_containers) {
		auto container = elemContain.second;
		for (auto rectUIObject : container->rect.childs) {
			rectUIObject->m_uiObject->render();
		}
	}

	//gui renderer for 3D;
	glEnable(GL_DEPTH_TEST);
}

UIObject* GUI::createUIObject() {
	auto entity = registry.create();
	auto newObject = new UIObject();
	newObject->g_registry = &registry;
	newObject->m_entity = entity;
	m_UIObjectHierarchy.push_back(newObject);
	return newObject;
}