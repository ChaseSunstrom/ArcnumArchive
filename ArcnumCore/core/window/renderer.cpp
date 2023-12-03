#include <vector>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "renderer.hpp"
#include "../util/macros.hpp"
#include "../player/player.hpp"

namespace arcnum_core
{
	renderer::renderer()
	{
		this->_ecs = new ecs();
		this->_chunks = std::vector<chunk*>();
	}

	void renderer::render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_SCISSOR_TEST);

		this->handle_player();
		glm::mat4 model;

		for (int i = 0; i < this->_ecs->_entities.size(); i++)
		{
			entity* entity = this->_ecs->_entities[i];

			glBindVertexArray(this->_ecs->_VAOs[i]);
			glUseProgram(entity->_shader_program);

			this->handle_view_and_projection(entity);
			this->handle_color_and_texture(entity);

			entity->_shader->set_vec3(entity->_shader_program, "light_pos", this->_ecs->_entities[0]->_position);
			entity->_shader->set_vec3(entity->_shader_program, "light_color", glm::vec3(1.0f, 1.0f, 1.0f));
			entity->_shader->set_vec3(this->_player->_shader_program, "view_pos", this->_player->_main_camera->_camera_position);

			model = glm::mat4(1.0f);
			model = glm::translate(model, entity->_position);
			entity->_shader->set_mat4(entity->_shader_program, "model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		std::unordered_map<voxel*, std::vector<world_position>>::iterator it;

		for (int i = 0; i < RENDER_DISTANCE; i++)
		{
			chunk* chunk = this->_chunks[i];

			for (it = chunk->_voxels.begin(); it != chunk->_voxels.end(); it++)
			{
				glBindVertexArray(it->first->_shader->_VAO);
				glUseProgram(it->first->_shader_program);

				this->handle_view_and_projection(it->first);
				this->handle_color_and_texture(it->first);

				it->first->_shader->set_vec3(it->first->_shader_program, "light_pos", this->_ecs->_entities[0]->_position);
				it->first->_shader->set_vec3(it->first->_shader_program, "light_color", glm::vec3(1.0f, 1.0f, 1.0f));
				it->first->_shader->set_vec3(this->_player->_shader_program, "view_pos", this->_player->_main_camera->_camera_position);

				for (int i = 0; i < it->second.size(); i++)
				{
					model = glm::mat4(1.0f);
					model = glm::translate(model, it->second[i]);
					it->first->_shader->set_mat4(it->first->_shader_program, "model", model);

					glDrawArrays(GL_TRIANGLES, 0, 36);
				}
			}

		}

	}

	void renderer::render_entity(entity entity)
	{
		glBindVertexArray(entity._shader->_VAO);
		glUseProgram(entity._shader_program);

		this->handle_view_and_projection(&entity);
		this->handle_color_and_texture(&entity);

		entity._shader->set_vec3(entity._shader_program, "light_pos", this->_ecs->_entities[0]->_position);
		entity._shader->set_vec3(entity._shader_program, "light_color", glm::vec3(1.0f, 1.0f, 1.0f));
		entity._shader->set_vec3(this->_player->_shader_program, "view_pos", this->_player->_main_camera->_camera_position);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, entity._position);
		entity._shader->set_mat4(entity._shader_program, "model", model);

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	void renderer::handle_view_and_projection(entity* current_entity)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		view = glm::lookAt(this->_player->_main_camera->_camera_position, this->_player->_main_camera->_camera_position + this->_player->_main_camera->_camera_front, this->_player->_main_camera->_camera_up);
		projection = glm::perspective(glm::radians(FOV), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		current_entity->_shader->set_mat4(current_entity->_shader_program, "view", view);
		current_entity->_shader->set_mat4(current_entity->_shader_program, "projection", projection);
	}

	void renderer::handle_view_and_projection(voxel current_voxel)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		view = glm::lookAt(this->_player->_main_camera->_camera_position, this->_player->_main_camera->_camera_position + this->_player->_main_camera->_camera_front, this->_player->_main_camera->_camera_up);
		projection = glm::perspective(glm::radians(FOV), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		current_voxel._shader->set_mat4(current_voxel._shader_program, "view", view);
		current_voxel._shader->set_mat4(current_voxel._shader_program, "projection", projection);
	}

	void renderer::handle_color_and_texture(entity* current_entity)
	{
		int vertex_color_location;
		color voxel_color;

		switch (current_entity->_color_type)
		{
		case color_type::NONE:
			current_entity->_color_type = color_type::WHITE;
			break;
		default:
			break;
		}

		vertex_color_location = glGetUniformLocation(current_entity->_shader_program, "color");
		voxel_color = color(current_entity->_color_type);
		glUniform4f(vertex_color_location, voxel_color._r, voxel_color._g, voxel_color._b, voxel_color._a);

		switch (current_entity->_texture_type)
		{
		case texture_type::NONE:
			glActiveTexture(-1);
			return;
		default:
			break;
		}
	}

	void renderer::handle_color_and_texture(voxel current_voxel)
	{
		int vertex_color_location;
		color voxel_color;

		switch (current_voxel._color_type)
		{
		case color_type::NONE:
			current_voxel._color_type = color_type::WHITE;
			break;
		default:
			break;
		}

		vertex_color_location = glGetUniformLocation(current_voxel._shader_program, "color");
		voxel_color = color(current_voxel._color_type);
		glUniform4f(vertex_color_location, voxel_color._r, voxel_color._g, voxel_color._b, voxel_color._a);

		switch (current_voxel._texture_type)
		{
		case texture_type::NONE:
			glActiveTexture(-1);
			return;
		default:
			break;
		}
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->_ecs->_texture_manager->texture_find(current_voxel._texture_type)->_texture);
	}

	void renderer::handle_player()
	{
		glm::mat4 model = glm::mat4(1.0f);
		glm::vec3 camera_offset = this->_player->_main_camera->_camera_position - this->_player->_main_camera->_camera_offset;

		this->_player->_shader->set_vec3(this->_player->_shader_program, "light_pos", this->_ecs->_entities[0]->_position);
		this->_player->_shader->set_vec3(this->_player->_shader_program, "light_color", glm::vec3(1.0f, 1.0f, 1.0f));
		this->_player->_shader->set_vec3(this->_player->_shader_program, "view_pos", this->_player->_main_camera->_camera_position);

		glUseProgram(this->_player->_shader_program);
		glBindVertexArray(this->_player->_VAO);

		this->handle_view_and_projection(this->_player);
		this->handle_color_and_texture(this->_player);

		model = glm::translate(model, camera_offset);
		this->_player->_shader->set_mat4(this->_player->_shader_program, "model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}