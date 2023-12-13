
#include "vector.h"

// ==============================================================================
// VECTOR FUNCTIONS

vector* vector_new(void)
{
	vector* v = ALLOC(vector);
	
	if (v != NULL)
	{
		v->size = 0;
		v->capacity = 1; // Sets an initial capacity (adjusts as needed)
		v->data = ALLOC(byte*);
	}

	return v;
}

byte* vector_get(vector* v, size_t index)
{
	if (index < v->size)
		return v->data[index];

	printf("VECTOR INDEX OUT OF RANGE: %u\n", index);
	exit(EXIT_FAILURE);
}

void vector_free(vector* v)
{
	if (v)
	{
		FREE(v->data);
		FREE(v);
	}
}
void vector_push(vector* v, void* data)
{
	if (v->size >= v->capacity)
	{
		v->capacity <<= 1;
		v->data = REALLOC(v->data, byte*, v->capacity);
	}
	v->data[v->size] = data;
	v->size += 1;
}

void vector_insert(vector* v, size_t index, void* data)
{
	if (index > v->size)
	{
		printf("VECTOR INDEX OUT OF RANGE: %u\n", index);
		return;
	}

	if (!vector_is_big_enough(v))
	{
		v->capacity <<= 1;
		v->data = REALLOC(v->data, byte*, v->capacity);
	}

	for (size_t i = v->size; i > index; i--)
	{
		v->data[i] = v->data[i - 1];
	}

	v->data[index] = data;
	v->size += 1;
}

void vector_remove(vector* v, size_t index)
{
	if (index >= v->size)
	{
		printf("VECTOR INDEX OUT OF RANGE: %u\n", index);
		return;
	}

	for (size_t i = index; i < v->size - 1; i++)
	{
		v->data[i] = v->data[i + 1];
	}

	v->size -= 1;
}

void vector_pop(vector* v)
{
	if (v->size > 0)
	{
		v->size -= 1;
		vector_remove(v, v->size);
	}
}

void vector_clear(vector* v)
{
	v->size = 0;
	v->capacity = 1;
	free(v->data);
	v->data = ALLOC(byte*);
}

void vector_reverse(vector* v)
{
	for (size_t i = 0; i < v->size / 2; i++)
	{
		byte* temp = v->data[i];
		v->data[i] = v->data[v->size - 1 - i];
		v->data[v->size - 1 - i] = temp;
	}
}

static inline bool vector_is_big_enough(vector* v)
{
	return v->capacity - v->size > 0;
}

//===============================================================================