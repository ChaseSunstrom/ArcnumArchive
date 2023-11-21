#include "triangle.hpp"

#define X 0
#define Y 1
#define Z 2

namespace arcnum_main
{
	triangle::triangle(std::vector<float> vertices, float world_position[3])
	{
		vertices[0] += world_position[X];
		vertices[1] += world_position[Y];
		vertices[2] += world_position[Z];

		vertices[3] += world_position[X];
		vertices[4] += world_position[Y];
		vertices[5] += world_position[Z];

		vertices[6] += world_position[X];
		vertices[7] += world_position[Y];
		vertices[8] += world_position[Z];

		this->_vertices = vertices;
	}
}	