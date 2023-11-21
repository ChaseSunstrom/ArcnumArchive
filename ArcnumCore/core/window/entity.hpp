
#ifndef CORE_ENTITY_HPP
#define CORE_ENTITY_HPP

#include <vector>
#include <filesystem>

#include "shader.hpp"

namespace arcnum_core
{

	class entity
	{
	public:
		entity(GLuint* shader_program, std::filesystem::path vertex_source, std::filesystem::path fragment_source, std::vector<float> vertices);
		~entity();
		void attach_shaders();
		void render();
	public:
		shader* _shader;
		GLuint _shader_program;
		std::vector<float> _vertices;
	};

	class entities
	{
	public:
		entities();
		~entities();
		void bind_objects();
		void render();
		void add_entity(entity* entity);
	private:
		std::vector<entity*> _entities;
		std::vector<GLuint> _VAOs;
		std::vector<GLuint> _VBOs;
	};

}

#endif