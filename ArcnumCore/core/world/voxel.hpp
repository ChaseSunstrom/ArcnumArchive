#ifndef CORE_VOXEL_HPP
#define CORE_VOXEL_HPP

#include <vector>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

#include "shader.hpp"
#include "texture.hpp"
#include "texture_type.hpp"
#include "entity_type.hpp"
#include "color.hpp"
#include "../util/macros.hpp"

namespace arcnum_core
{
	class voxel
	{
	public:
		voxel(world_position world_pos, texture_type texture_type, color_type color, entity_type entity_type);
		~voxel();
		void attach_shaders();
	public:
		shader*            _shader;
		texture*           _texture;
		GLuint             _shader_program;
		texture_type       _texture_type;
		color_type         _color;
		entity_type        _entity_type;
		glm::vec3          _position        = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3          _rotation        = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3          _scale           = glm::vec3(1.0f, 1.0f, 1.0f);
		std::vector<float> _vertices;
	};

	texture_type get_entity_type_from_string(std::string string);
}

#endif