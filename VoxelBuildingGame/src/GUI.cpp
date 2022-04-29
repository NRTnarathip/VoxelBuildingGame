#include "GUI.h"
#include "ClientEngine.h"
#include "Input.h"

GUI GUI::m_instance;

GUI::GUI() {
	m_menu = new UIMenu();
}
glm::vec2 GUI::getWindowSize()
{
	int width, height;
	glfwGetWindowSize(ClientEngine::GetInstance().window->glfwWindow, &width, &height);
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
	int winWidth, winHeight;
	glfwGetWindowSize(ClientEngine::GetInstance().window->glfwWindow, &winWidth, &winHeight);
	projection = glm::mat4(1.f);
	projection = glm::ortho(0.f, (float)winWidth, 0.f, (float)winHeight);
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
		float zOrder = (float)container->order / m_menu->m_containers.size();
		container->render(-zOrder);
	}
}