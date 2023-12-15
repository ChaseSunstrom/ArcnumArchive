#ifndef CORE_VEC_H
#define CORE_VEC_H

#include "../std_include.h"

#define VEC1_SIZE 1
#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4

// ===============================================================
// VEC STRUCTS:  | Used to store position data

AC_CORE_API typedef struct
{
	byte vec_size;
	f64  x;
} vec1;

AC_CORE_API typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
} vec2;

AC_CORE_API typedef struct
{
	byte vec_size;
	f64  x;
	f64  y;
	f64  z;
} vec3;

AC_CORE_API typedef struct
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

AC_CORE_API vec1 vec1_default();
AC_CORE_API vec1 vec1_new(f64 x);
AC_CORE_API vec2 vec2_default();
AC_CORE_API vec2 vec2_new(f64 x, f64 y);
AC_CORE_API vec3 vec3_default();
AC_CORE_API vec3 vec3_new(f64 x, f64 y, f64 z);
AC_CORE_API vec4 vec4_default();
AC_CORE_API vec4 vec4_new(f64 x, f64 y, f64 z, f64 w);

AC_CORE_API vec1 vec1_add(vec1 v1, vec1 v2);
AC_CORE_API vec2 vec2_add(vec2 v1, vec2 v2);
AC_CORE_API vec3 vec3_add(vec3 v1, vec3 v2);
AC_CORE_API vec4 vec4_add(vec4 v1, vec4 v2);

// ===============================================================

#endif // CORE_VEC_H