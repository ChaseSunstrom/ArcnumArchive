#ifndef CORE_COLOR_H
#define CORE_COLOR_H

#include "../../util/std_include.h"

typedef struct
{
	f64 r;
	f64 g;
	f64 b;
	f64 a;
} color;

__A_CORE_API__ color color_default();
__A_CORE_API__ color color_new(f64 r, f64 g, f64 b, f64 a);

#endif // CORE_COLOR_H