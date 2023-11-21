#include <cstdint>
#include <filesystem>

#include <glew.h>
#include <glfw3.h>

#include "entity.hpp"
#include "shader.hpp"

namespace arcnum_core
{
	entity::entity(GLuint* shader_program, std::filesystem::path vertex_source, std::filesystem::path fragment_source, std::vector<float> vertices)
	{
		this->_vertices = vertices;
		this->_shader_program = glCreateProgram();
		this->_shader = new shader(vertex_source, fragment_source);
		this->attach_shaders();
	}

	entity::~entity()
	{
		this->_shader->~shader();
		glDeleteProgram(this->_shader_program);
	}

	void entity::attach_shaders()
	{
		glAttachShader(_shader_program, this->_shader->_gl_vertex_shader);
		glAttachShader(_shader_program, this->_shader->_gl_fragment_shader);
		glLinkProgram(_shader_program);
		this->_shader->~shader();
	}

	entities::entities()
	{
		this->_entities = std::vector<entity*>();
		this->_VAOs = std::vector<GLuint>();
		this->_VBOs = std::vector<GLuint>();
	}

	entities::~entities()
	{
		for (auto entity : this->_entities)
		{
			entity->~entity();
		}
	}

	void entity::render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(this->_shader_program);


		glBindVertexArray(this->_shader->_VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
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
			float time = glfwGetTime();
			float green = static_cast<float>(sin(time) / 2.0f + 0.5f);
			int vertex_color_location = glGetUniformLocation(entity->_shader_program, "my_color");
			glUniform4f(vertex_color_location, 0.0f, green, 0.0f, 1.0f);

			glDrawArrays(GL_TRIANGLES, 0, 3);
			iterator++;
		}
	}

	void entities::bind_objects()
	{
		uint64_t iterator = 0;

		glGenVertexArrays(this->_entities.size(), &this->_VAOs[0]);
		glGenBuffers(this->_entities.size(), &this->_VBOs[0]);

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

	void entities::add_entity(entity* entity)
	{
		this->_VAOs.emplace_back(0);
		this->_VBOs.emplace_back(0);

		if (this->_entities.capacity() > sizeof(uint64_t))
		{
			this->_entities.emplace_back(entity);
		}
		else
		{
			this->_entities.push_back(entity);
		}
	}
}