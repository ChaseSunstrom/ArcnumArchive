
#ifndef CORE_ENTITY_HPP
#define CORE_ENTITY_HPP

#include <vector>

#include "shader.hpp"

namespace arc_core
{
	class entity
	{
	public:
		entity(GLuint* shader_program, const char* vertex_source, const char* fragment_source, std::vector<float> vertices);
		~entity();
		void attach_shaders();
		void render();
		void bind_objects();
	public:
		shader* _shader;
		GLuint* _shader_program;
		std::vector<float> _vertices;
	};
}

#endif