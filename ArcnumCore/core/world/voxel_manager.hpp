#ifndef CORE_VOXEL_MANAGER_HPP
#define CORE_VOXEL_MANAGER_HPP

#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "texture.hpp"
#include "voxel.hpp"	
#include "../player/player.hpp"

namespace arcnum_core
{
	class voxel_manager
	{
	public:
		voxel_manager();
		~voxel_manager();
		void bind_objects();
		void bind_all_objects();
		void render(player* player, std::vector<world_position> voxel_positions);
		void add_voxel(voxel* entity);
		void handle_view_and_projection(camera* player_camera, voxel* current_voxel);
		void handle_color_and_texture(voxel* current_voxel);
		void handle_player(player* player, const int& iterator);
	public:
		texture_manager* _texture_manager;
	private:
		std::vector<voxel*> _entities;
		std::vector<GLuint> _VAOs;
		std::vector<GLuint> _VBOs;
		uint64_t            _current_entity = 0;
	};
}

#endif