#include "Window.h"
#include <iostream>

Window* Window::m_instance = nullptr;

Window::Window(const char* title) {
	m_instance = this;
	this->title = title;
	this->window = window;
}
Window* Window::GetInstance() {
	return m_instance;
}
void Window::onWindowResize(int width,int height) {
	this->width = width;
	this->height = height;
	//printf("window resize width:%d height:%d\n", width, height);
}