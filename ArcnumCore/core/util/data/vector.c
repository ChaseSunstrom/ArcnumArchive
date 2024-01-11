#include "vector.h"

#include "../logging/log.h"

// ==============================================================================
// VECTOR FUNCTIONS

__A_CORE_API__ vector(void*) vector_default(void)
{
	vector(void*) v = ALLOC(_vector);
	
	if (v)
	{
		v->size = 0;
		v->capacity = 1; // Sets an initial capacity (adjusts as needed)
		v->data = ALLOC(ubyte*);
	}

	return v;
}

__A_CORE_API__ vector(void*) vector_news(uint64_t size)
{
	vector(void*) v = ALLOC(_vector);

	if (v)
	{
		v->size = size;
		v->capacity = size << 1;
		v->data = calloc(size, sizeof(ubyte*));
	}

	return v;
}

__A_CORE_API__ vector(void*) _vector_new(uint64_t size, void* values[])
{
	vector(void*) v = ALLOC(_vector);

	if (v)
	{
		v->size     = size;
		v->capacity = size << 1;
		v->data     = malloc(sizeof(ubyte*) * size << 1);

		memcpy(v->data, values, size);
	}

	return v;
}

__A_CORE_API__ ubyte* vector_get(vector(void*) v, uint64_t index)
{
	if (index < v->size)
		return v->data[index];

	return NULL;
}

__A_CORE_API__ void vector_free_d(vector(void*) v)
{
	if (v)
	{
		free(v->data);
		free(v);
	}
}

__A_CORE_API__ void vector_free(vector(void*) v, void (*fn)(void*))
{
	if (v)
	{
		for (uint64_t i = 0; i < v->size; i++)
			if (vector_get(v->data, i))
				fn(v->data[i]);

		free(v->data);
		free(v);
	}
}

__A_CORE_API__ void vector_push(vector(void*) v, void* data)
{
	if (v->size >= v->capacity)
	{
		v->capacity <<= 1;
		v->data = REALLOC(v->data, ubyte*, v->capacity);
	}
	v->data[v->size] = data;
	v->size += 1;
}

__A_CORE_API__ void vector_insert(vector(void*) v, uint64_t index, void* data)
{
	while (!vector_is_big_enough(v) || v->capacity < index + 1)
		v->capacity <<= 1;

	v->data = REALLOC(v->data, ubyte*, v->capacity);

	if (!v->data)
		return;

	for (uint64_t i = v->size; i > index; i--)
		v->data[i] = v->data[i - 1];

	v->data[index] = data;
	v->size += 1;
}

__A_CORE_API__ void vector_remove(vector(void*) v, uint64_t index)
{
	if (index >= v->size)
		return;

	for (size_t i = index; i < v->size - 1; i++)
		v->data[i] = v->data[i + 1];

	v->size -= 1;
}

__A_CORE_API__ void vector_pop(vector(void*) v)
{
	if (v->size > 0)
	{
		v->size -= 1;
		vector_remove(v, v->size);
	}
}

__A_CORE_API__ void vector_clear(vector(void*) v)
{
	if (!v->data)
		return;

	v->size = 0;
	v->capacity = 1;
	free(v->data);
	v->data = ALLOC(ubyte*);
}

__A_CORE_API__ void vector_reverse(vector(void*) v)
{
	for (uint64_t i = 0; i < v->size / 2; i++)
	{
		ubyte* temp = v->data[i];
		v->data[i] = v->data[v->size - 1 - i];
		v->data[v->size - 1 - i] = temp;
	}
}

__A_CORE_API__ void vector_add_capacity(vector(void*) v, uint64_t size)
{
	while (v->capacity < v->size + size)
		v->capacity <<= 1;

	v->data = REALLOC(v->data, ubyte*, v->capacity);
}

__A_CORE_API__ void vector_set_capacity(vector(void*) v, uint64_t size)
{
	if (v->capacity > size)
		return;

	v->capacity = size;

	v->data = REALLOC(v->data, ubyte*, v->capacity);
}

__A_CORE_API__ void vector_add_vector(vector(void*) v, vector(void*) other)
{
	vector_add_capacity(v, other->size);

	if (!v->data || !other->data)
		return;

	memcpy(v->data + v->size, other->data, other->size);

	v->size += other->size;
}

__A_CORE_API__ void _vector_add_array(vector(void*) v, uint64_t size, void* array[])
{
	vector_add_capacity(v, size);

	if (!v->data || !array)
		return;

	memcpy(v->data + v->size, array, size * sizeof(void*));

	v->size += size;
}

__A_CORE_API__ void vector_remove_slice(vector(void*) v, uint64_t index, uint64_t amount)
{
	if (index + amount > v->size)
		return;

	for (uint64_t i = index; i < v->size - amount; i++)
		v->data[i] = v->data[i + amount];

	v->size -= amount;
}

__A_CORE_API__ void vector_move_data(vector(void*) v, vector(void*) other)
{
	vector_add_capacity(v, other->size);

	if (!v->data || !other->data)
		return;

	memmove(v->data + v->size, other->data, other->size * sizeof(ubyte*));

	v->size += other->size;

	vector_free_d(other);
}

__A_CORE_API__ void vector_change_data(vector(void*) v, vector(void*) other)
{
	if (v->size < other->size)
		vector_add_capacity(v, other->size);

	if (!v->data || !other->data)
		return;

	memmove(v->data + v->size, other->data, other->size * sizeof(ubyte*));

	vector_free_d(other);
}

__A_CORE_API__ __A_CORE_INLINE__ static bool vector_is_big_enough(vector(void*) v)
{
	return v->capacity - v->size > 0;
}

__A_CORE_API__ void vector_assign_data(vector(void*) v, void* data, uint64_t index)
{
	if (index >= v->capacity)
		vector_add_capacity(v, v->capacity * 2 + 1);

	if (!v->data)
		return;

	if (index > v->size)
		v->size += 1;

	v->data[index] = data;
}

//===============================================================================