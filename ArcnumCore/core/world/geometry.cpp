#include "geometry.hpp"

#define TOP_RIGHT 0.5f,  0.5f, 0.0f
#define BOTTOM_RIGHT 0.5f, -0.5f, 0.0f
#define BOTTOM_LEFT -0.5f, -0.5f, 0.0f
#define TOP_LEFT -0.5f,  0.5f, 0.0f

namespace arcnum_core
{
	triangle::triangle(std::vector<float> vertices, float world_position[3])
	{
		//verticy 1
		vertices[0] += world_position[0];
		vertices[1] += world_position[1];
		vertices[2] += world_position[2];

		//verticy 2
		vertices[8] += world_position[0];
		vertices[9] += world_position[1];
		vertices[10] += world_position[2];

		//verticy 3
		vertices[16] += world_position[0];
		vertices[17] += world_position[1];
		vertices[18] += world_position[2];

		this->_vertices = vertices;
	}

	void triangle::flip_over_x_axis()
	{
		this->_vertices[0] *= -1;
		this->_vertices[8] *= -1;
		this->_vertices[16] *= -1;
	}

	void triangle::flip_over_y_axis()
	{
		this->_vertices[1] *= -1;
		this->_vertices[9] *= -1;
		this->_vertices[17] *= -1;
	}

	void triangle::flip_over_z_axis()
	{
		this->_vertices[2] *= -1;
		this->_vertices[10] *= -1;
		this->_vertices[18] *= -1;
	}

	square::square(float world_position[3])
	{
		this->_vertices = {
			TOP_RIGHT,
			BOTTOM_RIGHT,
			BOTTOM_LEFT,
			TOP_LEFT,
		};

		//verticy 1
		this->_vertices[0] += world_position[0];
		this->_vertices[1] += world_position[1];
		this->_vertices[2] += world_position[2];

		//verticy 2
		this->_vertices[3] += world_position[0];
		this->_vertices[4] += world_position[1];
		this->_vertices[5] += world_position[2];

		//verticy 3
		this->_vertices[6] += world_position[0];
		this->_vertices[7] += world_position[1];
		this->_vertices[8] += world_position[2];

		//verticy 4
		this->_vertices[9] += world_position[0];
		this->_vertices[10] += world_position[1];
		this->_vertices[11] += world_position[2];
	}
}