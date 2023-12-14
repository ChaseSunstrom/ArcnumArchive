#ifndef CORE_ITERATOR_H
#define CORE_ITERATOR_H

#include "../std_include.h"

// ===============================================================================
// ITERATOR_STATE: | Used to store the state of an iterator
// ===============================================================================
typedef enum
{
	ITERATOR_BEGIN,
	ITERATOR_NEXT,
	ITERATOR_PREV,
	ITERATOR_ITERATING,
	ITERATOR_END,

	// Used as a placeholder
	ITERATOR_NONE,
} iterator_state;



// ===============================================================================
// ITERATOR:      | Used to iterate through a list
// ===============================================================================
typedef struct
{
	iterator_state state;
	T* collection;
	T* collection_data;
	u64 index;
	u64 collection_size;
} iterator;



// ===============================================================================
// ITERATOR FUNCTIONS:

iterator*      iterator_new(T* collection);
iterator_state iterator_next(iterator* it);
iterator_state iterator_prev(iterator* it);
iterator_state iterator_iterate(iterator* it);
iterator_state iterator_b_iterate(iterator* it);
iterator_state iterator_begin(iterator* it);
iterator_state iterator_end(iterator* it);
T			   iterator_get_prev(iterator* it);
T		       iterator_get_next(iterator* it);
T	           iterator_get_current_data(iterator* it);
void           iterator_reset(iterator* it);
void           iterator_update(iterator* it, T* collection);
void           iterator_free(iterator* it);

//===============================================================================

#endif // CORE_ITERATOR_H