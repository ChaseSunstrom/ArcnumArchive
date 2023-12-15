#ifndef CORE_VECTOR_H
#define CORE_VECTOR_H

#include "../std_include.h"

#include "../memory/alloc.h"

// ===============================================================================
// VECTOR:       | Can store any type in the same vector as another type 
// ===============================================================================
AC_CORE_API typedef struct
{
	u64 size;
	u64 capacity;
	byte** data;
} vector;

// ===============================================================================
// VECTOR TYPES: | Used to hint at the data inside the vector.
//				 | it is up to the user to cast the data to the correct type

AC_CORE_API typedef vector* bool_vec;
AC_CORE_API typedef vector* int8_vec;
AC_CORE_API typedef vector* int16_vec;
AC_CORE_API  typedef vector* int32_vec;
AC_CORE_API typedef vector* int64_vec;
AC_CORE_API typedef vector* uint8_vec;
AC_CORE_API typedef vector* uint16_vec;
AC_CORE_API typedef vector* uint32_vec;
AC_CORE_API typedef vector* uint64_vec;
AC_CORE_API typedef vector* float32_vec;
AC_CORE_API typedef vector* float64_vec;
AC_CORE_API typedef vector* string_vec;
AC_CORE_API typedef vector* struct_vec;
AC_CORE_API typedef vector* enum_vec;
AC_CORE_API typedef vector* function_ptr_vec;

// ===============================================================================



// ===============================================================================
// VECTOR FUNCTIONS:

AC_CORE_API vector*     vector_new(void);
AC_CORE_API byte*       vector_get(vector* v, u64 index);
AC_CORE_API void        vector_free(vector* v);
AC_CORE_API void        vector_push(vector* v, T data);
AC_CORE_API void        vector_insert(vector* v, u64 index, T data);
AC_CORE_API void        vector_pop(vector* v);
AC_CORE_API void        vector_remove(vector* v, u64 index);
AC_CORE_API void        vector_clear(vector* v);
AC_CORE_API void        vector_reverse(vector* v);
AC_CORE_API static bool vector_is_big_enough(vector* v);

//===============================================================================

#endif // CORE_VECTOR_H