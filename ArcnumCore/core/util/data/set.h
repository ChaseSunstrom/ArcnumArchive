#ifndef CORE_SET_H
#define CORE_SET_H

#include "vector.h"

// =================================================================
// SET: | A vector that holds unique data types
// =================================================================

__A_CORE_API__ typedef struct
{
	uint64_t size;
	uint64_t capacity;
	vector(void*) data;
} _set;

#define set(_type) _set*



// =================================================================
// SET FUNCTIONS:

__A_CORE_API__ set(_type) set_default();
__A_CORE_API__ void		  set_insert(set(void*) set, uint64_t index, void* data);
__A_CORE_API__ void		  set_push(set(void*) set, void* data);
__A_CORE_API__ void	      set_remove(set(void*) set, uint64_t index);
__A_CORE_API__ void*      set_get(set(void*) set, uint64_t index);
__A_CORE_API__ void       set_free_d(set(void*) set);

// =================================================================

#endif // CORE_SET_H