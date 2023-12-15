#ifndef CORE_MAT_H
#define CORE_MAT_H

#include "../data/vector.h"

__A_CORE_API__ typedef struct
{
	u64 size;
	f64 scalar;
} scalar;

__A_CORE_API__ typedef struct
{
	u64  rows;
	u64  cols;
	f64* matrix;
} mat;

__A_CORE_API__ mat  mat_new(f64 rows, f64 cols, f64* matrix);
__A_CORE_API__ mat  mdot(mat m1, mat m2);
__A_CORE_API__ mat  msdot(f64 scalar, mat m1);
//T because this can return any sized vector
__A_CORE_API__ T    mvdot(T vec, mat m1);
__A_CORE_API__ __A_CORE_INLINE__ void mat_free(mat mat);


#endif // CORE_MAT_H