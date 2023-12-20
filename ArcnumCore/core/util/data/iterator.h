#ifndef CORE_ITERATOR_H
#define CORE_ITERATOR_H

#include "../std_include.h"

// ===============================================================================
// ITERATOR_STATE: | Used to store the state of an iterator
// ===============================================================================
__A_CORE_API__ typedef enum
{
	// Used as a placeholder
	ITERATOR_NONE,

	ITERATOR_BEGIN,
	ITERATOR_NEXT,
	ITERATOR_PREV,
	ITERATOR_ITERATING,
	ITERATOR_END,
} iterator_state;



// ===============================================================================
// ITERATOR:      | Used to iterate through a list
// ===============================================================================
__A_CORE_API__ typedef struct
{
	iterator_state state;
	generic* collection_data;
	u64 index;
	u64 collection_size;
} iterator;



// ===============================================================================
// ITERATOR FUNCTIONS:

__A_CORE_API__ iterator*      iterator_new(generic* collection);
__A_CORE_API__ iterator_state iterator_next(iterator* it);
__A_CORE_API__ iterator_state iterator_prev(iterator* it);
__A_CORE_API__ iterator_state iterator_iterate(iterator* it);
__A_CORE_API__ iterator_state iterator_b_iterate(iterator* it);
__A_CORE_API__ iterator_state iterator_begin(iterator* it);
__A_CORE_API__ iterator_state iterator_end(iterator* it);
__A_CORE_API__ generic	      iterator_get_prev(iterator* it);
__A_CORE_API__ generic		  iterator_get_next(iterator* it);
__A_CORE_API__ generic	      iterator_get_current_data(iterator* it);
__A_CORE_API__ bool           iterator_has_next(iterator* it);
__A_CORE_API__ bool           iterator_has_prev(iterator* it);
__A_CORE_API__ void           iterator_reset(iterator* it);
__A_CORE_API__ void           iterator_update(iterator* it, generic* collection);
__A_CORE_API__ void           iterator_free(iterator* it);

//===============================================================================

#endif // CORE_ITERATOR_H