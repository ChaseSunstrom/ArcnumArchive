#ifndef CORE_CHUNK_HPP
#define CORE_CHUNK_HPP

#include <unordered_map>
#include <array>

#include "../util/macros.hpp"
#include "../entity/voxel.hpp"

namespace arcnum_core
{
	class chunk
	{
	public:
		chunk() = default;
		~chunk();
		void insert(voxel* key, std::vector<world_position> value);
	public:
		std::unordered_map<voxel*, std::vector<world_position>> _voxels = std::unordered_map<voxel*, std::vector<world_position>>();
	};
}

#endif