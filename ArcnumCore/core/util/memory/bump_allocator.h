#ifndef CORE_BUMP_ALLOCATOR_H
#define CORE_BUMP_ALLOCATOR_H

#include "alloc.h"

#include "../std_include.h"

#define KILOBYTE 1024
#define MEGABYTE 1048576
#define GIGABYTE 1073741824



// ===============================================================
// BUMP ALLOCATOR:   | Used to allocate memory like an arena
// ===============================================================
__A_CORE_API__ typedef struct
{
	// size in bytes
	uint64_t   size;

	ubyte* start;
	ubyte* end;
	ubyte* current;
} bump_allocator;



// ===============================================================
// BUMP ALLOCATOR FUNCTIONS:

__A_CORE_API__ bump_allocator* bump_allocator_default(void);
__A_CORE_API__ bump_allocator* bump_allocator_new(uint64_t size);
__A_CORE_API__ void*         bump_allocator_alloc(bump_allocator* allocator, uint64_t size);
__A_CORE_API__ void            bump_allocator_free(bump_allocator* allocator);
__A_CORE_API__ void            bump_allocator_reset(bump_allocator* allocator);

// ===============================================================

#endif // CORE_BUMP_ALLOCATOR_H