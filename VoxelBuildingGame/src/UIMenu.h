#pragma once
class UIMenu {
private:
	static UIMenu* m_instance;
public:
	UIMenu() {
		m_instance = this;
	}


};