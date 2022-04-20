#pragma once
#include <glad/glad.h>

class HelperBufferObject {
public:
	unsigned int m_ID;
	void genBuffer() {
		glGenBuffers(1, &m_ID);//element Buffer Object
	}
};
class VBO {
private:
	HelperBufferObject m_VBO;
public:
	void setupGL() {
		m_VBO.genBuffer();
	}
	void bind() {
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO.m_ID);
	}
	void bufferData(GLsizeiptr size, const void* data, GLenum usage) {
		glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	}
};

class EBO {
private:
	HelperBufferObject m_EBO;
public:
	void setupGL() {
		m_EBO.genBuffer();
	}
	void bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO.m_ID);
	}
	void bufferData(GLsizeiptr size, const void* data, GLenum usage) {
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
	}
};