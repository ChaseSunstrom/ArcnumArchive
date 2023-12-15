#include "math.h"

__A_CORE_API__ __A_CORE_INLINE__ f64 clamp(f64 val, f64 minval, f64 maxval)
{
	return min(max(val, minval), maxval);
}