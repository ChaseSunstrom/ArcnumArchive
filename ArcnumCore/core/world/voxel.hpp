#ifndef CORE_VOXEL_HPP
#define CORE_VOXEL_HPP

#include <vector>

#include <glm.hpp>

namespace arcnum_core
{
	class voxel
	{
	public:
		voxel(float x_position, float y_position, float z_position);
		~voxel();
	public:
		glm::vec3          _position = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3          _rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3          _scale    = glm::vec3(1.0f, 1.0f, 1.0f);
		std::vector<float> _vertices;
	};
}

#endif