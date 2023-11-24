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

		void flip_over_x_axis();
		void flip_over_y_axis();
		void flip_over_z_axis();
	public:
		std::vector<float> _vertices;
	};

	class square
	{
	public:
		square();
		~square();
	public:
		std::vector<float> _vertices;
	};
}

#endif

