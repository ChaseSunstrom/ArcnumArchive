#include "../memory/alloc.h"
#include "mat.h"

#include <stdarg.h>
#include <stdlib.h>

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

	mat result = { m1.rows, m2.cols, (f64*)malloc(sizeof(f64) * m1.rows * m2.cols) };

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

void mat_free(mat mat)
{
	FREE(mat.matrix);
}