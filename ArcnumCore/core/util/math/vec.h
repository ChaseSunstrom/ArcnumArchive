#ifndef CORE_VEC_H
#define CORE_VEC_H

// ===============================================================
// VEC STRUCTS:  | Used to store position data

typedef struct
{
	f64 x;
} vec1;

typedef struct
{
	double x;
	f64 y;
} vec2;

typedef struct
{
	f64 x;
	f64 y;
	f64 z;
} vec3;

typedef struct
{
	f64 x;
	f64 y;
	f64 z;
	f64 w;
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

// ===============================================================

#endif // CORE_VEC_H