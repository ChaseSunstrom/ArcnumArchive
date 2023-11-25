#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "../world/voxel.hpp"

namespace arcnum_core
{
	class renderer
	{
	public:
		renderer();
		~renderer();
		void render();
		void attach_shaders();
	public:
		GLuint _shader_program = 0;
	private:
		std::vector<voxel*> _voxels;
		GLuint _gl_program = 0;
	};
}

#endif