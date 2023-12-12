#include "map.h"

// ===============================================================================
// MAP FUNCTIONS

map* map_new(void)
{
	map* m = ALLOC(map);

	if (m != NULL)
	{
		m->size = 0;
		m->capacity = 2;
		m->pairs = vector_new();
	}

	return m;
}

void map_insert(map* m, void* key, void* value)
{
	if (m->size == m->capacity)
	{
		m->capacity *= 2;
	}

	pair* _pair = ALLOC(pair);

	if (_pair == NULL)
	{
		return;
	}

	_pair->key = key;
	_pair->index = m->size;
	_pair->value = value;

	vector_push(m->pairs, _pair);
	m->size++;
}

void* map_find(map* m, void* key)
{
	for (size_t i = 0; i < m->size; i++)
	{
		const pair* current_pair = (pair*)vector_get(m->pairs, i);

		if (current_pair && current_pair->key)
		{
			if (current_pair->key == key)
			{
				return current_pair->value;
			}
		}
	}

	// Key not found
	return NULL;
}

void map_free(map* m)
{
	if (m)
	{
		free(m->pairs);
		free(m);
	}
}

void map_remove(map* m, void* key)
{
	for (size_t i = 0; i < m->size; i++)
	{
		if (((pair*)vector_get(m->pairs, i))->index == i)
		{
			vector_remove(m->pairs, i);
			m->pairs[i] = m->pairs[m->size - 1];
			m->size--;
		}
	}
}

//==============================================================================