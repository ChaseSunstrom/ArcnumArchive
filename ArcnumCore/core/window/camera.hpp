
#ifndef CORE_CAMERA_HPP
#define CORE_CAMERA_HPP

#include <glm.hpp>

namespace arcnum_core
{
	class camera
	{
	public: 			
		camera()  = default;
		~camera() = default;
		void camera_forward();
		void camera_backward();
		void camera_up();
		void camera_down();
		void camera_left();
		void camera_right();
		void rotate_camera();
	public:
		float       _camera_speed    = 2.5f;
		//           Y axis
		float       _pitch           = 30.0f;
		//           X axis
		float       _yaw             = 30.0f;
		//           Z axis
		float       _roll            = 30.0f;
		glm::vec3   _camera_position = glm::vec3(6.0f,  7.0f,  6.0f);
		glm::vec3   _camera_front    = glm::vec3(0.0f,  0.0f, -1.0f);
		glm::vec3   _camera_up		 = glm::vec3(0.0f,  1.0f,  0.0f);
		glm::vec3   _camera_view     = glm::vec3(0.0f,  0.0f,  0.0f);
		glm::vec3   _camera_offset   = glm::vec3(0.0f,  0.0f,  0.0f);
	};
}

#endif