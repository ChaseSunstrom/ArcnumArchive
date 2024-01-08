#ifndef CORE_COLOR_H
#define CORE_COLOR_H

#include "../../util/std_include.h"

typedef struct
{
	float64_t r;
	float64_t g;
	float64_t b;
	float64_t a;
} color;

__A_CORE_API__ color color_default();
__A_CORE_API__ color color_new(float64_t r, float64_t g, float64_t b, float64_t a);

#endif // CORE_COLOR_H