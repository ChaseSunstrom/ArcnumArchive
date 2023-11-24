#include <cstdint>
#include <filesystem>
#include <cstdlib>

#include <glew.h>
#include <glfw3.h>

#include "entity.hpp"
#include "entity_type.hpp"
#include "shader.hpp"
#include "texture.hpp"

namespace arcnum_core
{
	entity::entity(GLuint* shader_program, std::filesystem::path vertex_source, std::filesystem::path fragment_source, std::vector<float> vertices, texture* texture, entity_type type)
	{
		this->_type = type;
		this->_texture = texture;
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

			glActiveTexture(GL_TEXTURE0);
			
			//TODO: Add texture finding and or overloaded rendering for every texture type
			glBindTexture(GL_TEXTURE_2D, this->_texture_manager->find(entity->_type)->_texture);

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
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_entities[this->_current_entity]->_vertices.size(), this->_entities[this->_current_entity]->_vertices.data(), GL_DYNAMIC_DRAW);

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// Color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// Texture coordinate attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

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

	entity_type get_entity_type_from_string(std::string string)
	{
		return (entity_type)hash(string.c_str());
	}
}