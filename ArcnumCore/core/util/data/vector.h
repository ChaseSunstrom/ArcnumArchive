#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include "../std_include.h"

#include "../memory/alloc.h"

// ===============================================================================
// VECTOR:       | Can store any type in the same vector as another type 
// ===============================================================================
__A_CORE_API__ typedef struct
{
	u64 size;
	u64 capacity;
	byte** data;
} vector;

// ===============================================================================
// VECTOR TYPES: | Used to hint at the data inside the vector.
//				 | it is up to the user to cast the data to the correct type

__A_CORE_API__ typedef vector* bool_vec;
__A_CORE_API__ typedef vector* int8_vec;
__A_CORE_API__ typedef vector* int16_vec;
__A_CORE_API__  typedef vector* int32_vec;
__A_CORE_API__ typedef vector* int64_vec;
__A_CORE_API__ typedef vector* uint8_vec;
__A_CORE_API__ typedef vector* uint16_vec;
__A_CORE_API__ typedef vector* uint32_vec;
__A_CORE_API__ typedef vector* uint64_vec;
__A_CORE_API__ typedef vector* float32_vec;
__A_CORE_API__ typedef vector* float64_vec;
__A_CORE_API__ typedef vector* string_vec;
__A_CORE_API__ typedef vector* struct_vec;
__A_CORE_API__ typedef vector* enum_vec;
__A_CORE_API__ typedef vector* function_ptr_vec;

// ===============================================================================



// ===============================================================================
// VECTOR FUNCTIONS:

__A_CORE_API__ vector*     vector_new(void);
__A_CORE_API__ byte*       vector_get(vector* v, u64 index);
__A_CORE_API__ void        vector_free(vector* v);
__A_CORE_API__ void        vector_push(vector* v, T data);
__A_CORE_API__ void        vector_insert(vector* v, u64 index, T data);
__A_CORE_API__ void        vector_pop(vector* v);
__A_CORE_API__ void        vector_remove(vector* v, u64 index);
__A_CORE_API__ void        vector_clear(vector* v);
__A_CORE_API__ void        vector_reverse(vector* v);
__A_CORE_API__ static bool vector_is_big_enough(vector* v);

//===============================================================================

#endif // CORE_VECTOR_H