#include <vector>
#include <filesystem>
#include <iostream>

#include <core/window/window.hpp>
#include <core/util/macros.hpp>
#include <core/world/texture_type.hpp>
#include <core/world/entity_type.hpp>
#include <core/world/geometry.hpp>
#include <core/world/texture.hpp>
#include "core/world/color.hpp"

#include "arcnum.hpp"
#include "player/player.hpp"

namespace arcnum_main
{
	arcnum::arcnum()
	{
		this->_main_window = new arcnum_core::window();
		this->_main_entities = new arcnum_core::voxel_manager();
	}

	arcnum::~arcnum()
	{
		this->_main_entities->~voxel_manager();
		this->_main_window->~window();
	}

	void arcnum::arcnum_main()
	{

		this->_main_entities->_texture_manager = new arcnum_core::texture_manager();

		player* _player = new player(world_position(0.0f, 0.0f, 0.0f), arcnum_core::texture_type::NONE, arcnum_core::color_type::RED, arcnum_core::entity_type::PLAYER);
		arcnum_core::voxel* voxel = new arcnum_core::voxel(world_position(0.0f, 0.0f, 0.0f), arcnum_core::texture_type::NONE, arcnum_core::color_type::RED, arcnum_core::entity_type::BLOCK);

		this->_main_entities->add_voxel(_player);
		this->_main_entities->add_voxel(voxel);

		this->main_loop(_player->_main_camera);
	}

	void arcnum::main_loop(arcnum_core::camera* player_camera)
	{
		player_camera->rotate_camera();

		std::vector<world_position> voxel_positions;

		for (float i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				voxel_positions.push_back(world_position(-i, -0.5f, -j));
			}
		}

		while (this->_main_window->is_running())
		{
			this->_main_window->update(this->_main_entities, player_camera, voxel_positions);
		}
	}
}