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
#include "../window/camera.hpp"
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
		color_type              _color;
		entity_type        _entity_type;
		glm::vec3          _position        = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3          _rotation        = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3          _scale           = glm::vec3(1.0f, 1.0f, 1.0f);
		std::vector<float> _vertices;
	};

	class voxel_manager
	{
	public:
		voxel_manager();
		~voxel_manager();
		void bind_objects();
		void bind_all_objects();
		void render(camera* player_camera, std::vector<world_position> voxel_positions);
		void add_voxel(voxel* entity);
		void handle_view_and_projection(camera* player_camera, voxel* current_voxel);
		void handle_color_and_texture(voxel* current_voxel);
	public:
		texture_manager*    _texture_manager;
	private:
		std::vector<voxel*> _entities;
		std::vector<GLuint> _VAOs;
		std::vector<GLuint> _VBOs;
		uint64_t            _current_entity = 0;
	};

	texture_type get_entity_type_from_string(std::string string);
}

#endif