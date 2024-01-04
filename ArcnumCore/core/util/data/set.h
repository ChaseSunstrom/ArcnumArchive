#ifndef CORE_SET_H
#define CORE_SET_H

#include "vector.h"

__A_CORE_API__ typedef struct
{
	u64 size;
	u64 capacity;
	vector(generic) data;
} _set;

#define set(_type) _set*

__A_CORE_API__ set(_type)    set_default();
__A_CORE_API__ void    set_insert(set(generic) set, u64 index, generic data);
__A_CORE_API__ void    set_push(set(generic) set, generic data);
__A_CORE_API__ void	   set_remove(set(generic) set, u64 index);
__A_CORE_API__ generic set_get(set(generic) set, u64 index);
__A_CORE_API__ void    set_free(set(generic) set);


#endif // CORE_SET_H