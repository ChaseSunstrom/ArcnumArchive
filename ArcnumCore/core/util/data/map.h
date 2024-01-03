#ifndef CORE_MAP_H
#define CORE_MAP_H
#include "vector.h"



// ==============================================================================
// PAIER:        | Used to store a pair of values.
// ==============================================================================

__A_CORE_API__ typedef struct
{
	generic key;
	generic value;
} pair;



// ==============================================================================
// MAP:        | Used to store a collection of key-value pairs.
// ==============================================================================

__A_CORE_API__ typedef struct
{
	u64 size;
	u64 capacity;
	vector(pair) pairs;
} _map;

#define map(_type1, _type2) _map*

// ==============================================================================
// MAP FUNCITONS:

__A_CORE_API__ __A_CORE_INLINE__ bool pair_compare(pair* a, generic key);

__A_CORE_API__ map(generic, generic)    map_new();
__A_CORE_API__ void    map_insert(map(generic, generic) map, generic key, generic value);
__A_CORE_API__ void    map_remove(map(generic, generic) map, generic key);
__A_CORE_API__ generic map_get(map(generic, generic) map, generic key);

// ==============================================================================

#endif