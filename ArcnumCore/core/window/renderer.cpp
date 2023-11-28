#include <vector>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "renderer.hpp"
#include "../player/player.hpp"

namespace arcnum_core
{
	renderer::renderer()
	{
		this->_ecs = new ecs();
		this->_entity_positions = std::vector<world_position>();
	}

	void renderer::render()
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		uint64_t iterator = 0;

		this->handle_player();

		


		auto light = this->_ecs->_entities[1];

		glUseProgram(light->_shader_program);
		glBindVertexArray(this->_ecs->_VAOs[1]);


		this->handle_view_and_projection(light);
		//this->handle_color_and_texture(light);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, light->_position);
		light->_shader->set_mat4(light->_shader_program, "model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		auto entity = this->_ecs->_entities[0];
		glBindVertexArray(this->_ecs->_VAOs[0]);

		glUseProgram(entity->_shader_program);

		this->handle_view_and_projection(entity);
		this->handle_color_and_texture(entity);

		model = glm::mat4(1.0f);
		model = glm::translate(model, entity->_position);
		entity->_shader->set_mat4(entity->_shader_program, "model", model);
		entity->_shader->set_vec4(entity->_shader_program, "light_color", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

		glDrawArrays(GL_TRIANGLES, 0, 36);

	}

	void renderer::handle_view_and_projection(entity* current_voxel)
	{
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		view = glm::lookAt(this->_player->_main_camera->_camera_position, this->_player->_main_camera->_camera_position + this->_player->_main_camera->_camera_front, this->_player->_main_camera->_camera_up);
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		current_voxel->_shader->set_mat4(current_voxel->_shader_program, "view", view);
		current_voxel->_shader->set_mat4(current_voxel->_shader_program, "projection", projection);

	}

	void renderer::handle_color_and_texture(entity* current_voxel)
	{
		int vertex_color_location;
		float green;
		color voxel_color;

		switch (current_voxel->_color_type)
		{
		case color_type::NONE:
			goto BIND_TEXTURE;
		default:
			goto BIND_COLOR;
		}

	BIND_COLOR:

		vertex_color_location = glGetUniformLocation(current_voxel->_shader_program, "color");
		voxel_color = color(current_voxel->_color_type);
		glUniform4f(vertex_color_location, voxel_color._r, voxel_color._g, voxel_color._b, voxel_color._a);

		switch (current_voxel->_texture_type)
		{
		case texture_type::NONE:
			glActiveTexture(-1);
			return;
		default:
			goto BIND_TEXTURE;
		}

	BIND_TEXTURE:

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->_ecs->_texture_manager->texture_find(current_voxel->_texture_type)->_texture);
	}

	void renderer::handle_player()
	{
		glm::mat4 model = glm::mat4(1.0f);
		glm::vec3 camera_offset = this->_player->_main_camera->_camera_position - this->_player->_main_camera->_camera_offset;

		glUseProgram(this->_player->_shader_program);
		glBindVertexArray(this->_player->_VAO);

		this->handle_view_and_projection(this->_player);
		this->handle_color_and_texture(this->_player);

		model = glm::translate(model, camera_offset);
		this->_player->_shader->set_mat4(this->_player->_shader_program, "model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}