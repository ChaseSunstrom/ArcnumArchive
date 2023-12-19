#include "map.h"

bool pair_compare(pair* pair, T key)
{
	return pair->key == key;
}

map* map_new()
{
	map* _map = ALLOC(map);
	_map->pairs = vector_new();
	return _map;
}

void map_insert(map* _map, void* key, void* value)
{
	pair* _pair = ALLOC(pair);
	_pair->key = key;
	_pair->value = value;
	vector_push(_map->pairs, _pair);
}

T map_get(map* _map, void* key)
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

void map_remove(map* _map, void* key)
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
}