#include "../memory/alloc.h"
#include "mat.h"

#include <stdarg.h>
#include <stdlib.h>

#include "vec.h"

mat mat_new(f64 rows, f64 cols, f64* matrix)
{
	mat mat = { rows, cols, matrix };
	return mat;
}

mat mdot(mat m1, mat m2)
{
	u64 rows1 = m1.rows;
	u64 rows2 = m2.rows;
	u64 cols1 = m1.cols;
	u64 cols2 = m2.cols;

	mat result = { rows1, cols2, (f64*)malloc(sizeof(f64) * rows1 * cols2) };

	if (cols1 != rows2)
	{
		result.rows = 0;
		result.cols = 0;
		mat_free(result);
		return result;
	}

	for (i32 i = 0; i < rows1; ++i)
	{
		for (i32 j = 0; j < cols2; ++j)
		{
			result.matrix[i * result.cols + j] = 0.0;
			for (i32 k = 0; k < cols1; ++k)
			{
				result.matrix[i * result.cols + j] += m1.matrix[i * cols1 + k] * m2.matrix[k * cols2 + j];
			}
		}
	}

	return result;
}

mat msdot(f64 scalar, mat m1)
{
	u64 rows = m1.rows;
	u64 cols = m1.cols;

	mat result = { rows, cols, (f64*)malloc(sizeof(f64) * rows * cols) };

	for (i32 i = 0; i < rows; ++i)
	{
		for (i32 j = 0; j < cols; ++j)
		{
			result.matrix[i * cols + j] = m1.matrix[i * cols + j] * scalar;
		}
	}

	return result;
}

mat mvdot(T vec, mat m1)
{
	u64 vec_size = ((vec4*)vec)->vec_size;
	u64 rows = m1.rows;
	u64 cols = m1.cols;

	if (cols != vec_size)
	{
		mat result = { 0, 0, NULL };
		return result;
	}

	mat result = { rows, 1, (f64*)malloc(sizeof(f64) * rows) };

	for (u64 i = 0; i < rows; ++i)
	{
		result.matrix[i] = 0.0;
		for (u64 k = 0; k < cols; ++k)
		{
			result.matrix[i] += m1.matrix[i * cols + k] * ((f64*)vec)[k + 1];
		}
	}

	return result;
}

void mat_free(mat mat)
{
	FREE(mat.matrix);
}