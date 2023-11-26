#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "camera.hpp"

namespace arcnum_core
{
    void camera::camera_forward()
    {
        this->_camera_position += this->_camera_speed * glm::vec3(_camera_front.x, 0.0f, _camera_front.z);
    }

    void camera::camera_backward()
    {
        this->_camera_position -= this->_camera_speed * glm::vec3(_camera_front.x, 0.0f, _camera_front.z);
    }

    void camera::camera_up()
    {
        // Move only in the y-axis (up)
        this->_camera_position += this->_camera_speed * glm::vec3(0.0f, 1.0f, 0.0f);
    }

    void camera::camera_down()
    {
        // Move only in the y-axis (down)
        this->_camera_position -= this->_camera_speed * glm::vec3(0.0f, 1.0f, 0.0f);
    }

    void camera::camera_left()
    {
        // Move in the direction perpendicular to the view plane
        this->_camera_position -= glm::normalize(glm::cross(this->_camera_front, this->_camera_up)) * this->_camera_speed;
    }

    void camera::camera_right()
    {
        // Move in the direction perpendicular to the view plane
        this->_camera_position += glm::normalize(glm::cross(this->_camera_front, this->_camera_up)) * this->_camera_speed;
    }

	void camera::rotate_camera()
	{
		glm::vec3 _default;
        glm::vec3 front;
        this->_camera_front.x = cos(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
        this->_camera_front.y = sin(glm::radians(this->_pitch));
        this->_camera_front.z = sin(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
        front.x = cos(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
        front.y = sin(glm::radians(this->_pitch));
        front.z = sin(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
        this->_camera_front   = glm::normalize(_default);
        this->_camera_offset  = front + this->_camera_position;
        this->_camera_offset.y -= 1;
	}
}