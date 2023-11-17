#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "shader.hpp"

namespace arc_core
{
	class renderer
	{
	public:
		renderer();
		~renderer();
		void render();
		void attach_shaders();
	private:
		std::vector<shader*> _shaders;
		GLuint _gl_program     = 0;
		GLuint _shader_program = 0;
	};
}

#endif