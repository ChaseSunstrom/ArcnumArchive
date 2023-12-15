#include "math.h"

#include "vec.h"

// ===============================================================
// VEC FUNCTIONS:

__AC_CORE_API__ vec1 vec1_default()
{
	return (vec1) { VEC1_SIZE, 0 };
}

__AC_CORE_API__ vec1 vec1_new(f64 x)
{
	return (vec1) { VEC1_SIZE, x };
}

__AC_CORE_API__ vec2 vec2_default()
{
	return (vec2) { VEC2_SIZE, 0, 0 };
}

__AC_CORE_API__ vec2 vec2_new(f64 x, f64 y)
{
	return (vec2) { VEC2_SIZE, x, y };
}

__AC_CORE_API__ vec3 vec3_default()
{
	return (vec3) {VEC3_SIZE, 0, 0, 0 };
}

__AC_CORE_API__ vec3 vec3_new(f64 x, f64 y, f64 z)
{
	return (vec3) { VEC3_SIZE, x, y, z };
}

__AC_CORE_API__ vec4 vec4_default()
{
	return (vec4) { VEC4_SIZE, 0, 0, 0, 0 };
}

__AC_CORE_API__ vec4 vec4_new(f64 x, f64 y, f64 z, f64 w)
{
	return (vec4) { VEC4_SIZE, x, y, z, w };
}

__AC_CORE_API__ vec1 vec1_add(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x + v2.x };
}

__AC_CORE_API__ vec2 vec2_add(vec2 v1, vec2 v2)
{
	return (vec2) {VEC2_SIZE, (v1.x + v2.x), (v1.y + v2.y)};
}

__AC_CORE_API__ vec3 vec3_add(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z) };
}

__AC_CORE_API__ vec4 vec4_add(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z), (v1.w + v2.w) };
}

__AC_CORE_API__ vec1 vec1_mul(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x* v2.x };
}

__AC_CORE_API__ vec2 vec2_mul(vec2 v1, vec2 v2)
{
	return (vec2) { VEC2_SIZE, (v1.x * v2.x), (v1.y * v2.y) };
}

__AC_CORE_API__ vec3 vec3_mul(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x * v2.x), (v1.y * v2.y), (v1.z * v2.z) };
}

__AC_CORE_API__ vec4 vec4_mul(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x * v2.x), (v1.y * v2.y), (v1.z * v2.z), (v1.w * v2.w) };
}

__AC_CORE_API__ vec1 vec1_sub(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x - v2.x };
}

__AC_CORE_API__ vec2 vec2_sub(vec2 v1, vec2 v2)
{
	return (vec2) { VEC2_SIZE, (v1.x - v2.x), (v1.y - v2.y) };
}

__AC_CORE_API__ vec3 vec3_sub(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z) };
}

__AC_CORE_API__ vec4 vec4_sub(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z), (v1.w - v2.w) };
}

__AC_CORE_API__ vec1 vec1_div(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x / v2.x };
}

__AC_CORE_API__ vec2 vec2_div(vec2 v1, vec2 v2)
{
	return (vec2) { VEC2_SIZE, (v1.x / v2.x), (v1.y / v2.y) };
}

__AC_CORE_API__ vec3 vec3_div(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x / v2.x), (v1.y / v2.y), (v1.z / v2.z) };
}

__AC_CORE_API__ vec4 vec4_div(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x / v2.x), (v1.y / v2.y), (v1.z / v2.z), (v1.w / v2.w) };
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec1_dot(vec1 v1, vec1 v2)
{
	return v1.x * v2.x;
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec2_dot(vec2 v1, vec2 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec3_dot(vec3 v1, vec3 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec4_dot(vec4 v1, vec4 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 _vec1_norm(vec1 v)
{
	return vec1_dot(v, v);
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 _vec2_norm(vec2 v)
{
	return vec2_dot(v, v);
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 _vec3_norm(vec3 v)
{
	return vec3_dot(v, v);
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 _vec4_norm(vec4 v)
{
	return vec4_dot(v, v);
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec1_norm(vec1 v)
{
	return sqrt(vec1_norm(v));
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec2_norm(vec2 v)
{
	return sqrt(vec2_norm(v));
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec3_norm(vec3 v)
{
	return sqrt(vec3_norm(v));
}

__AC_CORE_API__ __AC_CORE_INLINE__ f64 vec4_norm(vec4 v)
{
	return sqrt(vec4_norm(v));
}

__AC_CORE_API__ __AC_CORE_INLINE__ vec1 vec1_scale(vec1 v, f64 scale)
{
	return (vec1) { VEC1_SIZE, v.x* scale };
}

__AC_CORE_API__ __AC_CORE_INLINE__ vec2 vec2_scale(vec2 v, f64 scale)
{
	return (vec2) { VEC1_SIZE, v.x* scale, v.y * scale };
}

__AC_CORE_API__ __AC_CORE_INLINE__ vec3 vec3_scale(vec3 v, f64 scale)
{
	return (vec3) { VEC1_SIZE, v.x* scale, v.y * scale, v.z * scale };
}

__AC_CORE_API__ __AC_CORE_INLINE__ vec4 vec4_scale(vec4 v, f64 scale)
{
	return (vec4) { VEC1_SIZE, v.x* scale, v.y * scale, v.z * scale, v.w * scale };
}

__AC_CORE_API__ __AC_CORE_INLINE__ void vec1_clamp(vec1 v, f64 min, f64 max)
{
	v.x = clamp(v.x, min, max);
}

__AC_CORE_API__ __AC_CORE_INLINE__ void vec2_clamp(vec2 v, f64 min, f64 max)
{
	v.x = clamp(v.x, min, max);
	v.y = clamp(v.y, min, max);
}

__AC_CORE_API__ __AC_CORE_INLINE__ void vec3_clamp(vec3 v, f64 min, f64 max)
{
	v.x = clamp(v.x, min, max);
	v.y = clamp(v.y, min, max);
	v.z = clamp(v.z, min, max);
}

__AC_CORE_API__ __AC_CORE_INLINE__ void vec4_clamp(vec4 v, f64 min, f64 max)
{
	v.x = clamp(v.x, min, max);
	v.y = clamp(v.x, min, max);
	v.z = clamp(v.z, min, max);
	v.w = clamp(v.w, min, max);
}

__AC_CORE_API__ void vec1_normalize(vec1 v)
{
	f64 norm = 0.0;

	norm = vec1_norm(v);

	if (norm == 0.0f) 
	{
		v.x = 0.0;
		return;
	}

	vec1_scale(v, 1.0f / norm);
}

__AC_CORE_API__ void vec2_normalize(vec2 v)
{
	f64 norm = 0.0;

	norm = vec2_norm(v);

	if (norm == 0.0f)
	{
		v.x = 0.0;
		v.y = 0.0;
		return;
	}

	vec2_scale(v, 1.0f / norm);
}

__AC_CORE_API__ void vec3_normalize(vec3 v)
{
	f64 norm = 0.0;

	norm = vec3_norm(v);

	if (norm == 0.0f)
	{
		v.x = 0.0;
		v.y = 0.0;
		v.z = 0.0;
		return;
	}

	vec3_scale(v, 1.0f / norm);
}

__AC_CORE_API__ void vec4_normalize(vec4 v)
{
	f64 norm = 0.0;

	norm = vec4_norm(v);

	if (norm == 0.0f)
	{
		v.x = 0.0;
		v.y = 0.0;
		v.z = 0.0;
		v.w = 0.0;
		return;
	}

	vec4_scale(v, 1.0f / norm);
}

// ===============================================================