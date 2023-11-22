#include <cstdint>
#include <filesystem>
#include <cstdlib>

#include <glew.h>
#include <glfw3.h>

#include "entity.hpp"
#include "shader.hpp"
#include "../debug/macros.hpp"

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

			srand((unsigned)time(NULL));

			// Get a random number
			int random = rand() % 10;

			float time = glfwGetTime();
			float green = static_cast<float>(sin(time) / random);
			float blue = static_cast<float>(cos(time) / random);
			float red = static_cast<float>(tan(time) / random);
			int vertex_color_location = glGetUniformLocation(entity->_shader_program, "my_color");
			glUniform4f(vertex_color_location, red, green, blue, 1.0f);

			glDrawArrays(GL_TRIANGLES, 0, 3);
			iterator++;
		}
	}

	void entities::bind_all_objects()
	{
		for (auto _ : this->_entities)
		{
			this->bind_objects();
		}
	}

	void entities::bind_objects()
	{
		glGenVertexArrays(1, &this->_VAOs[this->_current_entity]);
		glGenBuffers(1, &this->_VBOs[this->_current_entity]);

		glBindVertexArray(this->_VAOs[this->_current_entity]);
		glBindBuffer(GL_ARRAY_BUFFER, this->_VBOs[this->_current_entity]);
		glBufferData(GL_ARRAY_BUFFER, 1.1 * sizeof(this->_entities[this->_current_entity]->_vertices), this->_entities[this->_current_entity]->_vertices.data(), GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3 * sizeof(float)) * 1.1, NULL);
		CHECK_GL_ERROR()
		glEnableVertexAttribArray(0);

		this->_current_entity++;
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

		this->bind_objects();
	}
}