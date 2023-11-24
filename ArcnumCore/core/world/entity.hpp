
#ifndef CORE_ENTITY_HPP
#define CORE_ENTITY_HPP

#include <vector>
#include <map>
#include <filesystem>
#include <xhash>
#include <string>
#include <memory>

#include "shader.hpp"
#include "texture.hpp"

namespace arcnum_core
{
	

	class entity
	{
	public:
		entity(GLuint* shader_program, std::filesystem::path vertex_source, std::filesystem::path fragment_source, std::vector<float> vertices, entity_type type);
		~entity();
		void attach_shaders();
		void render();
	public:
		shader* _shader;
		texture* _texture;
		GLuint _shader_program;
		entity_type _type;
		std::vector<float> _vertices;
	};

	class entities
	{
	public:
		entities();
		~entities();
		void bind_objects();
		void bind_all_objects();
		void render();
		void add_entity(entity* entity);
		void find_texture(entity_type);
	public:
		texture_manager* _texture_manager;
	private:
		std::vector<entity*> _entities;
		std::vector<GLuint> _VAOs;
		std::vector<GLuint> _VBOs;
		uint64_t _current_entity  = 0;
		uint64_t _current_texture = 0;
	};

	entity_type get_entity_type_from_string(std::string string);
}

#endif