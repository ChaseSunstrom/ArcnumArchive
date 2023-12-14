#ifndef CORE_MAT_H
#define CORE_MAT_H

#include "../data/vector.h"

typedef struct
{
	u64 size;
	f64 scalar;
} scalar;

typedef struct
{
	u64  rows;
	u64  cols;
	f64* matrix;
} mat;

mat  mat_new(f64 rows, f64 cols, f64* matrix);
mat  mdot(mat m1, mat m2);
mat  msdot(f64 scalar, mat m1);
void mat_free(mat mat);


#endif // CORE_MAT_H