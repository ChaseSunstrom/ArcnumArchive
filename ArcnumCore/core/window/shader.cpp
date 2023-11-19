#include <iostream>
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "shader.hpp"



namespace arc_core
{
	shader::shader(const char* vertex_source, const char* fragment_source)
	{
		this->_gl_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(_gl_vertex_shader, 1, &vertex_source, NULL);
		glCompileShader(_gl_vertex_shader);
		this->_gl_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(_gl_fragment_shader, 1, &fragment_source, NULL);
		glCompileShader(_gl_fragment_shader);
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
}