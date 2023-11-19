#ifndef CORE_SHADER_HPP
#define CORE_SHADER_HPP

#include <glfw3.h>

namespace arc_core
{
	struct gl_objects
	{
		gl_objects() = default;
		~gl_objects();

		GLuint _VBO = 0;
		GLuint _VAO = 0;
		GLuint _EBO = 0;
	};

	struct shader
	{
		shader(const char* vertex_source, const char* fragment_source);
		~shader();
		void bind_objects(float vertices[]);

		gl_objects* _gl_objects;
		GLuint _gl_vertex_shader = 0;
		GLuint _gl_fragment_shader = 0;
	};
}

#endif