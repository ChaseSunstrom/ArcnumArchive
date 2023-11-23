
#ifndef CORE_ENTITY_HPP
#define CORE_ENTITY_HPP

#include <vector>
#include <filesystem>

#include "shader.hpp"
#include "texture.hpp"

namespace arcnum_core
{

	class entity
	{
	public:
		entity(GLuint* shader_program, std::filesystem::path vertex_source, std::filesystem::path fragment_source, std::vector<float> vertices, texture* texture);
		~entity();
		void attach_shaders();
		void render();
	public:
		shader* _shader;
		texture* _texture;
		GLuint _shader_program;
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
		void add_texture(texture* texture);
	private:
		std::vector<entity*> _entities;
		std::vector<GLuint> _VAOs;
		std::vector<GLuint> _VBOs;
		std::vector<texture*> _textures;
		uint64_t _current_entity  = 0;
		uint64_t _current_texture = 0;
	};

}

#endif