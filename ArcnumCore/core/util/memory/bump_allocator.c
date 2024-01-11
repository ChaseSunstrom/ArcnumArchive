#include "bump_allocator.h"

// ===============================================================
// BUMP ALLOCATOR FUNCTIONS:

// this will return a bump allocator with a default size of 1 MB
__A_CORE_API__ bump_allocator* bump_allocator_default(void)
{
	bump_allocator* allocator = ALLOC(bump_allocator);
	allocator->size = MEGABYTE;
	allocator->start = malloc(MEGABYTE);
	allocator->end = allocator->start + allocator->size;
	allocator->current = allocator->start;
	
	return allocator;
}

__A_CORE_API__ bump_allocator* bump_allocator_new(uint64_t size)
{
	bump_allocator* allocator = ALLOC(bump_allocator);
	allocator->size = size;
	allocator->start = malloc(size);
	allocator->end = allocator->start + allocator->size;
	allocator->current = allocator->start;

	return allocator;
}

__A_CORE_API__ void* bump_allocator_alloc(bump_allocator* allocator, uint64_t size)
{
	if (allocator->current + size > allocator->end)
		// Out of memory
		return NULL;

	void* allocation = allocator->current;
	allocator->current += size;
	return allocation;
}

__A_CORE_API__ void bump_allocator_free(bump_allocator* allocator)
{
	free(allocator->start);
	free(allocator);
}

__A_CORE_API__ void bump_allocator_reset(bump_allocator* allocator)
{
	allocator->current = allocator->start;
}

// ===============================================================