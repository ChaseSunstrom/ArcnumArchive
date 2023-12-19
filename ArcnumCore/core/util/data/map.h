#ifndef CORE_MAP_H
#define CORE_MAP_H
#include "vector.h"

typedef struct
{
	T key;
	T value;
} pair;

typedef struct
{
	struct_vec pairs;
} map;

bool  pair_compare(pair* a, T key);

map*  map_new();
void  map_insert(map* map, T key, T value);
void  map_remove(map* map, T key);
T     map_get(map* map, T key);


#endif