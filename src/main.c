#include <stdio.h>
#include <core/util/math/mat.h>

#include "core/util/data/vector.h"

int main(void)
{
	mat m1 = { 2, 2, (double[]) { 1, 2, 3, 4 }};
	mat res = msdot(12, m1);

	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 2; j++) 
		{
			printf("%f ", res.matrix[i * res.cols + j]);
		}
		printf(" \n");
	}
}
