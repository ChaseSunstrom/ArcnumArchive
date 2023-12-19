#include "math.h"

#include "vec.h"

// ===============================================================
// VEC FUNCTIONS:

__A_CORE_API__ vec1 vec1_default()
{
	return (vec1) { VEC1_SIZE, 0 };
}

__A_CORE_API__ vec1 vec1_new(f64 x)
{
	return (vec1) { VEC1_SIZE, x };
}

__A_CORE_API__ vec2 vec2_default()
{
	return (vec2) { VEC2_SIZE, 0, 0 };
}

__A_CORE_API__ vec2 vec2_new(f64 x, f64 y)
{
	return (vec2) { VEC2_SIZE, x, y };
}

__A_CORE_API__ vec3 vec3_default()
{
	return (vec3) { VEC3_SIZE, 0, 0, 0 };
}

__A_CORE_API__ vec3 vec3_new(f64 x, f64 y, f64 z)
{
	return (vec3) { VEC3_SIZE, x, y, z };
}

__A_CORE_API__ vec4 vec4_default()
{
	return (vec4) { VEC4_SIZE, 0, 0, 0, 0 };
}

__A_CORE_API__ vec4 vec4_new(f64 x, f64 y, f64 z, f64 w)
{
	return (vec4) { VEC4_SIZE, x, y, z, w };
}

__A_CORE_API__ vec1 vec1_add(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x + v2.x };
}

__A_CORE_API__ vec2 vec2_add(vec2 v1, vec2 v2)
{
	return (vec2) { VEC2_SIZE, (v1.x + v2.x), (v1.y + v2.y) };
}

__A_CORE_API__ vec3 vec3_add(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z) };
}

__A_CORE_API__ vec4 vec4_add(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x + v2.x), (v1.y + v2.y), (v1.z + v2.z), (v1.w + v2.w) };
}

__A_CORE_API__ vec1 vec1_mul(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x* v2.x };
}

__A_CORE_API__ vec2 vec2_mul(vec2 v1, vec2 v2)
{
	return (vec2) { VEC2_SIZE, (v1.x * v2.x), (v1.y * v2.y) };
}

__A_CORE_API__ vec3 vec3_mul(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x * v2.x), (v1.y * v2.y), (v1.z * v2.z) };
}

__A_CORE_API__ vec4 vec4_mul(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x * v2.x), (v1.y * v2.y), (v1.z * v2.z), (v1.w * v2.w) };
}

__A_CORE_API__ vec1 vec1_sub(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x - v2.x };
}

__A_CORE_API__ vec2 vec2_sub(vec2 v1, vec2 v2)
{
	return (vec2) { VEC2_SIZE, (v1.x - v2.x), (v1.y - v2.y) };
}

__A_CORE_API__ vec3 vec3_sub(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z) };
}

__A_CORE_API__ vec4 vec4_sub(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z), (v1.w - v2.w) };
}

__A_CORE_API__ vec1 vec1_div(vec1 v1, vec1 v2)
{
	return (vec1) { VEC1_SIZE, v1.x / v2.x };
}

__A_CORE_API__ vec2 vec2_div(vec2 v1, vec2 v2)
{
	return (vec2) { VEC2_SIZE, (v1.x / v2.x), (v1.y / v2.y) };
}

__A_CORE_API__ vec3 vec3_div(vec3 v1, vec3 v2)
{
	return (vec3) { VEC3_SIZE, (v1.x / v2.x), (v1.y / v2.y), (v1.z / v2.z) };
}

__A_CORE_API__ vec4 vec4_div(vec4 v1, vec4 v2)
{
	return (vec4) { VEC4_SIZE, (v1.x / v2.x), (v1.y / v2.y), (v1.z / v2.z), (v1.w / v2.w) };
}

__A_CORE_API__ __A_CORE_INLINE__ vec3 vec3_cross(vec3 v1, vec3 v2)
{
	return (vec3) {
		3,
			v1.y* v2.z - v1.z * v2.y,
			v1.z* v2.x - v1.x * v2.z,
			v1.x* v2.y - v1.y * v2.x
	};
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec1_dot(vec1 v1, vec1 v2)
{
	return v1.x * v2.x;
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec2_dot(vec2 v1, vec2 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y);
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec3_dot(vec3 v1, vec3 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec4_dot(vec4 v1, vec4 v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

__A_CORE_API__ __A_CORE_INLINE__ f64 _vec1_norm(vec1 v)
{
	return vec1_dot(v, v);
}

__A_CORE_API__ __A_CORE_INLINE__ f64 _vec2_norm(vec2 v)
{
	return vec2_dot(v, v);
}

__A_CORE_API__ __A_CORE_INLINE__ f64 _vec3_norm(vec3 v)
{
	return vec3_dot(v, v);
}

__A_CORE_API__ __A_CORE_INLINE__ f64 _vec4_norm(vec4 v)
{
	return vec4_dot(v, v);
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec1_norm(vec1 v)
{
	return sqrt(_vec1_norm(v));
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec2_norm(vec2 v)
{
	return sqrt(_vec2_norm(v));
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec3_norm(vec3 v)
{
	return sqrt(_vec3_norm(v));
}

__A_CORE_API__ __A_CORE_INLINE__ f64 vec4_norm(vec4 v)
{
	return sqrt(_vec4_norm(v));
}

__A_CORE_API__ __A_CORE_INLINE__ vec1 vec1_scale(vec1 v, f64 scale)
{
	return (vec1) { VEC1_SIZE, v.x* scale };
}

__A_CORE_API__ __A_CORE_INLINE__ vec2 vec2_scale(vec2 v, f64 scale)
{
	return (vec2) { VEC1_SIZE, v.x* scale, v.y* scale };
}

__A_CORE_API__ __A_CORE_INLINE__ vec3 vec3_scale(vec3 v, f64 scale)
{
	return (vec3) { VEC1_SIZE, v.x* scale, v.y* scale, v.z* scale };
}

__A_CORE_API__ __A_CORE_INLINE__ vec4 vec4_scale(vec4 v, f64 scale)
{
	return (vec4) { VEC1_SIZE, v.x* scale, v.y* scale, v.z* scale, v.w* scale };
}

__A_CORE_API__ __A_CORE_INLINE__ vec1 vec1_clamp(vec1 v, f64 min, f64 max)
{
	vec1 res;
	res.x = clamp(v.x, min, max);
	return res;
}

__A_CORE_API__ __A_CORE_INLINE__ vec2 vec2_clamp(vec2 v, f64 min, f64 max)
{
	vec2 res;
	res.x = clamp(v.x, min, max);
	res.y = clamp(v.y, min, max);
	return res;
}

__A_CORE_API__ __A_CORE_INLINE__ vec3 vec3_clamp(vec3 v, f64 min, f64 max)
{
	vec3 res;
	res.x = clamp(v.x, min, max);
	res.y = clamp(v.y, min, max);
	res.z = clamp(v.z, min, max);
	return res;
}

__A_CORE_API__ __A_CORE_INLINE__ vec4 vec4_clamp(vec4 v, f64 min, f64 max)
{
	vec4 res;
	res.x = clamp(v.x, min, max);
	res.y = clamp(v.y, min, max);
	res.z = clamp(v.z, min, max);
	res.w = clamp(v.w, min, max);
	return res;
}

__A_CORE_API__ vec1 vec1_normalize(vec1 v)
{
	f64 norm = 0.0;

	norm = vec1_norm(v);

	if (norm == 0.0f)
	{
		return (vec1) { 1, 0.0 };
	}

	return vec1_scale(v, 1.0f / norm);
}

__A_CORE_API__ vec2 vec2_normalize(vec2 v)
{
	f64 norm = 0.0;

	norm = vec2_norm(v);

	if (norm == 0.0f)
	{
		return (vec2) { 2, 0.0, 0.0};
	}

	return vec2_scale(v, 1.0f / norm);
}

__A_CORE_API__ vec3 vec3_normalize(vec3 v)
{
	f64 norm = 0.0;

	norm = vec3_norm(v);

	if (norm == 0.0f)
	{
		return (vec3){3, 0.0, 0.0, 0.0};
	}

	return vec3_scale(v, 1.0f / norm);
}

__A_CORE_API__ vec4 vec4_normalize(vec4 v)
{
	f64 norm = 0.0;

	norm = vec4_norm(v);

	if (norm == 0.0f)
	{
		return (vec4){ 4, 0.0, 0.0, 0.0, 0.0 };
	}

	return vec4_scale(v, 1.0f / norm);
}

__A_CORE_API__ vec3 vec3_rotate(quat q, vec3 v)
{
	quat result_quaternion = {
		q.w * v.x + q.y * v.z - q.z * v.y,
		q.w * v.y + q.z * v.x - q.x * v.z,
		q.w * v.z + q.x * v.y - q.y * v.x,
	   -q.x * v.x - q.y * v.y - q.z * v.z
	};

	return (vec3) {
		result_quaternion.x* q.w + result_quaternion.w * -q.x + result_quaternion.y * -q.z - result_quaternion.z * -q.y,
			result_quaternion.y* q.w + result_quaternion.w * -q.y + result_quaternion.z * -q.x - result_quaternion.x * -q.z,
			result_quaternion.z* q.w + result_quaternion.w * -q.z + result_quaternion.x * -q.y - result_quaternion.y * -q.x
	};
}

__A_CORE_API__ void vec1_add_to(vec1* v1, vec1* v2)
{
	v1->x = v1->x + v2->x;
}

__A_CORE_API__ void vec2_add_to(vec2* v1, vec2* v2)
{
	v1->x = v1->x + v2->x;
	v1->y = v1->y + v2->y;
}

__A_CORE_API__ void vec3_add_to(vec3* v1, vec3* v2)
{
	v1->x = v1->x + v2->x;
	v1->y = v1->y + v2->y;
	v1->z = v1->z + v2->z;
}

__A_CORE_API__ void vec4_add_to(vec4* v1, vec4* v2)
{
	v1->x = v1->x + v2->x;
	v1->y = v1->y + v2->y;
	v1->z = v1->z + v2->z;
	v1->w = v1->w + v2->w;
}

__A_CORE_API__ void vec1_mul_to(vec1* v1, vec1* v2)
{
	v1->x = v1->x * v2->x;
}

__A_CORE_API__ void vec2_mul_to(vec2* v1, vec2* v2)
{
	v1->x = v1->x * v2->x;
	v1->y = v1->y * v2->y;
}

__A_CORE_API__ void vec3_mul_to(vec3* v1, vec3* v2)
{
	v1->x = v1->x * v2->x;
	v1->y = v1->y * v2->y;
	v1->z = v1->z * v2->z;
}

__A_CORE_API__ void vec4_mul_to(vec4* v1, vec4* v2)
{
	v1->x = v1->x * v2->x;
	v1->y = v1->y * v2->y;
	v1->z = v1->z * v2->z;
	v1->w = v1->w * v2->w;
}

__A_CORE_API__ void vec1_sub_to(vec1* v1, vec1* v2)
{
	v1->x = v1->x - v2->x;
}

__A_CORE_API__ void vec2_sub_to(vec2* v1, vec2* v2)
{
	v1->x = v1->x - v2->x;
	v1->y = v1->y - v2->y;
}

__A_CORE_API__ void vec3_sub_to(vec3* v1, vec3* v2)
{
	v1->x = v1->x - v2->x;
	v1->y = v1->y - v2->y;
	v1->z = v1->z - v2->z;
}

__A_CORE_API__ void vec4_sub_to(vec4* v1, vec4* v2)
{
	v1->x = v1->x - v2->x;
	v1->y = v1->y - v2->y;
	v1->z = v1->z - v2->z;
	v1->w = v1->w - v2->w;
}

__A_CORE_API__ void vec1_div_to(vec1* v1, vec1* v2)
{
	v1->x = v1->x / v2->x;
}

__A_CORE_API__ void vec2_div_to(vec2* v1, vec2* v2)
{
	v1->x = v1->x / v2->x;
	v1->y = v1->y /  v2->y;
}

__A_CORE_API__ void vec3_div_to(vec3* v1, vec3* v2)
{
	v1->x = v1->x / v2->x;
	v1->y = v1->y / v2->y;
	v1->z = v1->z / v2->z;
}

__A_CORE_API__ void vec4_div_to(vec4* v1, vec4* v2)
{
	v1->x = v1->x / v2->x;
	v1->y = v1->y / v2->y;
	v1->z = v1->z / v2->z;
	v1->w = v1->w / v2->w;
}

__A_CORE_API__ __A_CORE_INLINE__ void vec3_cross_to(vec3* v1, vec3* v2)
{
	v1->x = v1->y * v2->z - v1->z * v2->y;
	v1->y = v1->z * v2->x - v1->x * v2->z;
	v1->z = v1->x * v2->y - v1->y * v2->x;
}

__A_CORE_API__ __A_CORE_INLINE__ void vec1_scale_to(vec1* v, f64 scale)
{
	v->x = v->x * scale;
}

__A_CORE_API__ __A_CORE_INLINE__ void vec2_scale_to(vec2* v, f64 scale)
{
	v->x = v->x * scale;
	v->y = v->y * scale;
}

__A_CORE_API__ __A_CORE_INLINE__ void vec3_scale_to(vec3* v, f64 scale)
{
	v->x = v->x * scale;
	v->y = v->y * scale;
	v->z = v->z * scale;
}

__A_CORE_API__ __A_CORE_INLINE__ void vec4_scale_to(vec4* v, f64 scale)
{
	v->x = v->x * scale;
	v->y = v->y * scale;
	v->z = v->z * scale;
	v->w = v->w * scale;
}

__A_CORE_API__ __A_CORE_INLINE__ void vec1_clamp_to(vec1* v, f64 min, f64 max)
{
	v->x = clamp(v->x, min, max);
}

__A_CORE_API__ __A_CORE_INLINE__ void vec2_clamp_to(vec2* v, f64 min, f64 max)
{
	v->x = clamp(v->x, min, max);
	v->y = clamp(v->y, min, max);
}

__A_CORE_API__ __A_CORE_INLINE__ void vec3_clamp_to(vec3* v, f64 min, f64 max)
{
	v->x = clamp(v->x, min, max);
	v->y = clamp(v->y, min, max);
	v->z = clamp(v->z, min, max);
}

__A_CORE_API__ __A_CORE_INLINE__ void vec4_clamp_to(vec4* v, f64 min, f64 max)
{
	v->x = clamp(v->x, min, max);
	v->y = clamp(v->y, min, max);
	v->z = clamp(v->z, min, max);
	v->w = clamp(v->w, min, max);
}

__A_CORE_API__ void vec1_normalize_to(vec1* v)
{
	f64 norm = 0.0;

	norm = vec1_norm(*v);

	if (norm == 0.0f)
	{
		v->x = 0.0;
		return;
	}

	vec1_scale_to(v, 1.0f / norm);
}

__A_CORE_API__ void vec2_normalize_to(vec2* v)
{
	f64 norm = 0.0;
	norm = vec2_norm(*v);

	if (norm == 0.0f)
	{
		v->x = 0.0;
		v->y = 0.0;
		return;
	}

	vec2_scale_to(v, 1.0f / norm);
}

__A_CORE_API__ void vec3_normalize_to(vec3* v)
{
	f64 norm = 0.0;

	norm = vec3_norm(*v);

	if (norm == 0.0f)
	{
		v->x = 0.0;
		v->y = 0.0;
		v->z = 0.0;
		return;
	}

	vec3_scale_to(v, 1.0f / norm);
}

__A_CORE_API__ void vec4_normalize_to(vec4* v)
{
	f64 norm = 0.0;

	norm = vec4_norm(*v);

	if (norm == 0.0f)
	{
		v->x = 0.0;
		v->y = 0.0;
		v->z = 0.0;
		v->w = 0.0;
		return;
	}

	vec4_scale_to(v, 1.0f / norm);
}

// ===============================================================