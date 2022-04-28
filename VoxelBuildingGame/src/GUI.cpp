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
	Input& input = Input::GetInstance();
	//update polling event mouse button
	for (auto elemContent : m_menu->m_containers) {
		auto content = elemContent.second;
		for (auto elemButton : content->m_buttons) {
			auto btn = elemButton.second;
			btn->updateEventInput();
		}
	}
}
void GUI::render() {
	int winWidth, winHeight;
	glfwGetWindowSize(ClientEngine::GetInstance().window->glfwWindow, &winWidth, &winHeight);
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["sprite"];
	shaderSprite->Bind();

	projection = glm::mat4(1.f);
	projection = glm::ortho(0.f, (float)winWidth, 0.f, (float)winHeight);
	projection[2][2] = 1.f;
	shaderSprite->SetMat4("projection", projection);

	for (auto elemContain : m_menu->m_containers) {
		auto container = elemContain.second;
		float zOrder = (float)container->order / m_menu->m_containers.size();
		container->render(-zOrder);

		printf("gui render: %s\n", elemContain.first.c_str());
	}
	printf("gui end render\n\n");
}