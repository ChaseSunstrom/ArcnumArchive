#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <glfw3.h>

#include "camera.hpp"

namespace arcnum_core
{
	void camera::move_camera()
	{
		this->_position = glm::vec3(0.0f, 0.0f, 3.0f);
		this->_target = glm::vec3(0.0f, 0.0f, 0.0f);
		this->_direction = glm::normalize(this->_position - this->_target);
		this->_up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->_camera_right = glm::normalize(glm::cross(this->_direction, this->_up));
		this->_camera_up = glm::cross(this->_direction, this->_camera_right);
		glm::mat4 view;
		view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f));
		const float radius = 10.0f;
		float camX = sin(glfwGetTime()) * radius;
		float camZ = cos(glfwGetTime()) * radius;
		view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
	}
}