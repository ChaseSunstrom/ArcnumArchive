#include <glm.hpp>

#include "camera.hpp"

namespace arcnum_core
{
	void camera::camera_up()
	{
		this->_camera_position += this->_camera_speed * glm::vec3(0.0f, 1.0f, 0.0f);
	}

	void camera::camera_down()
	{
		this->_camera_position -= this->_camera_speed * glm::vec3(0.0f, 1.0f, 0.0f);
	}

	void camera::camera_left()
	{
		this->_camera_position -= glm::normalize(glm::cross(this->_camera_front, this->_camera_up)) * this->_camera_speed;
	}

	void camera::camera_right()
	{
		this->_camera_position += glm::normalize(glm::cross(this->_camera_front, this->_camera_up)) * this->_camera_speed;
	}
}