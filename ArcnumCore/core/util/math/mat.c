#include "../memory/alloc.h"
#include "mat.h"

#include <stdarg.h>
#include <stdlib.h>

mat mat_new(double rows, double cols, double* matrix)
{
	mat mat = { rows, cols, matrix };
	return mat;
}

mat mdot(mat m1, mat m2)
{
	size_t rows1 = m1.rows;
	size_t rows2 = m2.rows;
	size_t cols1 = m1.cols;
	size_t cols2 = m2.cols;

	mat result = { m1.rows, m2.cols, (double*)malloc(sizeof(double) * m1.rows * m2.cols) };

	if (cols1 != rows2)
	{
		result.rows = 0;
		result.cols = 0;
		mat_free(result);
		return result;
	}

	for (int i = 0; i < rows1; ++i)
	{
		for (int j = 0; j < cols2; ++j)
		{
			result.matrix[i * result.cols + j] = 0.0;
			for (int k = 0; k < cols1; ++k)
			{
				result.matrix[i * result.cols + j] += m1.matrix[i * cols1 + k] * m2.matrix[k * cols2 + j];
			}
		}
	}

	return result;
}

mat msdot(double scalar, mat m1)
{
	size_t rows = m1.rows;
	size_t cols = m1.cols;

	mat result = { rows, cols, (double*)malloc(sizeof(double) * rows * cols) };

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
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