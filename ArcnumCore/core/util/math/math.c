#include "math.h"

__A_CORE_API__ __A_CORE_INLINE__ float64_t clamp(float64_t val, float64_t minval, float64_t maxval)
{
	return min(max(val, minval), maxval);
}