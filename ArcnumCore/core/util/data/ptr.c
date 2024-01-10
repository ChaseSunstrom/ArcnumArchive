#include "ptr.h"

__A_CORE_API__ handled_ptr(void*) handled_ptr_default()
{
	handled_ptr(void*) handled;
	handled.ptr = NULL;
	handled.ptr_size = 0;
	return handled;
}

__A_CORE_API__ handled_ptr(void*) handled_ptr_new(void* ptr)
{
	handled_ptr(void*) handled;
	handled.ptr = ptr;
	handled.ptr_size = sizeof(ptr);
	return handled;
}

__A_CORE_API__ void handled_ptr_set_ptr(handled_ptr(void*)* handled, void* ptr)
{
	handled->ptr = ptr;
	handled->ptr_size = sizeof(ptr);
}

__A_CORE_API__ optional_ptr(void*) optional_ptr_default()
{
	optional_ptr(void*) optional;
	optional.ptr = NULL;
	optional.ptr_size = 0;
	optional.state = NONE;
	return optional;
}

__A_CORE_API__ optional_ptr(void*) optional_ptr_new(void* ptr)
{
	optional_ptr(void*) optional;
	optional.ptr = ptr;

	if (ptr)
		optional.state = SOME;

	else
		optional.state = NONE;

	optional.ptr_size = sizeof(ptr);
}

__A_CORE_API__ void optional_ptr_set_ptr(optional_ptr(void*)* optional, void* ptr)
{
	optional->ptr = ptr;

	if (ptr)
		optional->state = SOME;

	else
		optional->state = NONE;

	optional->ptr_size = sizeof(ptr);
}

__A_CORE_API__ void* handled_ptr_deref(handled_ptr(void*)* handled)
{
	if (handled->ptr)
		return handled->ptr;

	return NULL;
}

__A_CORE_API__ __A_CORE_INLINE__ bool optional_ptr_is_some(optional_ptr(void*)* optional)
{
	return optional->state == SOME;
}

__A_CORE_API__ void* optional_ptr_deref(optional_ptr(void*)* optional)
{
	if (optional_ptr_is_some(optional) && optional->ptr)
	{
		// Just in case the state is off
		optional->state = SOME;
		return optional->ptr;
	}

	optional->state = NONE;
	return NONE;
}

__A_CORE_API__ void* optional_ptr_deref_or(optional_ptr(void*)* optional, void* (*fn)(), ...)
{
	if (optional_ptr_is_some(optional) && optional->ptr)
		return optional->ptr;

	va_list args;
	va_start(args, fn);
	void* result = fn(args);
	va_end(args);

	return result;
}