#ifndef CORE_MAP_H
#define CORE_MAP_H
#include "vector.h"

__A_CORE_API__ typedef struct
{
	generic key;
	generic value;
} pair;

__A_CORE_API__ typedef struct
{
	u64 size;
	u64 capacity;
	struct_vec pairs;
} map;

__A_CORE_API__ __A_CORE_INLINE__ bool pair_compare(pair* a, generic key);

__A_CORE_API__ map*    map_new();
__A_CORE_API__ void    map_insert(map* map, generic key, generic value);
__A_CORE_API__ void    map_remove(map* map, generic key);
__A_CORE_API__ generic map_get(map* map, generic key);


#endif