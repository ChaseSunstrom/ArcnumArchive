#ifndef CORE_SHADER_HPP
#define CORE_SHADER_HPP

#include <glfw3.h>

namespace arc_core
{
	struct shader
	{
		shader(const char* vertex_source, const char* fragment_source);
		~shader();

		GLuint _gl_vertex_shader = 0;
		GLuint _gl_fragment_shader = 0;

		GLuint _VBO = 0;
		GLuint _VAO = 0;
		GLuint _EBO = 0;
	};
}

#endif