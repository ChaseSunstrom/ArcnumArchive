#include <cstdint>
#include <filesystem>
#include <cstdlib>
#include <thread>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "texture_type.hpp"
#include "entity_type.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "color.hpp"
#include "../window/camera.hpp"
#include "../util/macros.hpp"

#include "entity.hpp"

namespace arcnum_core
{
	entity::entity(world_position world_pos, texture_type texture_type, color_type color, entity_type entity_type)
	{
		this->_shader_program = glCreateProgram();
		switch (texture_type)
		{
		case texture_type::NONE:
			switch (entity_type)
			{
			case entity_type::LIGHT:
				this->_shader = new shader(std::filesystem::absolute("ArcnumCore/shaders/color_shader.vsl"), std::filesystem::absolute("ArcnumCore/shaders/light_shader.fsl"));
				break;
			default:
				this->_shader = new shader(std::filesystem::absolute("ArcnumCore/shaders/color_shader.vsl"), std::filesystem::absolute("ArcnumCore/shaders/color_shader.fsl"));
				break;
			}
			break;
		default:
			this->_shader = new shader(std::filesystem::absolute("ArcnumCore/shaders/texture_shader.vsl"), std::filesystem::absolute("ArcnumCore/shaders/texture_shader.fsl"));
			break;
		}
		this->_texture_type = texture_type;
		this->_color_type = color;
		this->_entity_type = entity_type;
		this->_position = world_pos;

		this->_vertices = {
			//position           //color           //texture
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //bottom left
			 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, //bottom right
			 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, //top right
			 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, //top right
			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, //top left
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //bottom left

			-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
		};

		this->attach_shaders();
	}

	entity::~entity()
	{
		delete this->_shader;
		glDeleteProgram(this->_shader_program);
	}

	void entity::attach_shaders()
	{
		glAttachShader(this->_shader_program, this->_shader->_gl_vertex_shader);
		glAttachShader(this->_shader_program, this->_shader->_gl_fragment_shader);
		glLinkProgram(this->_shader_program);
		this->_shader->~shader();
	}

	texture_type get_entity_type_from_string(std::string string)
	{
		return (texture_type)hash(string.c_str());
	}
}