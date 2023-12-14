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
} vector;

// ===============================================================================
// VECTOR TYPES: | Used to hint at the data inside the vector.
//				 | it is up to the user to cast the data to the correct type

typedef vector* bool_vec;
typedef vector* int8_vec;
typedef vector* int16_vec;
typedef vector* int32_vec;
typedef vector* int64_vec;
typedef vector* uint8_vec;
typedef vector* uint16_vec;
typedef vector* uint32_vec;
typedef vector* uint64_vec;
typedef vector* float32_vec;
typedef vector* float64_vec;
typedef vector* string_vec;
typedef vector* struct_vec;
typedef vector* enum_vec;
typedef vector* function_ptr_vec;

// ===============================================================================



// ===============================================================================
// VECTOR FUNCTIONS:

vector*     vector_new(void);
byte*       vector_get(vector* v, u64 index);
void        vector_free(vector* v);
void        vector_push(vector* v, T data);
void        vector_insert(vector* v, u64 index, T data);
void        vector_pop(vector* v);
void        vector_remove(vector* v, u64 index);
void        vector_clear(vector* v);
void        vector_reverse(vector* v);
static bool vector_is_big_enough(vector* v);

//===============================================================================

#endif // CORE_VECTOR_H