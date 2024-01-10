#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include "../std_include.h"

#include "../memory/alloc.h"

// ===============================================================================
// VECTOR:       | Can store any type in the same vector as another type 
// ===============================================================================

typedef struct 
{ 
	uint64_t size; 
	uint64_t capacity; 
	ubyte** data; 
} _vector;

#define vector(_type) _vector*

// ===============================================================================
// VECTOR FUNCTIONS:

__A_CORE_API__ vector(void*) vector_default(void);
__A_CORE_API__ vector(void*) _vector_new(uint64_t size, void* values[]);
__A_CORE_API__ ubyte*		   vector_get(vector(void*) v, uint64_t index);
//                             Just frees the vector, not the data inside
__A_CORE_API__ void			   vector_free(vector(void*) v);
//                             Will free all the data inside the vector as well, requires a function pointer to be called to free the data
__A_CORE_API__ void            vector_free_all(vector(void*) v, void (*fn)(void*));
__A_CORE_API__ void            vector_push(vector(void*) v, void* data);
__A_CORE_API__ void            vector_insert(vector(void*) v, uint64_t index, void* data);
__A_CORE_API__ void			   vector_pop(vector(void*) v);
__A_CORE_API__ void            vector_remove(vector(void*) v, uint64_t index);
__A_CORE_API__ void            vector_clear(vector(void*) v);
__A_CORE_API__ void            vector_reverse(vector(void*) v);
__A_CORE_API__ void            vector_add_capacity(vector(void*) v, uint64_t size);
__A_CORE_API__ void            vector_add_vector(vector(void*) v, vector(void*) other);
__A_CORE_API__ void            _vector_add_array(vector(void*) v, uint64_t size, void* array[]);
__A_CORE_API__ void            vector_remove_slice(vector(void*) v, uint64_t index, uint64_t amount);
__A_CORE_API__ void            vector_move_data(vector(void*) v, vector(void*) other);
__A_CORE_API__ void            vector_change_data(vector(void*) v, vector(void*) other);
__A_CORE_API__ void			   vector_assign_data(vector(void*) v, void* data, uint64_t index);
__A_CORE_API__ __A_CORE_INLINE__ static bool vector_is_big_enough(vector(void*) v);


// helper macros to make calling vector functions easier
#define vector_new(_arr)   _vector_new((sizeof(_arr) / sizeof(_arr[0])), (_arr))
#define vector_add_array(_v, _arr) _vector_add_array(_v, sizeof(_arr) / sizeof(_arr[0]), _arr)

//===============================================================================

#endif // CORE_VECTOR_H