#include "Button.h"

Button::Button()
{
}

void Button::update()
{
}

void Button::bindOnClick(eventFunction refFunction)
{
	m_eventOnClick = refFunction;
}
