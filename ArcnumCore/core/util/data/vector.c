#include "vector.h"

// ==============================================================================
// VECTOR FUNCTIONS

__A_CORE_API__ vector(generic) vector_default(void)
{
	vector(generic) v = ALLOC(_vector);
	
	if (v != NULL)
	{
		v->size = 0;
		v->capacity = 1; // Sets an initial capacity (adjusts as needed)
		v->data = ALLOC(byte*);
	}

	return v;
}

__A_CORE_API__ vector(generic) _vector_new(u64 size, generic values[])
{
	vector(generic) v = ALLOC(_vector);

	if (v != NULL)
	{
		v->size     = size;
		v->capacity = size << 1;
		v->data     = ALLOC(byte*);

		vector_add_capacity(v, size);

		memcpy(v->data, values, size * sizeof(generic));
	}

	return v;
}

__A_CORE_API__ byte* vector_get(vector(generic) v, u64 index)
{
	if (index < v->size)
		return v->data[index];

	return NULL;
}

__A_CORE_API__ void vector_free(vector(generic) v)
{
	if (v)
	{
		FREE(v->data);
		FREE(v);
	}
}

__A_CORE_API__ void vector_push(vector(generic) v, generic data)
{
	if (v->size >= v->capacity)
	{
		v->capacity <<= 1;
		v->data = REALLOC(v->data, byte*, v->capacity);
	}
	v->data[v->size] = data;
	v->size += 1;
}

__A_CORE_API__ void vector_insert(vector(generic) v, u64 index, generic data)
{
	if (index > v->size)
	{
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

__A_CORE_API__ void vector_remove(vector(generic) v, u64 index)
{
	if (index >= v->size)
	{
		return;
	}

	for (size_t i = index; i < v->size - 1; i++)
	{
		v->data[i] = v->data[i + 1];
	}

	v->size -= 1;
}

__A_CORE_API__ void vector_pop(vector(generic) v)
{
	if (v->size > 0)
	{
		v->size -= 1;
		vector_remove(v, v->size);
	}
}

__A_CORE_API__ void vector_clear(vector(generic) v)
{
	v->size = 0;
	v->capacity = 1;
	free(v->data);
	v->data = ALLOC(byte*);
}

__A_CORE_API__ void vector_reverse(vector(generic) v)
{
	for (u64 i = 0; i < v->size / 2; i++)
	{
		byte* temp = v->data[i];
		v->data[i] = v->data[v->size - 1 - i];
		v->data[v->size - 1 - i] = temp;
	}
}

__A_CORE_API__ void vector_add_capacity(vector(generic) v, u64 size)
{
	while (v->capacity < v->size + size)
		v->capacity <<= 1;

	v->data = REALLOC(v->data, byte*, v->capacity);
}

__A_CORE_API__ void vector_add_vector(vector(generic) v, vector(generic) other)
{
	vector_add_capacity(v, other->size);

	memcpy(v->data + v->size, other->data, other->size * sizeof(byte*));

	v->size += other->size;
}

__A_CORE_API__ void _vector_add_array(vector(generic) v, u64 size, generic array[])
{
	vector_add_capacity(v, size);

	memcpy(v->data + v->size, array, size * sizeof(generic));

	v->size += size;
}

__A_CORE_API__ void vector_remove_slice(vector(generic) v, u64 index, u64 amount)
{
	if (index + amount > v->size)
		return;

	for (u64 i = index; i < v->size - amount; i++)
		v->data[i] = v->data[i + amount];

	v->size -= amount;
}

__A_CORE_API__ void vector_move_data(vector(generic) v, vector(generic) other)
{
	vector_add_capacity(v, other->size);

	memmove(v->data + v->size, other->data, other->size * sizeof(byte*));

	v->size += other->size;

	vector_free(other);
}

__A_CORE_API__ void vector_change_data(vector(generic) v, vector(generic) other)
{
	if (v->size < other->size)
		vector_add_capacity(v, other->size);

	memmove(v->data + v->size, other->data, other->size * sizeof(byte*));

	vector_free(other);
}

__A_CORE_API__ __A_CORE_INLINE__ static bool vector_is_big_enough(vector(generic) v)
{
	return v->capacity - v->size > 0;
}

//===============================================================================