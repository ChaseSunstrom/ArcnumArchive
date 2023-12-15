
#include "vector.h"

// ==============================================================================
// VECTOR FUNCTIONS

AC_CORE_API vector* vector_new(void)
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

AC_CORE_API byte* vector_get(vector* v, u64 index)
{
	if (index < v->size)
		return v->data[index];

	printf("VECTOR INDEX OUT OF RANGE: %u\n", index);
	exit(EXIT_FAILURE);
}

AC_CORE_API void vector_free(vector* v)
{
	if (v)
	{
		FREE(v->data);
		FREE(v);
	}
}

AC_CORE_API void vector_push(vector* v, T data)
{
	if (v->size >= v->capacity)
	{
		v->capacity <<= 1;
		v->data = REALLOC(v->data, byte*, v->capacity);
	}
	v->data[v->size] = data;
	v->size += 1;
}

AC_CORE_API void vector_insert(vector* v, u64 index, T data)
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

	for (u64 i = v->size; i > index; i--)
	{
		v->data[i] = v->data[i - 1];
	}

	v->data[index] = data;
	v->size += 1;
}

AC_CORE_API void vector_remove(vector* v, u64 index)
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

AC_CORE_API void vector_pop(vector* v)
{
	if (v->size > 0)
	{
		v->size -= 1;
		vector_remove(v, v->size);
	}
}

AC_CORE_API void vector_clear(vector* v)
{
	v->size = 0;
	v->capacity = 1;
	free(v->data);
	v->data = ALLOC(byte*);
}

AC_CORE_API void vector_reverse(vector* v)
{
	for (u64 i = 0; i < v->size / 2; i++)
	{
		byte* temp = v->data[i];
		v->data[i] = v->data[v->size - 1 - i];
		v->data[v->size - 1 - i] = temp;
	}
}

AC_CORE_API static inline bool vector_is_big_enough(vector* v)
{
	return v->capacity - v->size > 0;
}

//===============================================================================