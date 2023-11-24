#ifndef CORE_ENTITY_HPP
#define CORE_ENTITY_HPP

#include <vector>
#include <map>
#include <filesystem>
#include <xhash>
#include <string>
#include <memory>

#include <glew.h>
#include <glfw3.h>

#include "shader.hpp"
#include "texture.hpp"
#include "texture_type.hpp"
#include "entity_type.hpp"
#include "../window/camera.hpp"

namespace arcnum_core
{
	

	class entity
	{
	public:
		entity(GLuint* shader_program, std::filesystem::path vertex_source, std::filesystem::path fragment_source, std::vector<float> vertices, texture_type texture_type, entity_type entity_type);
		~entity();
		void attach_shaders();
		void render();
	public:
		shader* _shader;
		texture* _texture;
		GLuint _shader_program;
		texture_type _texture_type;
		entity_type _entity_type;
		std::vector<float> _vertices;
		glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 _rotation = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 _scale    = glm::vec3(1.0f, 1.0f, 1.0f);
	};

	class entity_manager
	{
	public:
		entity_manager();
		~entity_manager();
		void bind_objects();
		void bind_all_objects();
		void render(camera* player_camera);
		void add_entity(entity* entity);
	public:
		texture_manager* _texture_manager;
	private:
		std::vector<entity*> _entities;
		std::vector<GLuint> _VAOs;
		std::vector<GLuint> _VBOs;
		uint64_t _current_entity  = 0;
	};

	texture_type get_entity_type_from_string(std::string string);
}

#endif