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
		this->_shader_program = glCreateProgram();
		this->_shader = new shader(vertex_source, fragment_source);
		this->attach_shaders();
	}

	void entity::attach_shaders()
	{
		glAttachShader(_shader_program, this->_shader->_gl_vertex_shader);
		glAttachShader(_shader_program, this->_shader->_gl_fragment_shader);
		glLinkProgram(_shader_program);
		this->_shader->~shader();
	}

	entities::entities(std::vector<entity*> entities)
	{
		this->_entities = entities;
		this->_VAOs = new GLuint[entities.size()];
		this->_VBOs = new GLuint[entities.size()];
	}

	void entity::render()
	{
		glUseProgram(this->_shader_program);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBindVertexArray(this->_shader->_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	void entities::render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		uint64_t iterator = 0;

		for (auto entity : this->_entities)
		{
			glUseProgram(entity->_shader_program);
			glBindVertexArray(this->_VAOs[iterator]);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			iterator++;
		}
	}

	void entities::bind_objects()
	{
		uint64_t iterator = 0;

		glGenVertexArrays(this->_entities.size(), this->_VAOs);
		glGenBuffers(this->_entities.size(), this->_VBOs);

		for (auto entity : this->_entities)
		{
			glBindVertexArray(this->_VAOs[iterator]);
			glBindBuffer(GL_ARRAY_BUFFER, this->_VBOs[iterator]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(entity->_vertices), entity->_vertices.data(), GL_DYNAMIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);	
			glEnableVertexAttribArray(0);
			iterator++;
		}
	}
}