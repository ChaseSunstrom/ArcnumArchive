#include <vector>
#include <filesystem>
#include <iostream>

#include <core/window/window.hpp>
#include <core/util/macros.hpp>
#include <core/world/texture_type.hpp>
#include <core/world/entity_type.hpp>
#include <core/world/texture.hpp>
#include <core/world/color.hpp>
#include <core/player/player.hpp>

#include "arcnum.hpp"

namespace arcnum_main
{
	arcnum::arcnum()
	{
		this->_main_window = new arcnum_core::window();
		this->_main_entities = new arcnum_core::voxel_manager();
	}

	arcnum::~arcnum()
	{
		delete this->_main_entities;
		delete this->_main_window;
	}

	void arcnum::arcnum_main()
	{

		this->_main_entities->_texture_manager = new arcnum_core::texture_manager();

		arcnum_core::player* _player = new arcnum_core::player(world_position(0.0f, 0.0f, 0.0f), arcnum_core::texture_type::TEST_CONTAINER, arcnum_core::color_type::WHITE, arcnum_core::entity_type::PLAYER);
		arcnum_core::voxel* voxel = new arcnum_core::voxel(world_position(0.0f, 0.0f, 0.0f), arcnum_core::texture_type::TEST_BRICK, arcnum_core::color_type::RED, arcnum_core::entity_type::BLOCK);
		
		this->_main_entities->add_voxel(voxel);

		this->main_loop(_player);
	}

	void arcnum::main_loop(arcnum_core::player* player)
	{
		player->_main_camera->rotate_camera();

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
			this->_main_window->update(this->_main_entities, player, voxel_positions);
		}
	}
}