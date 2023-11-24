#include "geometry.hpp"

#define TOP_RIGHT 0.5f,  0.5f, 0.0f
#define BOTTOM_RIGHT 0.5f, -0.5f, 0.0f
#define BOTTOM_LEFT -0.5f, -0.5f, 0.0f
#define TOP_LEFT -0.5f,  0.5f, 0.0f

namespace arcnum_core
{
	triangle::triangle(std::vector<float> vertices)
	{
		this->_vertices = vertices;
	}
}