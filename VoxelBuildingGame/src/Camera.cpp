#include <Camera.h>
#include <Game.h>
#include <Renderer/shaderClass.h>
#include "glm/gtx/string_cast.hpp"

void Camera::setupCamera(GLFWwindow* window, float FOVdeg, float nearPlane, float farPlane) {
	
	this->FOVdeg = FOVdeg;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	this->window = window;
	//		 ______Y+_Z-_______
	//		/	   | /       /
	//	   /       |/       /
	//	  X+-------/-------X-
	//   /        /|      /
	//	/	     / |     / 
	// /        /Y-|    /
	// /-------Z+--------
	//default coordinate system opengl it right hand
	// x+ on left
	// x- on right                    
	// z+ on near                    
	// z- on far
	// y+ on top
	// y- on down
	// Convert Coordinate system to left hand
	//change Invert axis X,Z From Left To Right In Matrix Projection;
	//set up projection one on init
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / (float)height, nearPlane, farPlane);
	projection[0][0] *= -1;//invert project axis X
	Shader* shader = Game::GetInstance()->shaders.defaultShader;
	shader->Bind();
	shader->SetMat4("projection", projection);
	shader->UnBind();
};
void Camera::switchMode(bool isPerspective) {
	if (isPerspective) {
		
	}
	else {

	}
}
