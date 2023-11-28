#include "player.hpp"

namespace arcnum_core
{
	void player::bind_objects()
	{
		glGenVertexArrays(1, &this->_VAO);
		glGenBuffers(1, &this->_VBO);

		glBindVertexArray(this->_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_vertices.size(), this->_vertices.data(), GL_DYNAMIC_DRAW);

		this->bind_vertex_position();
		this->bind_color();
		this->bind_texture();
		this->bind_normal();
	}
}