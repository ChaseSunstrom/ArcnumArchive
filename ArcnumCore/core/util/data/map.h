#ifndef CORE_MAP_H
#define CORE_MAP_H
#include "vector.h"



// ==============================================================================
// PAIER:        | Used to store a pair of values.
// ==============================================================================

__A_CORE_API__ typedef struct
{
	void* key;
	void* value;
} pair;



// ==============================================================================
// MAP:        | Used to store a collection of key-value pairs.
// ==============================================================================

__A_CORE_API__ typedef struct
{
	uint64_t size;
	uint64_t capacity;
	vector(pair) pairs;
} _map;

#define map(_type1, _type2) _map*

// ==============================================================================
// MAP FUNCITONS:

__A_CORE_API__ __A_CORE_INLINE__ bool pair_compare(pair* a, void* key);

__A_CORE_API__ map(void*, void*) map_new();
__A_CORE_API__ void				 map_insert(map(void*, void*) map, void* key, void* value);
__A_CORE_API__ void			     map_remove(map(void*, void*) map, void* key);
__A_CORE_API__ void*			 map_get(map(void*, void*) map, void* key);

// ==============================================================================

#endif