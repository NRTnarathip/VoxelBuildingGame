#include <PlayerController.h> 
#include <Game.h>
#include "glm/gtx/string_cast.hpp"
#include <GraphicSetting.h>
#include <ClientEngine.h>

PlayerController* PlayerController::refThis = NULL;

PlayerController* PlayerController::GetInstance() {
	return refThis;
}

void PlayerController::init() {
	entity->mesh = new Mesh();
	refThis = this;
}
void PlayerController::start() {
}
void PlayerController::update() { //update every frame on ECS
	UpdateInputs();

	//update camera pos
	camera->Postition = entity->transform.position;
	camera->UpdateMatrix();
}

void PlayerController::UpdateInputs()
{
	auto window = Game::ref->window->glfwWindow;
	auto mouseClickUseCamera = GLFW_MOUSE_BUTTON_RIGHT;
	glm::vec3 &posEntity = entity->transform.position;

	float speed = speedMove;
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speed = speedRun;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		speed = speedMove;
	}

	// Handles key inputs
	speed *= (float)Time::deltaTime;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		posEntity += speed * camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		posEntity += speed * glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		posEntity += speed * -camera->Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		posEntity += speed * -glm::normalize(glm::cross(camera->Orientation, camera->Up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		posEntity += speed * camera->Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		posEntity += speed * -camera->Up;
	}

	
	// Handles mouse inputs
	if (glfwGetMouseButton(window, mouseClickUseCamera) == GLFW_PRESS)
	{
		// Hides mouse cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Prevents camera from jumping on the first click
		if (camera->firstClick)
		{
			glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
			camera->firstClick = false;
		}

		// Stores the coordinates of the cursor
		double mouseX;
		double mouseY;
		// Fetches the coordinates of the cursor
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = camera->sensitivity * (float)(mouseY - (camera->height / 2)) / camera->height;
		float rotY = camera->sensitivity * (float)(mouseX - (camera->width / 2)) / camera->width;

		// Calculates upcoming vertical change in the Orientation
		glm::vec3 newOrientation = glm::rotate(camera->Orientation, glm::radians(-rotX), glm::normalize(glm::cross(camera->Orientation, camera->Up)));

		// Decides whether or not the next vertical Orientation is legal or not
		if (abs(glm::angle(newOrientation, camera->Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			camera->Orientation = newOrientation;
		}

		// Rotates the Orientation left and right
		//test
		camera->Orientation = glm::rotate(camera->Orientation, glm::radians(rotY), camera->Up);

		// Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
		glfwSetCursorPos(window, (camera->width / 2), (camera->height / 2));
	}
	else if (glfwGetMouseButton(window, mouseClickUseCamera) == GLFW_RELEASE)
	{
		// Unhides cursor since camera is not looking around anymore
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Makes sure the next time the camera looks around it doesn't jump
		camera->firstClick = true;
	}

	
}
