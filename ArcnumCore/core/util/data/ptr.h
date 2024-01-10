#ifndef CORE_PTR_H
#define CORE_PTR_H

#include "../std_include.h"

// =================================================================
// OPTIONAL STATE: | Used to store the sate of the data inside the optional
//                 | ptr
// =================================================================

__A_CORE_API__ typedef enum
{
	NONE = 0,
	SOME
} optional_state;



// =================================================================
// OPTIONAL PTR: | A safer stack pointer
// =================================================================

__A_CORE_API__ typedef struct
{
	optional_state state;
	// Pointer size in bytes
	uint64_t ptr_size;
	void* ptr;
} _optional_ptr;



// =================================================================
// HANDLED PTR: | A stack pointer
// =================================================================

__A_CORE_API__ typedef struct
{
	// Pointer size in bytes
	uint64_t ptr_size;
	void* ptr;
} _handled_ptr;

#define handled_ptr(_type) _handled_ptr
#define optional_ptr(_type) _optional_ptr



// =================================================================
// HANDLED PTR FUNCTIONS:

__A_CORE_API__ handled_ptr(void*) handled_ptr_default();
__A_CORE_API__ handled_ptr(void*) handled_ptr_new(void* ptr);
__A_CORE_API__ void               handled_ptr_set_ptr(handled_ptr(void*)* handled, void* ptr);
__A_CORE_API__ void*              handled_ptr_deref(handled_ptr(void*)* handled);

// =================================================================



// =================================================================
// OPTIONAL PTR FUNCTIONS:

__A_CORE_API__ optional_ptr(void*)    optional_ptr_default();
__A_CORE_API__ optional_ptr(void*)    optional_ptr_new(void* ptr);
__A_CORE_API__ void                   optional_ptr_set_ptr(optional_ptr(void*)* optional, void* ptr);
__A_CORE_API__ void*			      optional_ptr_deref(optional_ptr(void*)* optional);
//                                    Takes in a function pointer for a function to call if the optional is NONE
__A_CORE_API__ void*                  optional_ptr_deref_or(optional_ptr(void*)* optional, void* (*fn)(), ...);
__A_CORE_API__ __A_CORE_INLINE__ bool optional_ptr_is_some(optional_ptr(void*)* optional);

// =================================================================

#endif