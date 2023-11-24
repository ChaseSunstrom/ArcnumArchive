#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <filesystem>

#include <glew.h>
#include <glfw3.h>

#include "shader.hpp"

namespace arcnum_core
{
	shader::shader(std::filesystem::path vertex_path, std::filesystem::path fragment_path)
	{
		std::string vertex_source_string = read_file(vertex_path);
		std::string fragment_source_string = read_file(fragment_path);

		const char* vertex_source = vertex_source_string.c_str();
		const char* fragment_source = fragment_source_string.c_str();

		this->_gl_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(_gl_vertex_shader, 1, &vertex_source, NULL);
		glCompileShader(_gl_vertex_shader);
		this->_gl_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(_gl_fragment_shader, 1, &fragment_source, NULL);
		glCompileShader(_gl_fragment_shader);
	}

	shader::~shader()
	{
		glDeleteShader(this->_gl_vertex_shader);
		glDeleteShader(this->_gl_fragment_shader);
		glDeleteVertexArrays(1, &this->_VAO);
		glDeleteBuffers(1, &this->_VBO);
	}

	std::string shader::read_file(std::filesystem::path file_path)
	{
		std::string code;
		std::ifstream file_stream;
		file_stream.open(file_path);
		std::stringstream stream;
		stream << file_stream.rdbuf();
		file_stream.close();
		code = stream.str();
		return code;
	}

	void shader::set_mat4(const GLuint& shader_program, const std::string& name, const glm::mat4& mat)
	{
		int location = glGetUniformLocation(shader_program, name.c_str());
		glProgramUniformMatrix4fv(shader_program, location, 1, GL_FALSE, &mat[0][0]);
	}
}