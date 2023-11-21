#ifndef CORE_GEOMETRY_HPP
#define CORE_GEOMETRY_HPP

#include <vector>

namespace arcnum_core
{
	class triangle
	{
	public:
		triangle(std::vector<float> vertices, float world_position[3]);
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
		square(float world_position[3]);
		~square();
	public:
		std::vector<float> _vertices;
	};
}

#endif

