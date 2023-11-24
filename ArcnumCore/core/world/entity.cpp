#include <cstdint>
#include <filesystem>
#include <cstdlib>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "entity.hpp"
#include "entity_type.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "../window/camera.hpp"

namespace arcnum_core
{
	entity::entity(GLuint* shader_program, std::filesystem::path vertex_source, std::filesystem::path fragment_source, std::vector<float> vertices,  entity_type type)
	{
		this->_type = type;
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

	glm::vec3 cube_positions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	void entities::render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		uint64_t iterator = 0;

		for (auto entity : this->_entities)
		{
			glm::mat4 view = glm::mat4(1.0f);
			float radius = 10.0f;
			float camX = static_cast<float>(sin(glfwGetTime()) * radius);
			float camY = static_cast<float>(sin(glfwGetTime()) * radius);
			float camZ = static_cast<float>(cos(glfwGetTime()) * radius);
			view = glm::lookAt(glm::vec3(camX, camY, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			entity->_shader->set_mat4(entity->_shader_program, "view", view);

			glm::mat4 projection = glm::mat4(1.0f);

			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -1.0f));
			projection = glm::perspective(glm::radians(45.0f), (float)1080 / (float)1080, 0.1f, 100.0f);

			entity->_shader->set_mat4(entity->_shader_program, "view", view);
			entity->_shader->set_mat4(entity->_shader_program, "projection", projection);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, this->_texture_manager->find(entity->_type)->_texture);

			glUseProgram(entity->_shader_program);
			glBindVertexArray(this->_VAOs[iterator]);

			for (int i = 0; i < 10; i++)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, cube_positions[i]);
				float angle = 20.0f * i;
				model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
				entity->_shader->set_mat4(entity->_shader_program, "model", model);

				glDrawArrays(GL_TRIANGLES, 0, 18);
			}

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
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// Texture coordinate attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

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