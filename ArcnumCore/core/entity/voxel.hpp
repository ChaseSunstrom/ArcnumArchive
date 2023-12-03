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
		voxel() = default;
		voxel(world_position world_pos, voxel_type voxel_type) 
			:
		entity(world_pos, voxel_vertices, convert_voxel_type_to_texture_type(voxel_type), color_type::NONE, entity_type::BLOCK)
		{
			this->_voxel_type = voxel_type;
			this->bind_objects();
		};
		~voxel() = default;
		color_type convert_voxel_type_to_color_type(voxel_type voxel_type);
		texture_type convert_voxel_type_to_texture_type(voxel_type voxel_type);
		void bind_objects();
	public:
		voxel_type _voxel_type;
	};
}

#endif