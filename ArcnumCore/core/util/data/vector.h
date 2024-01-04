#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include "../std_include.h"

#include "../memory/alloc.h"

// ===============================================================================
// VECTOR:       | Can store any type in the same vector as another type 
// ===============================================================================

typedef struct 
{ 
	u64 size; 
	u64 capacity; 
	byte** data; 
} _vector;

#define vector(_type) _vector*

// ===============================================================================
// VECTOR FUNCTIONS:

__A_CORE_API__ vector(generic) vector_default(void);
__A_CORE_API__ vector(generic) _vector_new(u64 size, generic values[]);
__A_CORE_API__ byte*		   vector_get(vector(generic) v, u64 index);
__A_CORE_API__ void			   vector_free(vector(generic) v);
__A_CORE_API__ void            vector_push(vector(generic) v, generic data);
__A_CORE_API__ void            vector_insert(vector(generic) v, u64 index, generic data);
__A_CORE_API__ void			   vector_pop(vector(generic) v);
__A_CORE_API__ void            vector_remove(vector(generic) v, u64 index);
__A_CORE_API__ void            vector_clear(vector(generic) v);
__A_CORE_API__ void            vector_reverse(vector(generic) v);
__A_CORE_API__ void            vector_add_capacity(vector(generic) v, u64 size);
__A_CORE_API__ void            vector_add_vector(vector(generic) v, vector(generic) other);
__A_CORE_API__ void            _vector_add_array(vector(generic) v, u64 size, generic array[]);
__A_CORE_API__ void            vector_remove_slice(vector(generic) v, u64 index, u64 amount);
__A_CORE_API__ void            vector_move_data(vector(generic) v, vector(generic) other);
__A_CORE_API__ void            vector_change_data(vector(generic) v, vector(generic) other);
__A_CORE_API__ __A_CORE_INLINE__ static bool vector_is_big_enough(vector(generic) v);


// helper macros to make calling vector functions easier
#define vector_new(_arr)   _vector_new(sizeof(_arr) / sizeof(_arr[0]), _arr)
#define vector_add_array(_v, _arr) _vector_add_array(_v, sizeof(_arr) / sizeof(_arr[0]), _arr)

//===============================================================================

#endif // CORE_VECTOR_H