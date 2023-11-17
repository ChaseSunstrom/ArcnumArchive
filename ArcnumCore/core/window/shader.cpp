#include <iostream>
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "shader.hpp"



namespace arc_core
{
	shader::shader()
	{
		this->_gl_objects = new gl_objects();
	}

	shader::~shader()
	{
		glDeleteShader(this->_gl_vertex_shader);
		glDeleteShader(this->_gl_fragment_shader);
	}

	gl_objects::~gl_objects()
	{
		glDeleteVertexArrays(1, &this->_VAO);
		glDeleteBuffers(1, &this->_VBO);
		glDeleteBuffers(1, &this->_EBO);
	}

	void shader::compile_shaders(const char* vertex_source, const char* fragment_source)
	{
		this->_gl_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(_gl_vertex_shader, 1, &vertex_source, NULL);
		glCompileShader(_gl_vertex_shader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(_gl_vertex_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(_gl_vertex_shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		// fragment shader
		this->_gl_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(_gl_fragment_shader, 1, &fragment_source, NULL);
		glCompileShader(_gl_fragment_shader);
		// check for shader compile errors
		glGetShaderiv(_gl_fragment_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(_gl_fragment_shader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}
}