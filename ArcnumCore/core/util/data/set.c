#include "set.h"

__A_CORE_API__ set(void*) set_default()
{
	set(void*) set = ALLOC(_set);
	set->data = vector_default();
	set->capacity = set->data->capacity;
	set->size = set->data->size;
	return set;
}
 
__A_CORE_API__ void set_insert(set(void*) _set, uint64_t index, void* data)
{
	for (uint64_t i = 0; i < _set->data->size; i++)
		if (vector_get(_set->data, i) == data)
			return;

	vector_insert(_set->data, index, data);
	_set->size = _set->data->size;
	_set->capacity = _set->data->capacity;
}

__A_CORE_API__ void set_push(set(void*) _set, void* data)
{
	for (uint64_t i = 0; i < _set->data->size; i++)
		if (vector_get(_set->data, i) == data)
			return;

	vector_push(_set->data, data);
	_set->size = _set->data->size;
	_set->capacity = _set->data->capacity;
}

__A_CORE_API__ void* set_get(set(void*) _set, uint64_t index)
{
	return vector_get(_set->data, index);
}

__A_CORE_API__ void set_remove(set(void*) _set, uint64_t index)
{
	vector_remove(_set->data, index);
}

__A_CORE_API__ void set_free_d(set(void*) _set)
{
	vector_free_d(_set->data);
	free(_set);
}

__A_CORE_API__ void set_free(set(void*) set, void (*free_fn)(void*))
{
	vector_free(set->data, free_fn);
	free(set);
}