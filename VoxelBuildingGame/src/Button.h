#pragma once
class Button {
private:
	typedef void(*eventFunction)();
	eventFunction m_eventOnClick;
public:
	Button();
	void update();
	void bindOnClick(eventFunction refFunction);
};