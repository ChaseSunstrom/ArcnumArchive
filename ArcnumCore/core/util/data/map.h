#ifndef CORE_MAP_H
#define CORE_MAP_H

#include "vector.h"

//===============================================================================
// PAIR:         |Used to store a key and a value
//===============================================================================
typedef struct
{
	size_t index;
	void* key;
	void* value;
} pair;

//===============================================================================
// MAP:          | Stores a list of key-value pairs
//===============================================================================
typedef struct
{
	size_t size;
	size_t capacity;
	struct_vec pairs;
} map;

//===============================================================================
// MAP FUNCTIONS:

map*  map_new(void);
void  map_insert(map* m, void* key, void* value);
void* map_find(map* m, void* key);
void  map_remove(map* m, void* key);
void  map_free(map* m);

//===============================================================================


//===============================================================================
// MAP ALIAS FUNCTIONS:

#define map_put(m, k, v) map_insert(m, k, v)
#define map_get(m, k)    map_find(m, k)

//===============================================================================

#endif //CORE_MAP_H