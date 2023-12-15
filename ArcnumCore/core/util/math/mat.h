#ifndef CORE_MAT_H
#define CORE_MAT_H

#include "../data/vector.h"

AC_CORE_API typedef struct
{
	u64 size;
	f64 scalar;
} scalar;

AC_CORE_API typedef struct
{
	u64  rows;
	u64  cols;
	f64* matrix;
} mat;

AC_CORE_API mat  mat_new(f64 rows, f64 cols, f64* matrix);
AC_CORE_API mat  mdot(mat m1, mat m2);
AC_CORE_API mat  msdot(f64 scalar, mat m1);
//T because this can return any sized vector
AC_CORE_API T    mvdot(T vec, mat m1);
AC_CORE_API void mat_free(mat mat);


#endif // CORE_MAT_H