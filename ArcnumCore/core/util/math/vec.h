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

// ===============================================================



// ===============================================================
// VEC FUNCTIONS:

vec1 vec1_default();
vec1 vec1_new(double x);
vec2 vec2_default();
vec2 vec2_new(double x, double y);
vec3 vec3_default();
vec3 vec3_new(double x, double y, double z);

// ===============================================================

#endif // CORE_VEC_H