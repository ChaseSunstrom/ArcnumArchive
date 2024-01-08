#include "color.h"

__A_CORE_API__ color color_default()
{
	return (color) { 0, 0, 0, 0 };
}

__A_CORE_API__ color color_new(float64_t r, float64_t g, float64_t b, float64_t a)
{
	return (color) { r, g, b, a };
}