#include <cstdint>
#include <filesystem>
#include <cstdlib>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "texture_type.hpp"
#include "entity_type.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "color.hpp"
#include "../window/camera.hpp"
#include "../util/macros.hpp"

#include "voxel.hpp"

namespace arcnum_core
{
	voxel::voxel(world_position world_pos, texture_type texture_type, color_type color, entity_type entity_type)
	{
		this->_shader_program = glCreateProgram();
		switch (texture_type)
		{
		case texture_type::NONE:
			this->_shader = new shader(std::filesystem::absolute("ArcnumCore/shaders/color_shader.vsl"), std::filesystem::absolute("ArcnumCore/shaders/color_shader.fsl"));
			break;
		default:
			this->_shader = new shader(std::filesystem::absolute("ArcnumCore/shaders/texture_shader.vsl"), std::filesystem::absolute("ArcnumCore/shaders/texture_shader.fsl"));
			break;
		}
		this->_texture_type = texture_type;
		this->_color = color;
		this->_entity_type = entity_type;
		this->_position = world_pos;
		;

		this->_vertices = {
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //bottom left
			 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, //bottom right
			 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, //top right
			 0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, //top right
			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, //top left
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, //bottom left

			-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,

			 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			 0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
		};

		this->attach_shaders();
	}

	voxel::~voxel()
	{
		delete this->_shader;
		glDeleteProgram(this->_shader_program);
	}


	voxel_manager::voxel_manager()
	{
		this->_entities = std::vector<voxel*>();
		this->_VAOs = std::vector<GLuint>();
		this->_VBOs = std::vector<GLuint>();
	}

	voxel_manager::~voxel_manager()
	{
		for (auto entity : this->_entities)
		{
			delete entity;
		}
	}

	void voxel::attach_shaders()
	{
		glAttachShader(this->_shader_program, this->_shader->_gl_vertex_shader);
		glAttachShader(this->_shader_program, this->_shader->_gl_fragment_shader);
		glLinkProgram(this->_shader_program);
		this->_shader->~shader();
	}

	void voxel_manager::handle_view_and_projection(camera* player_camera, voxel* current_voxel)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		view = glm::lookAt(player_camera->_camera_position, player_camera->_camera_position + player_camera->_camera_front, player_camera->_camera_up);
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		current_voxel->_shader->set_mat4(current_voxel->_shader_program, "view", view);
		current_voxel->_shader->set_mat4(current_voxel->_shader_program, "projection", projection);

	}

	void voxel_manager::handle_color_and_texture(voxel* current_voxel)
	{
		int vertex_color_location;
		float green;
		color voxel_color;

		switch (current_voxel->_color)
		{
		case color_type::NONE:
			goto BIND_TEXTURE;
			break;
		default:
			break;
		}

	BIND_COLOR:

		vertex_color_location = glGetUniformLocation(current_voxel->_shader_program, "color");
		voxel_color = color(current_voxel->_color);
		glUniform4f(vertex_color_location, voxel_color._r, voxel_color._g, voxel_color._b, voxel_color._a);

		switch (current_voxel->_texture_type)
		{
		case texture_type::NONE:
			glActiveTexture(GL_TEXTURE0);
			return;
		default:
			goto BIND_TEXTURE;
		}

	BIND_TEXTURE:

		texture* texture = this->_texture_manager->find(current_voxel->_texture_type);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->_width, texture->_height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->_image_data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture->_texture);
	}


	void voxel_manager::render(camera* player_camera, std::vector<world_position> voxel_positions)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		uint64_t iterator = 0;

		for (auto entity : this->_entities)
		{
			glm::mat4 model = glm::mat4(1.0f);

			switch (entity->_entity_type)
			{
			case entity_type::PLAYER:
				glm::vec3 camera_offset = player_camera->_camera_position - player_camera->_camera_offset;

				glUseProgram(entity->_shader_program);
				glBindVertexArray(this->_VAOs[iterator]);

				this->handle_view_and_projection(player_camera, entity);
				this->handle_color_and_texture(entity);

				model = glm::translate(model, camera_offset);
				entity->_shader->set_mat4(entity->_shader_program, "model", model);
				glDrawArrays(GL_TRIANGLES, 0, 36);

				iterator++;

				continue;
			default:
				break;
			}

			glUseProgram(entity->_shader_program);
			glBindVertexArray(this->_VAOs[iterator]);

			this->handle_view_and_projection(player_camera, entity);
			this->handle_color_and_texture(entity);

			for (int i = 0; i < voxel_positions.size(); i++)
			{
				glm::mat4 model = glm::mat4(1.0f);
				model = glm::translate(model, voxel_positions[i]);
				entity->_shader->set_mat4(entity->_shader_program, "model", model);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			iterator++;
		}
	}

	void voxel_manager::bind_all_objects()
	{
		for (auto _ : this->_entities)
		{
			this->bind_objects();
		}
	}

	void voxel_manager::bind_objects()
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

	void voxel_manager::add_voxel(voxel* voxel)
	{
		this->_VAOs.emplace_back(0);
		this->_VBOs.emplace_back(0);

		if (this->_entities.capacity() > sizeof(uint64_t))
		{
			this->_entities.emplace_back(voxel);
		}
		else
		{
			this->_entities.push_back(voxel);
		}

		this->bind_objects();
	}

	texture_type get_entity_type_from_string(std::string string)
	{
		return (texture_type)hash(string.c_str());
	}
}