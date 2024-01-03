#include "map.h"



// ==============================================================================
// MAP FUNCTIONS:

__A_CORE_API__ __A_CORE_INLINE__ bool pair_compare(pair* pair, generic key)
{
	return pair->key == key;
}

__A_CORE_API__ map(generic, generic) map_new()
{
	map(generic, generic) map = ALLOC(_map);
	map->pairs = vector_default();
	map->size = map->pairs->size;
	map->capacity = map->pairs->capacity;
	return map;
}

__A_CORE_API__ void map_insert(map(generic, generic) _map, generic key, generic value)
{
	pair* _pair = ALLOC(pair);
	_pair->key = key;
	_pair->value = value;
	vector_push(_map->pairs, _pair);
	_map->size = _map->pairs->size;
	_map->capacity = _map->pairs->capacity;
}

__A_CORE_API__ generic map_get(map(generic, generic) _map, generic key)
{
	for (int i = 0; i < _map->pairs->size; i++)
	{
		pair* _pair = _map->pairs->data[i];
		if (pair_compare(_pair, key))
		{
			return _pair->value;
		}
	}
	return NULL;
}

__A_CORE_API__ void map_remove(map(generic, generic) _map, generic key)
{
	for (int i = 0; i < _map->pairs->size; i++)
	{
		pair* _pair = _map->pairs->data[i];
		if (pair_compare(_pair, key))
		{
			vector_remove(_map->pairs, i);
			FREE(_pair);
			break;
		}
	}

	_map->size = _map->pairs->size;
	_map->capacity = _map->pairs->capacity;
}

// ==============================================================================