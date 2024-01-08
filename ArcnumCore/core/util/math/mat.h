#ifndef CORE_MAT_H
#define CORE_MAT_H

#include "../data/vector.h"



// ==============================================================================
// MAT           | Used to store a matrix, with information on its size
// ==============================================================================
__A_CORE_API__ typedef struct
{
	uint64_t  rows;
	uint64_t  cols;
	float64_t* matrix;
} mat;



// ==============================================================================
// MAT FUNCTIONS:

__A_CORE_API__ mat     mat_new(float64_t rows, float64_t cols, float64_t* matrix);
__A_CORE_API__ mat     mdot(mat m1, mat m2);
__A_CORE_API__ mat     msdot(float64_t scalar, mat m1);
//void* because this can return any sized vector
__A_CORE_API__ void* mvdot(void* vec, mat m1);
__A_CORE_API__ __A_CORE_INLINE__ void mat_free(mat mat);

// ==============================================================================

#endif // CORE_MAT_H