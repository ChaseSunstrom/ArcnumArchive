#ifndef CORE_SET_H
#define CORE_SET_H

#include "vector.h"

__A_CORE_API__ typedef struct
{
	u64 size;
	u64 capacity;
	vector* data;
} set;

__A_CORE_API__ set* set_new();
__A_CORE_API__ void set_insert(set* set, u64 index, T data);
__A_CORE_API__ void set_push(set* set, T data);
__A_CORE_API__ void set_remove(set* set, u64 index);
__A_CORE_API__ T    set_get(set* set, u64 index);
__A_CORE_API__ void set_free(set* set);


#endif // CORE_SET_H