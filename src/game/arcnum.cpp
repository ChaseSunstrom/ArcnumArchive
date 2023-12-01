#include <vector>
#include <filesystem>
#include <iostream>

#include <core/window/window.hpp>
#include <core/util/macros.hpp>
#include <core/world/chunk.hpp>
#include <core/entity/texture_type.hpp>
#include <core/entity/entity_type.hpp>
#include <core/entity/texture.hpp>
#include <core/entity/color.hpp>
#include <core/player/player.hpp>
#include <core/entity/voxel.hpp>
#include <core/lighting/light.hpp>
#include <core/entity/voxel_type.hpp>

#include "arcnum.hpp"

namespace arcnum_main
{
	arcnum::arcnum()
	{
		this->_main_window = new arcnum_core::window();
	}

	arcnum::~arcnum()
	{
		delete this->_main_window;
	}

	void arcnum::arcnum_main()
	{
		this->_main_window->_renderer->_player = new arcnum_core::player(world_position(0.0f, 0.0f, 0.0f), arcnum_core::texture_type::NONE, arcnum_core::color_type::WHITE, arcnum_core::entity_type::PLAYER);

		arcnum_core::light* light = new arcnum_core::light(world_position(-12.0f, 7.0f, -10.0f), arcnum_core::texture_type::NONE, arcnum_core::color_type::WHITE);

		this->_main_window->_renderer->_ecs->add_entity(light);

		
		

		for (int i = 0; i < 3; i++)
		{
			arcnum_core::chunk* chunk = new arcnum_core::chunk();
			std::vector<world_position> positions;
			arcnum_core::voxel* voxel = nullptr;
			if (i == 0)
				voxel = new arcnum_core::voxel(world_position(0.0f, 0.0f, 0.0f), arcnum_core::voxel_type::GRASS);
			if (i == 1)
				voxel = new arcnum_core::voxel(world_position(0.0f, 0.0f, 0.0f), arcnum_core::voxel_type::SAND);
			if (i == 2)
				voxel = new arcnum_core::voxel(world_position(0.0f, 0.0f, 0.0f), arcnum_core::voxel_type::STONE);

			for (int j = 0; j < CHUNK_SIZE; j++)
			{
				for (int n = 0; n < CHUNK_SIZE; n++)
				{
					for (int m = 0; m < CHUNK_SIZE; m++)
					{
						positions.emplace_back(world_position((float)-j + (i * 16), (float)-m, (float)-n));
					}
				}
			}

			chunk->insert(voxel, positions);
			this->_main_window->_renderer->_chunks.push_back(chunk);
			positions.clear();
		}

		this->main_loop();
	}

	void arcnum::main_loop()
	{
		this->_main_window->_renderer->_player->_main_camera->rotate_camera();

		while (this->_main_window->is_running())
		{
			this->_main_window->update();
		}
	}
}