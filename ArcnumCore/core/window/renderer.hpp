#ifndef CORE_RENDERER_HPP
#define CORE_RENDERER_HPP

#include "../player/player.hpp"
#include "../entity/ecs.hpp"

namespace arcnum_core
{
	class renderer
	{
	public:
		renderer();
		~renderer();
		void render();
		void handle_view_and_projection(entity* current_entity);
		void handle_color_and_texture(entity* current_entity);
		void handle_player(const int& iterator);
	public:
		double _delta_time;
		ecs* _ecs;
		player* _player;
		std::vector<world_position> _entity_positions;
	};
}

#endif