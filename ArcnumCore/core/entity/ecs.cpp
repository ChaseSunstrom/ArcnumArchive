#include <filesystem>

#include <glew.h>
#include <glfw3.h>

#include "entity.hpp"
#include "ecs.hpp"
#include "texture.hpp"

namespace arcnum_core
{
	ecs::ecs()
	{
		this->_texture_manager = new texture_manager();
		this->_entities = std::vector<entity*>();
		this->_VAOs     = std::vector<GLuint>();
		this->_VBOs     = std::vector<GLuint>();
	}

	ecs::~ecs()
	{
		for (auto entity : this->_entities)
		{
			delete entity;
		}
	}

	void ecs::bind_all_objects()
	{
		for (auto _ : this->_entities)
		{
			this->bind_objects();
		}
	}

	void ecs::bind_objects()
	{
		glGenVertexArrays(1, &this->_VAOs[this->_current_entity]);
		glGenBuffers(1, &this->_VBOs[this->_current_entity]);

		glBindVertexArray(this->_VAOs[this->_current_entity]);
		glBindBuffer(GL_ARRAY_BUFFER, this->_VBOs[this->_current_entity]);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->_entities[this->_current_entity]->_vertices.size(), this->_entities[this->_current_entity]->_vertices.data(), GL_DYNAMIC_DRAW);

		// Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// Color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// Texture coordinate attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		this->_current_entity++;
	}

	void ecs::add_entity(entity* voxel)
	{
		this->_VAOs.emplace_back(0);
		this->_VBOs.emplace_back(0);

		if (this->_entities.capacity() > sizeof(uint64_t))
		{
			this->_entities.emplace_back(voxel);
		}
		else
		{
			this->_entities.push_back(voxel);
		}

		this->bind_objects();
	}
}