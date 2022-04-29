#include "UIText.h"
#include "ResourceManager.h"
#include "TextRenderer.h"

void UIText::render() {
	auto tr = TextRenderer::GetInstance();
	tr->renderText("This is sample text", 250.0f, 250.0f, 1.0f, glm::vec3(1.f));
}