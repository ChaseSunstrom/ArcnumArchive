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
__A_CORE_API__ typedef vector* i8_vec;
__A_CORE_API__ typedef vector* i16_vec;
__A_CORE_API__ typedef vector* i32_vec;
__A_CORE_API__ typedef vector* i64_vec;
__A_CORE_API__ typedef vector* u8_vec;
__A_CORE_API__ typedef vector* u16_vec;
__A_CORE_API__ typedef vector* u32_vec;
__A_CORE_API__ typedef vector* u64_vec;
__A_CORE_API__ typedef vector* f32_vec;
__A_CORE_API__ typedef vector* f64_vec;
__A_CORE_API__ typedef vector* string_vec;
__A_CORE_API__ typedef vector* struct_vec;
__A_CORE_API__ typedef vector* enum_vec;
__A_CORE_API__ typedef vector* fn_ptr_vec;

// ===============================================================================



// ===============================================================================
// VECTOR FUNCTIONS:

__A_CORE_API__ vector*     vector_default(void);
__A_CORE_API__ vector*     _vector_new(u64 size, generic values[]);
__A_CORE_API__ byte*       vector_get(vector* v, u64 index);
__A_CORE_API__ void        vector_free(vector* v);
__A_CORE_API__ void        vector_push(vector* v, generic data);
__A_CORE_API__ void        vector_insert(vector* v, u64 index, generic data);
__A_CORE_API__ void        vector_pop(vector* v);
__A_CORE_API__ void        vector_remove(vector* v, u64 index);
__A_CORE_API__ void        vector_clear(vector* v);
__A_CORE_API__ void        vector_reverse(vector* v);
__A_CORE_API__ void        vector_add_capacity(vector* v, u64 size);
__A_CORE_API__ void        vector_add_vector(vector* v, vector* other);
__A_CORE_API__ void        _vector_add_array(vector* v, u64 size, generic array[]);
__A_CORE_API__ void        vector_remove_slice(vector* v, u64 index, u64 amount);
__A_CORE_API__ __A_CORE_INLINE__ static bool vector_is_big_enough(vector* v);


// helper macros to make calling vector functions easier
#define vector_new(_arr)   _vector_new(sizeof(_arr) / sizeof(_arr[0]), _arr)
#define vector_add_array(_v, _arr) _vector_add_array(_v, sizeof(_arr) / sizeof(_arr[0]), _arr)

//===============================================================================

#endif // CORE_VECTOR_H