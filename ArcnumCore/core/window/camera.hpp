
#ifndef CORE_CAMERA_HPP
#define CORE_CAMERA_HPP

#include <glm.hpp>

namespace arcnum_core
{
	class camera
	{
	public: 			
		camera() = default;
		~camera() = default;

		void move_camera();
	public:
		glm::vec3 _position;
		glm::vec3 _target;
		glm::vec3 _direction;
		glm::vec3 _up;
		glm::vec3 _camera_right;
		glm::vec3 _camera_up;
	};
}

#endif