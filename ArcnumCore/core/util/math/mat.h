#ifndef CORE_MAT_H
#define CORE_MAT_H

#include "../data/vector.h"

typedef struct
{
	size_t size;
	double scalar;
} scalar;

typedef struct
{
	size_t  rows;
	size_t  cols;
	double* matrix;
} mat;

mat  mat_new(double rows, double cols, double* matrix);
mat  mdot(mat m1, mat m2);
mat  msdot(double scalar, mat m1);
void mat_free(mat mat);


#endif // CORE_MAT_H