#include "chunk.hpp"
#include "../entity/entity.hpp"
#include "../window/renderer.hpp"

namespace arcnum_core
{
	void chunk::load_chunk()
	{
		
	}

	void chunk::insert(voxel* key, std::vector<world_position> value)
	{
		this->_voxels[key] = value;
	}
}