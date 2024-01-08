#include "../memory/alloc.h"
#include "mat.h"

#include <stdarg.h>
#include <stdlib.h>

#include "vec.h"


// ==============================================================================
// MAT FUNCTIONS:

__A_CORE_API__ mat mat_new(float64_t rows, float64_t cols, float64_t* matrix)
{
	mat mat = { rows, cols, matrix };
	return mat;
}

__A_CORE_API__ mat mdot(mat m1, mat m2)
{
	uint64_t rows1 = m1.rows;
	uint64_t rows2 = m2.rows;
	uint64_t cols1 = m1.cols;
	uint64_t cols2 = m2.cols;

	mat result = { rows1, cols2, (float64_t*)calloc(rows1 * cols2, sizeof(float64_t)) };

	if (cols1 != rows2)
	{
		result.rows = 0;
		result.cols = 0;
		mat_free(result);
		return result;
	}

	for (int32_t i = 0; i < rows1; ++i)
	{
		for (int32_t j = 0; j < cols2; ++j)
		{
			result.matrix[i * result.cols + j] = 0.0;
			for (int32_t k = 0; k < cols1; ++k)
			{
				result.matrix[i * result.cols + j] += m1.matrix[i * cols1 + k] * m2.matrix[k * cols2 + j];
			}
		}
	}

	return result;
}

__A_CORE_API__ mat msdot(float64_t scalar, mat m1)
{
	uint64_t rows = m1.rows;
	uint64_t cols = m1.cols;

	mat result = { rows, cols, (float64_t*)calloc(rows * cols,sizeof(float64_t)) };

	for (int32_t i = 0; i < rows; ++i)
	{
		for (int32_t j = 0; j < cols; ++j)
		{
			result.matrix[i * cols + j] = m1.matrix[i * cols + j] * scalar;
		}
	}

	return result;
}

__A_CORE_API__ void* mvdot(void* vec, mat m1)
{
	uint64_t vec_size = ((vec4*)vec)->vec_size;
	uint64_t rows = m1.rows;
	uint64_t cols = m1.cols;

	if (cols != vec_size)
		return NULL;

	mat result = { rows, 1, (float64_t*)calloc(rows, sizeof(float64_t)) };

	for (uint64_t i = 0; i < rows; ++i)
	{
		result.matrix[i] = 0.0;
		for (uint64_t k = 0; k < cols; ++k)
		{
			result.matrix[i] += m1.matrix[i * cols + k] * ((float64_t*)vec)[k + 1];
		}
	}

	vec4* _vec = ALLOC(vec4);
	_vec->vec_size = vec_size;

	for (uint64_t i = 0; i < rows; i++)
		((float64_t*)_vec)[i + 1] = result.matrix[i];

	mat_free(result);

	return _vec;
}

__A_CORE_API__ __A_CORE_INLINE__ void mat_free(mat mat)
{
	FREE(mat.matrix);
}

// ==============================================================================