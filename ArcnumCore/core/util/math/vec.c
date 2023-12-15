#include "vec.h"

// ===============================================================
// VEC FUNCTIONS:

AC_CORE_API vec1 vec1_default()
{
	return (vec1) { VEC1_SIZE, 0 };
}

AC_CORE_API vec1 vec1_new(f64 x)
{
	return (vec1) { VEC1_SIZE, x };
}

AC_CORE_API vec2 vec2_default()
{
	return (vec2) { VEC2_SIZE, 0, 0 };
}

AC_CORE_API vec2 vec2_new(f64 x, f64 y)
{
	return (vec2) { VEC2_SIZE, x, y };
}

AC_CORE_API vec3 vec3_default()
{
	return (vec3) {VEC3_SIZE, 0, 0, 0 };
}

AC_CORE_API vec3 vec3_new(f64 x, f64 y, f64 z)
{
	return (vec3) { VEC3_SIZE, x, y, z };
}

AC_CORE_API vec4 vec4_default()
{
	return (vec4) { VEC4_SIZE, 0, 0, 0, 0 };
}

AC_CORE_API vec4 vec4_new(f64 x, f64 y, f64 z, f64 w)
{
	return (vec4) { VEC4_SIZE, x, y, z, w };
}

AC_CORE_API vec1 vec1_add(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x + v2.x };
}

AC_CORE_API vec2 vec2_add(vec2 v1, vec2 v2)
{
	return (vec2) {VEC2_SIZE, (v1.x + v2.x), (v1.y + v2.y)};
}

AC_CORE_API vec3 vec3_add(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z) };
}

AC_CORE_API vec4 vec4_add(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z), (v1.w + v2.w) };
}

// ===============================================================