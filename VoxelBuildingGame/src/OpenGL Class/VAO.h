#pragma once
#include <glad/glad.h>

class VAO {
private:
	unsigned int m_VAO;
public:
	void setupGL() {
		glGenVertexArrays(1, &m_VAO);//Vertex Array Object
	};
	void bind() {
		glBindVertexArray(m_VAO);
	}
	void unbind() {
		glBindVertexArray(0);
	}
};