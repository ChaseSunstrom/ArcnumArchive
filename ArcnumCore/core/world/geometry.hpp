#ifndef CORE_GEOMETRY_HPP
#define CORE_GEOMETRY_HPP

#include <vector>

namespace arcnum_core
{
	class triangle
	{
	public:
		triangle(std::vector<float> vertices);
		~triangle();
	public:
		std::vector<float> _vertices;
	};
}

#endif

