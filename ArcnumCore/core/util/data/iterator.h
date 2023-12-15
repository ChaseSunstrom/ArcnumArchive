#ifndef CORE_ITERATOR_H
#define CORE_ITERATOR_H

#include "../std_include.h"

// ===============================================================================
// ITERATOR_STATE: | Used to store the state of an iterator
// ===============================================================================
AC_CORE_API typedef enum
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
AC_CORE_API typedef struct
{
	iterator_state state;
	T* collection;
	T* collection_data;
	u64 index;
	u64 collection_size;
} iterator;



// ===============================================================================
// ITERATOR FUNCTIONS:

AC_CORE_API iterator*      iterator_new(T* collection);
AC_CORE_API iterator_state iterator_next(iterator* it);
AC_CORE_API iterator_state iterator_prev(iterator* it);
AC_CORE_API iterator_state iterator_iterate(iterator* it);
AC_CORE_API iterator_state iterator_b_iterate(iterator* it);
AC_CORE_API iterator_state iterator_begin(iterator* it);
AC_CORE_API iterator_state iterator_end(iterator* it);
AC_CORE_API T			   iterator_get_prev(iterator* it);
AC_CORE_API T		       iterator_get_next(iterator* it);
AC_CORE_API T	           iterator_get_current_data(iterator* it);
AC_CORE_API void           iterator_reset(iterator* it);
AC_CORE_API void           iterator_update(iterator* it, T* collection);
AC_CORE_API void           iterator_free(iterator* it);

//===============================================================================

#endif // CORE_ITERATOR_H