#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include <glew.h>
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
		shader();
		~shader();
		void compile_shaders(const char* vertex_source, const char* fragment_source);
		void bind_objects();

		GLuint _gl_vertex_shader;
		GLuint _gl_fragment_shader;
		gl_objects* _gl_objects;
	};

	class renderer
	{
	public:
		renderer();
		~renderer();
		void render();
		void attach_shaders();
	private:
		shader* _shaders;
		GLuint _gl_program = 0;
		GLuint _shader_program;
	};
}

#endif