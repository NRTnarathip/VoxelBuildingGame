#pragma once
#include "UIObject.h"
#include "SpriteRenderer.h"
#include "RectTransform.h"
#include <glm/vec4.hpp>
#include "UIComponent.h"

class Image : public UIComponent, public SpriteRenderer {
public:
	Image() {}
	Image(Sprite* ref) : SpriteRenderer(ref) { }

};