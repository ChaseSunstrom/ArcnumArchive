#ifndef CORE_LIGHT_HPP
#define CORE_LIGHT_HPP

#include "../entity/color.hpp"
#include "../entity/entity.hpp"

namespace arcnum_core
{
	class light : public entity
	{
	public:
		light(world_position world_pos, texture_type texture_type, color_type color_type) : entity(world_pos, texture_type, color_type, entity_type::LIGHT) {}
		~light();
	};
}

#endif