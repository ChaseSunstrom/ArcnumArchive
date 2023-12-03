#include "chunk.hpp"
#include "../entity/entity.hpp";
#include "../window/renderer.hpp"

namespace arcnum_core
{
	chunk::~chunk()
	{
		for (auto& it : this->_voxels)
		{
			delete it.first;
			this->_voxels.clear();
		}
	}

	void chunk::insert(voxel* key, std::vector<world_position> value)
	{
		this->_voxels[key] = value;
	}
}