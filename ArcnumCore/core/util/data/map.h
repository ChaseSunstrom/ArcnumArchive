#ifndef CORE_MAP_H
#define CORE_MAP_H
#include "vector.h"

__A_CORE_API__ typedef struct
{
	T key;
	T value;
} pair;

__A_CORE_API__ typedef struct
{
	u64 size;
	u64 capacity;
	struct_vec pairs;
} map;

__A_CORE_API__ bool  pair_compare(pair* a, T key);

__A_CORE_API__ map*  map_new();
__A_CORE_API__ void  map_insert(map* map, T key, T value);
__A_CORE_API__ void  map_remove(map* map, T key);
__A_CORE_API__ T     map_get(map* map, T key);


#endif