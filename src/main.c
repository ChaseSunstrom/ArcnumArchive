#include "core/util/math/mat.h"
#include "game/arcnum.h"

int main(void)
{
	vec2 vec = vec2_new(1, 2);
	mat  _mat = mat_new(2, 2, (f64[]) { 1.0, 2.0, 3.0, 4.0 });

	mat result = mvdot(&vec, _mat);

	for (i32 i = 0; i < 2; ++i)
	{
		for (i32 j = 0; j < 2; ++j)
		{
			printf("%f\n", result.matrix[i * 2 + j]);
		}
	}
}
