#include "GUI.h"
#include "ClientEngine.h"
#include "Input.h"

GUI GUI::m_instance;

GUI::GUI() {

}
Button* GUI::newButton(std::string keyName) {
	auto res = ResourceManager::GetInstance();
	auto btn = new Button();
	btn->spriteRender = new SpriteRenderer();
	m_buttons.emplace(keyName, btn);
	return btn;
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
	for (auto elem : m_buttons) {
		auto button = elem.second;
		button->updateEventInput();
	}
}
void GUI::render() {
	int winWidth, winHeight;
	glfwGetWindowSize(ClientEngine::GetInstance().window->glfwWindow, &winWidth, &winHeight);
	auto res = ResourceManager::GetInstance();
	auto shaderSprite = res->m_shaders["sprite"];
	shaderSprite->Bind();
	auto projOrtho = glm::mat4(1.f);
	projOrtho = glm::ortho(0.f, (float)winWidth, 0.f, (float)winHeight);
	shaderSprite->SetMat4("projection", projOrtho);
	for (auto elem : m_buttons) {
		auto button = elem.second;
		auto spriteRender = button->spriteRender;

		auto pos = button->getpos();
		auto size = button->getsize();

		auto model = glm::mat4(1.f);
		model = glm::translate(model, glm::vec3(pos, 0.f));
		model = glm::scale(model, glm::vec3(size, 1.f));
		shaderSprite->SetMat4("model", model);
		spriteRender->draw();
	}
}