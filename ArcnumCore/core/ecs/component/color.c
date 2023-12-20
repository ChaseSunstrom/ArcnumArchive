#include "color.h"

__A_CORE_API__ color color_default()
{
	return (color) { 0, 0, 0, 0 };
}

__A_CORE_API__ color color_new(f64 r, f64 g, f64 b, f64 a)
{
	return (color) { r, g, b, a };
}