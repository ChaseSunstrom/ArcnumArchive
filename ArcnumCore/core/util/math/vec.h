#ifndef CORE_VEC_H
#define CORE_VEC_H

// ===============================================================
// VEC STRUCTS:  | Used to store position data

typedef struct
{
	double x;
} vec1;

typedef struct
{
	double x;
	double y;
} vec2;

typedef struct
{
	double x;
	double y;
	double z;
} vec3;

typedef struct
{
	double x;
	double y;
	double z;
	double w;
} vec4;

// ===============================================================



// ===============================================================
// VEC FUNCTIONS:

vec1 vec1_default();
vec1 vec1_new(double x);
vec2 vec2_default();
vec2 vec2_new(double x, double y);
vec3 vec3_default();
vec3 vec3_new(double x, double y, double z);
vec4 vec4_default();
vec4 vec4_new(double x, double y, double z, double w);

// ===============================================================

#endif // CORE_VEC_H