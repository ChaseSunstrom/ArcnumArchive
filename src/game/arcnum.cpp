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
		this->_main_window->_renderer->_player = new arcnum_core::player(world_position(0.0f, 0.0f, 0.0f), arcnum_core::texture_type::TEST_BRICK, arcnum_core::color_type::GREEN, arcnum_core::entity_type::PLAYER);
		
		arcnum_core::entity* green_voxel = new arcnum_core::entity(world_position(0.0f, 0.0f, 0.0f), arcnum_core::texture_type::NONE, arcnum_core::color_type::GREEN, arcnum_core::entity_type::BLOCK);
		
		arcnum_core::entity* red_voxel = new arcnum_core::entity(world_position(0.0f, 0.0f, 1.0f), arcnum_core::texture_type::NONE, arcnum_core::color_type::RED, arcnum_core::entity_type::BLOCK);
		
		arcnum_core::entity* blue_voxel = new arcnum_core::entity(world_position(1.0f, 0.0f, 0.0f), arcnum_core::texture_type::TEST_CONTAINER, arcnum_core::color_type::BLUE, arcnum_core::entity_type::BLOCK);
		
		arcnum_core::light* light = new arcnum_core::light(world_position(-3.0f, 3.0f, -3.0f), arcnum_core::texture_type::NONE, arcnum_core::color_type::WHITE);

		this->_main_window->_renderer->_ecs->add_entity(green_voxel);
		this->_main_window->_renderer->_ecs->add_entity(red_voxel);
		this->_main_window->_renderer->_ecs->add_entity(blue_voxel);
		this->_main_window->_renderer->_ecs->add_entity(light);

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