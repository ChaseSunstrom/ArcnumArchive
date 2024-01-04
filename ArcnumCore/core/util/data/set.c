#include "set.h"

__A_CORE_API__ set(generic) set_default()
{
	set(generic) set = ALLOC(_set);
	set->data = vector_default();
	set->capacity = set->data->capacity;
	set->size = set->data->size;
	return set;
}

__A_CORE_API__ void set_insert(set(generic) _set, u64 index, generic data)
{
	for (u64 i = 0; i < _set->data->size; i++)
		if (vector_get(_set->data, i) == data)
			return;

	vector_insert(_set->data, index, data);
	_set->size = _set->data->size;
	_set->capacity = _set->data->capacity;
}

__A_CORE_API__ void set_push(set(generic) _set, generic data)
{
	for (u64 i = 0; i < _set->data->size; i++)
		if (vector_get(_set->data, i) == data)
			return;

	vector_push(_set->data, data);
	_set->size = _set->data->size;
	_set->capacity = _set->data->capacity;
}

__A_CORE_API__ generic set_get(set(generic) _set, u64 index)
{
	return vector_get(_set->data, index);
}

__A_CORE_API__ void set_remove(set(generic) _set, u64 index)
{
	vector_remove(_set->data, index);
}

__A_CORE_API__ void set_free(set(generic) _set)
{
	vector_free(_set->data);
	FREE(_set);
}