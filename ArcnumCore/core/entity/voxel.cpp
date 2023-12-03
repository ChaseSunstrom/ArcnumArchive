#include "voxel.hpp"

namespace arcnum_core
{
	color_type voxel::convert_voxel_type_to_color_type(voxel_type voxel_type)
	{
		switch (voxel_type)
		{
		case voxel_type::GRASS:
			return color_type::GREEN;
		case voxel_type::DIRT:
			return color_type::BROWN;
		case voxel_type::STONE:
			return color_type::GRAY;
		case voxel_type::SAND:
			return color_type::YELLOW;
		default:
			return color_type::NONE;
		}
	}

	texture_type voxel::convert_voxel_type_to_texture_type(voxel_type voxel_type)
	{
		switch (voxel_type)
		{
		case voxel_type::GRASS:
			return texture_type::GRASS;
		case voxel_type::STONE:
			return texture_type::STONE;
		case voxel_type::SAND:
			return texture_type::SAND;
		default:
			return texture_type::NONE;
		}
	}

	void voxel::bind_objects()
	{
		glGenVertexArrays(1, &this->_shader->_VAO);
		glGenBuffers(1, &this->_shader->_VBO);

		glBindVertexArray(this->_shader->_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->_shader->_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_vertices.size(), this->_vertices.data(), GL_DYNAMIC_DRAW);

		this->bind_vertex_position();
		this->bind_color();
		this->bind_texture();
		this->bind_normal();
	}
}