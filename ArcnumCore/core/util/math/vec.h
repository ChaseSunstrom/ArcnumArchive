#ifndef CORE_VEC_H
#define CORE_VEC_H

#include "../std_include.h"

#define VEC1_SIZE 1
#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4

// ===============================================================
// VEC STRUCTS:  | Used to store position data

typedef struct
{
	byte vec_size;
	f64  x;
} vec1;

typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
} vec2;

typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
	f64  z;
} vec3;

typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
	f64  z;
	f64  w;
} vec4;

// ===============================================================



// ===============================================================
// VEC FUNCTIONS:

vec1 vec1_default();
vec1 vec1_new(f64 x);
vec2 vec2_default();
vec2 vec2_new(f64 x, f64 y);
vec3 vec3_default();
vec3 vec3_new(f64 x, f64 y, f64 z);
vec4 vec4_default();
vec4 vec4_new(f64 x, f64 y, f64 z, f64 w);

vec1 vec1_add(vec1 v1, vec1 v2);
vec2 vec2_add(vec2 v1, vec2 v2);
vec3 vec3_add(vec3 v1, vec3 v2);
vec4 vec4_add(vec4 v1, vec4 v2);

// ===============================================================

#endif // CORE_VEC_H