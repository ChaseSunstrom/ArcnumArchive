#ifndef CORE_VOXEL_HPP
#define CORE_VOXEL_HPP

#include <vector>

#include "entity.hpp"
#include "color.hpp"
#include "voxel_type.hpp"
#include "../util/constants.hpp"

namespace arcnum_core
{
	class voxel : public entity
	{
	public:
		voxel(world_position world_pos, texture_type texture_type, color_type _color_type, voxel_type voxel_type) 
			:
		entity(world_pos, voxel_vertices, texture_type, _color_type, entity_type::BLOCK)
		{
			this->_voxel_type = voxel_type;
		};
		~voxel();
	public:
		voxel_type _voxel_type;
	};
}

#endif