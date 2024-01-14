#ifndef CORE_COLOR_H
#define CORE_COLOR_H

#include "../../core.hpp"

namespace ac
{
	__A_CORE_API__ struct color
	{
		__A_CORE_API__ color() = default;
		__A_CORE_API__ color(float64_t r, float64_t g, float64_t b, float64_t a) : m_r(r), m_g(g), m_b(b), m_a(a) {}

		__A_CORE_API__ float64_t m_r = 0;
		__A_CORE_API__ float64_t m_g = 0;
		__A_CORE_API__ float64_t m_b = 0;
		__A_CORE_API__ float64_t m_a = 0;
	};
}
#endif // CORE_COLOR_H