#ifndef ARCNUM_TRIANGLE_HPP
#define ARCNUM_TRIANGLE_HPP

#include <core/window/entity.hpp>
#include <vector>

namespace arcnum_main
{
	class triangle
	{
	public:
		triangle(std::vector<float> vertices, float _world_position[3]);
		~triangle();
	public:
		std::vector<float> _vertices;
	};
}

#endif