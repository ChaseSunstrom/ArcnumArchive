#include <vector>
#include <filesystem>
#include <iostream>

#include <core/window/window.hpp>
#include <core/util/macros.hpp>
#include <core/entity/texture_type.hpp>
#include <core/entity/entity_type.hpp>
#include <core/entity/texture.hpp>
#include <core/entity/color.hpp>
#include <core/player/player.hpp>
#include <core/lighting/light.hpp>

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

		for (float i = 0; i < 10; i++)
		{
			for (float j = 0; j < 10; j++)
			{
				srand((unsigned)time(NULL));

				int random = 1 + (rand() % 5);

				arcnum_core::entity* voxel = new arcnum_core::entity(world_position(-i, (i*j)/((j + i + random)*2), -j), arcnum_core::texture_type::NONE, (arcnum_core::color_type)(((i*random)*(j*random))/((random*random) * 3*random)), arcnum_core::entity_type::BLOCK);
				this->_main_window->_renderer->_ecs->add_entity(voxel);
			}
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