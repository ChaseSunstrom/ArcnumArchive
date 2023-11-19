#include <glew.h>
#include <glfw3.h>

#include "entity.hpp"
#include "shader.hpp"

namespace arc_core
{
	entity::entity(GLuint* shader_program, const char* vertex_source, const char* fragment_source, std::vector<float> vertices, std::vector<int> indices)
	{
		this->_vertices = vertices;
		this->_indices = indices;
		this->_shader_program = shader_program;
		this->_shader = new shader(vertex_source, fragment_source);
		this->attach_shaders();
		this->bind_objects();
	}

	void entity::attach_shaders()
	{
		glAttachShader(*_shader_program, this->_shader->_gl_vertex_shader);
		glAttachShader(*_shader_program, this->_shader->_gl_fragment_shader);
		glLinkProgram(*_shader_program);
		this->_shader->~shader();
	}

	void entity::render()
	{
		glUseProgram(*this->_shader_program);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(this->_shader->_gl_objects->_VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void  entity::bind_objects()
	{
		
		glGenVertexArrays(1, &this->_shader->_gl_objects->_VAO);
		glGenBuffers(1, &this->_shader->_gl_objects->_VBO);
		glGenBuffers(1, &this->_shader->_gl_objects->_EBO);
		glBindVertexArray(this->_shader->_gl_objects->_VAO);

		glBindBuffer(GL_ARRAY_BUFFER, this->_shader->_gl_objects->_VBO);
		glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(this->_vertices), this->_vertices.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_shader->_gl_objects->_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->_indices), this->_indices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}
}