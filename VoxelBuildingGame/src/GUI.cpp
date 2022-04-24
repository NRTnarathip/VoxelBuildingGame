#include "GUI.h"

GUI GUI::m_instance;

GUI::GUI() {

}
Button* GUI::NewButton(std::string keyName, std::string title) {
	auto button = new Button();
	return button;
}