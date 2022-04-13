#include <Camera.h>
#include <Game.h>
#include <Renderer/shaderClass.h>
#include "glm/gtx/string_cast.hpp"

void Camera::InitCamera(GLFWwindow* window,int width, int height, float FOVdeg, float nearPlane, float farPlane) {
	this->width = width;
	this->height = height;
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
	//change Invert axis X From Left To Right In Matrix Projection;
	// X-       X+
	//set up projection one on init
	Shader* shader = Game::GetInstance()->shaders.defaultShader;
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / (float)height, nearPlane, farPlane);
	projection[0][0] *= -1;//invert project axis X

	shader->Bind();
	shader->SetMat4("projection", projection);
};
void Camera::UpdateMatrix() const
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::lookAt(Postition, Postition + Orientation, Up);
	
	// Exports the camera matrix to the Vertex Shader
	Shader* shader = Game::GetInstance()->shaders.defaultShader;
	shader->Bind();
	shader->SetMat4("view",view);
}