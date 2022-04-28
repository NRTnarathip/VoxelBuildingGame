#pragma once
class UIObject;

class UIComponent {
public:
	UIObject* m_uiObject = nullptr;
	virtual void updateEventInput() {
		printf("update event input base class\n");
	};
	virtual void update() {};
	void render() {};
};