#ifndef CORE_VEC_H
#define CORE_VEC_H

#include "../std_include.h"

#define VEC1_SIZE 1
#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4

// ===============================================================
// VEC STRUCTS:  | Used to store position data

__A_CORE_API__ typedef struct
{
	byte vec_size;
	f64  x;
} vec1;

__A_CORE_API__ typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
} vec2;

__A_CORE_API__ typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
	f64  z;
} vec3;

__A_CORE_API__ typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
	f64  z;
	f64  w;
} vec4;

typedef vec4 quat;

// ===============================================================



// ===============================================================
// VEC FUNCTIONS:

__A_CORE_API__ vec1 vec1_default();
__A_CORE_API__ vec1 vec1_new(f64 x);
__A_CORE_API__ vec2 vec2_default();
__A_CORE_API__ vec2 vec2_new(f64 x, f64 y);
__A_CORE_API__ vec3 vec3_default();
__A_CORE_API__ vec3 vec3_new(f64 x, f64 y, f64 z);
__A_CORE_API__ vec4 vec4_default();
__A_CORE_API__ vec4 vec4_new(f64 x, f64 y, f64 z, f64 w);
#define quat_default() vec4_default()
#define quat_new(_x, _y, _z, _w) vec4_new(_x, _y, _z, _w)

__A_CORE_API__ vec1 vec1_add(vec1 v1, vec1 v2);
__A_CORE_API__ vec2 vec2_add(vec2 v1, vec2 v2);
__A_CORE_API__ vec3 vec3_add(vec3 v1, vec3 v2);
__A_CORE_API__ vec4 vec4_add(vec4 v1, vec4 v2);
__A_CORE_API__ vec1 vec1_mul(vec1 v1, vec1 v2);
__A_CORE_API__ vec2 vec2_mul(vec2 v1, vec2 v2);
__A_CORE_API__ vec3 vec3_mul(vec3 v1, vec3 v2);
__A_CORE_API__ vec4 vec4_mul(vec4 v1, vec4 v2);
__A_CORE_API__ vec1 vec1_sub(vec1 v1, vec1 v2);
__A_CORE_API__ vec2 vec2_sub(vec2 v1, vec2 v2);
__A_CORE_API__ vec3 vec3_sub(vec3 v1, vec3 v2);
__A_CORE_API__ vec4 vec4_sub(vec4 v1, vec4 v2);
__A_CORE_API__ vec1 vec1_div(vec1 v1, vec1 v2);
__A_CORE_API__ vec2 vec2_div(vec2 v1, vec2 v2);
__A_CORE_API__ vec3 vec3_div(vec3 v1, vec3 v2);
__A_CORE_API__ vec4 vec4_div(vec4 v1, vec4 v2);

__A_CORE_API__ __A_CORE_INLINE__ vec3 vec3_cross(vec3 v1, vec3 v2);

__A_CORE_API__ __A_CORE_INLINE__ f64 vec1_dot(vec1 v1, vec1 v2);
__A_CORE_API__ __A_CORE_INLINE__ f64 vec2_dot(vec2 v1, vec2 v2);
__A_CORE_API__ __A_CORE_INLINE__ f64 vec3_dot(vec3 v1, vec3 v2);
__A_CORE_API__ __A_CORE_INLINE__ f64 vec4_dot(vec4 v1, vec4 v2);

__A_CORE_API__ __A_CORE_INLINE__ f64 _vec1_norm(vec1 v);
__A_CORE_API__ __A_CORE_INLINE__ f64 _vec2_norm(vec2 v);
__A_CORE_API__ __A_CORE_INLINE__ f64 _vec3_norm(vec3 v);
__A_CORE_API__ __A_CORE_INLINE__ f64 _vec4_norm(vec4 v);

__A_CORE_API__ __A_CORE_INLINE__ f64 vec1_norm(vec1 v);
__A_CORE_API__ __A_CORE_INLINE__ f64 vec2_norm(vec2 v);
__A_CORE_API__ __A_CORE_INLINE__ f64 vec3_norm(vec3 v);
__A_CORE_API__ __A_CORE_INLINE__ f64 vec4_norm(vec4 v);

__A_CORE_API__ __A_CORE_INLINE__ vec1 vec1_scale(vec1 v, f64 scale);
__A_CORE_API__ __A_CORE_INLINE__ vec2 vec2_scale(vec2 v, f64 scale);
__A_CORE_API__ __A_CORE_INLINE__ vec3 vec3_scale(vec3 v, f64 scale);
__A_CORE_API__ __A_CORE_INLINE__ vec4 vec4_scale(vec4 v, f64 scale);

__A_CORE_API__ __A_CORE_INLINE__ vec1 vec1_clamp(vec1 v, f64 min, f64 max);
__A_CORE_API__ __A_CORE_INLINE__ vec2 vec2_clamp(vec2 v, f64 min, f64 max);
__A_CORE_API__ __A_CORE_INLINE__ vec3 vec3_clamp(vec3 v, f64 min, f64 max);
__A_CORE_API__ __A_CORE_INLINE__ vec4 vec4_clamp(vec4 v, f64 min, f64 max);

__A_CORE_API__ vec1 vec1_normalize(vec1 v);
__A_CORE_API__ vec2 vec2_normalize(vec2 v);
__A_CORE_API__ vec3 vec3_normalize(vec3 v);
__A_CORE_API__ vec4 vec4_normalize(vec4 v);

__A_CORE_API__ vec3 vec3_rotate(vec3 v, vec3 axis, f64 angle);

__A_CORE_API__ void vec1_add_to(vec1* v1, vec1* v2);
__A_CORE_API__ void vec2_add_to(vec2* v1, vec2* v2);
__A_CORE_API__ void vec3_add_to(vec3* v1, vec3* v2);
__A_CORE_API__ void vec4_add_to(vec4* v1, vec4* v2);
__A_CORE_API__ void vec1_mul_to(vec1* v1, vec1* v2);
__A_CORE_API__ void vec2_mul_to(vec2* v1, vec2* v2);
__A_CORE_API__ void vec3_mul_to(vec3* v1, vec3* v2);
__A_CORE_API__ void vec4_mul_to(vec4* v1, vec4* v2);
__A_CORE_API__ void vec1_sub_to(vec1* v1, vec1* v2);
__A_CORE_API__ void vec2_sub_to(vec2* v1, vec2* v2);
__A_CORE_API__ void vec3_sub_to(vec3* v1, vec3* v2);
__A_CORE_API__ void vec4_sub_to(vec4* v1, vec4* v2);
__A_CORE_API__ void vec1_div_to(vec1* v1, vec1* v2);
__A_CORE_API__ void vec2_div_to(vec2* v1, vec2* v2);
__A_CORE_API__ void vec3_div_to(vec3* v1, vec3* v2);
__A_CORE_API__ void vec4_div_to(vec4* v1, vec4* v2);

__A_CORE_API__ __A_CORE_INLINE__ void vec3_cross_to(vec3* v1, vec3* v2);

__A_CORE_API__ __A_CORE_INLINE__ void vec1_scale_to(vec1* v, f64 scale);
__A_CORE_API__ __A_CORE_INLINE__ void vec2_scale_to(vec2* v, f64 scale);
__A_CORE_API__ __A_CORE_INLINE__ void vec3_scale_to(vec3* v, f64 scale);
__A_CORE_API__ __A_CORE_INLINE__ void vec4_scale_to(vec4* v, f64 scale);

__A_CORE_API__ __A_CORE_INLINE__ void vec1_clamp_to(vec1* v, f64 min, f64 max);
__A_CORE_API__ __A_CORE_INLINE__ void vec2_clamp_to(vec2* v, f64 min, f64 max);
__A_CORE_API__ __A_CORE_INLINE__ void vec3_clamp_to(vec3* v, f64 min, f64 max);
__A_CORE_API__ __A_CORE_INLINE__ void vec4_clamp_to(vec4* v, f64 min, f64 max);

__A_CORE_API__ void vec1_normalize_to(vec1* v);
__A_CORE_API__ void vec2_normalize_to(vec2* v);
__A_CORE_API__ void vec3_normalize_to(vec3* v);
__A_CORE_API__ void vec4_normalize_to(vec4* v);

__A_CORE_API__ void vec3_rotate_to(vec3* v, vec3 axis, f64 angle);

// ===============================================================

#endif // CORE_VEC_H