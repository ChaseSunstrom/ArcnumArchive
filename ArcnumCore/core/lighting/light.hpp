#ifndef CORE_LIGHT_HPP
#define CORE_LIGHT_HPP

#include "../entity/color.hpp"
#include "../entity/voxel.hpp"
#include "../entity/entity.hpp"
#include "../util/constants.hpp"

namespace arcnum_core
{
	class light : public entity
	{
	public:
		light(world_position world_pos, texture_type texture_type, color_type _color_type) : entity(world_pos, voxel_vertices, texture_type, _color_type, entity_type::LIGHT) {};
		~light();
	public:
		color color;
	};
}

#endif