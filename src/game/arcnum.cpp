#include <vector>
#include <filesystem>
#include <iostream>

#include <core/window/window.hpp>
#include <core/world/entity.hpp>
#include <core/world/texture_type.hpp>
#include <core/world/entity_type.hpp>
#include <core/world/geometry.hpp>
#include <core/world/texture.hpp>

#include "arcnum.hpp"
#include "player/player.hpp"

#define TOP_RIGHT 0.5f,  0.5f, 0.0f
#define BOTTOM_RIGHT 0.5f, -0.5f, 0.0f
#define BOTTOM_LEFT -0.5f, -0.5f, 0.0f
#define TOP_LEFT -0.5f,  0.5f, 0.0f

#define SHADERS "shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl"

namespace arcnum_main
{
	arcnum::arcnum()
	{
		this->_main_window = new arcnum_core::window();
		this->_main_entities = new arcnum_core::entity_manager();
	}

	arcnum::~arcnum()
	{
		this->_main_entities->~entity_manager();
		this->_main_window->~window();
	}

	void arcnum::arcnum_main()
	{

		this->_main_entities->_texture_manager = new arcnum_core::texture_manager();

		arcnum_core::voxel* voxel = new arcnum_core::voxel(0.0f, 0.0f, 0.0f);

		player* player = new arcnum_main::player(
			&this->_main_window->_renderer->_shader_program,
			SHADERS,
			voxel->_vertices,
			arcnum_core::texture_type::TEST_CONTAINER,
			arcnum_core::entity_type::PLAYER
		);

		arcnum_core::entity* entity = new arcnum_core::entity(
			&this->_main_window->_renderer->_shader_program,
			SHADERS,
			voxel->_vertices,
			arcnum_core::texture_type::TEST_CONTAINER,
			arcnum_core::entity_type::BLOCK
		);

		this->_main_entities->add_entity(player);
		this->_main_entities->add_entity(entity);

		this->main_loop(player->_main_camera);
	}

	void arcnum::main_loop(arcnum_core::camera* player_camera)
	{
		player_camera->rotate_camera();

		std::vector<arcnum_core::voxel*> voxels;

		for (float i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				voxels.push_back(new arcnum_core::voxel(i, 0.0f, j));
			}
		}

		while (this->_main_window->is_running())
		{
			this->_main_window->update(this->_main_entities, player_camera, voxels);
		}
	}
}