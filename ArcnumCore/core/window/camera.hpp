
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
		void camera_up();
		void camera_down();
		void camera_left();
		void camera_right();
	public:
		float       _camera_speed    = 2.5f;
		glm::vec3   _camera_position = glm::vec3(0.0f,  0.0f,  3.0f);
		glm::vec3   _camera_front    = glm::vec3(0.0f,  0.0f, -1.0f);
		glm::vec3   _camera_up		 = glm::vec3(0.0f,  1.0f,  0.0f);
	};
}

#endif