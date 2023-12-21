#include "game/arcnum.h"

int main(void)
{
	vector* v1 = vector_default();
	vector* v2 = vector_default();

	vector_push(v1, 1);
	vector_push(v1, 2);
	vector_push(v1, 3);

	vector_push(v2, 4);
	vector_push(v2, 5);

	vector_add_vector(v1, v2);

	for (int i = 0; i < v1->size; i++)
		printf("%d\n", (int)vector_get(v1, i));
}