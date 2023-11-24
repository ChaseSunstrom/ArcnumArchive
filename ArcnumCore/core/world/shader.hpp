#ifndef CORE_SHADER_HPP
#define CORE_SHADER_HPP

#include <string>

#include <glm.hpp>
#include <glfw3.h>

namespace arcnum_core
{
	struct shader
	{
		shader(std::filesystem::path vertex_path, std::filesystem::path fragment_path);
		~shader();
		std::string read_file(std::filesystem::path path);

		void set_mat4(const GLuint& shader_program, const std::string& name, const glm::mat4& mat);

		GLuint _gl_vertex_shader = 0;
		GLuint _gl_fragment_shader = 0;

		GLuint _VBO = 0;
		GLuint _VAO = 0;
	};
}

#endif