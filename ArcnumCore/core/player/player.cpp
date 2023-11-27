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

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// Color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// Texture coordinate attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
	}
}