#include "map.h"

__A_CORE_API__ bool pair_compare(pair* pair, T key)
{
	return pair->key == key;
}

__A_CORE_API__ map* map_new()
{
	map* _map = ALLOC(map);
	_map->pairs = vector_new();
	_map->size = _map->pairs->size;
	_map->capacity = _map->pairs->capacity;
	return _map;
}

__A_CORE_API__ void map_insert(map* _map, void* key, void* value)
{
	pair* _pair = ALLOC(pair);
	_pair->key = key;
	_pair->value = value;
	vector_push(_map->pairs, _pair);
	_map->size = _map->pairs->size;
	_map->capacity = _map->pairs->capacity;
}

__A_CORE_API__ T map_get(map* _map, void* key)
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

__A_CORE_API__ void map_remove(map* _map, void* key)
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