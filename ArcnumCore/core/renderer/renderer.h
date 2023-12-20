#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

#include "../util/memory/bump_allocator.h"
#include "../util/data/vector.h"

// ==============================================================================
// RENDERER:     | Used for rendering and storing rendering data
// ==============================================================================
__A_CORE_API__ typedef struct
{
	f64 delta_time;
	f64 fixed_delta_time;
	f64 last_frame_time;
	f64 tick_time;

	// These are for batch rendering, all entity data that can be batch rendered will be
	// stored here
	GLuint VAO;
	GLuint VBO;

	struct_vec entities;
} renderer;

//===============================================================================
// RENDERER FUNCTIONS:     

__A_CORE_API__ renderer* renderer_new(void);
__A_CORE_API__ renderer* _renderer_new(bump_allocator* allocator);
__A_CORE_API__ void      renderer_free(renderer* renderer);
__A_CORE_API__ void      renderer_render(renderer* renderer);
__A_CORE_API__ void      renderer_set_tick_time(renderer* renderer);
__A_CORE_API__ void      renderer_set_delta_time(renderer* renderer);
__A_CORE_API__ void      renderer_set_fixed_delta_time(renderer* renderer);
__A_CORE_API__ void      renderer_set_last_frame_time(renderer* renderer);
__A_CORE_API__ double    calculate_tick_time(void);
__A_CORE_API__ double    calculate_delta_time(void);
__A_CORE_API__ double    calculate_fixed_delta_time(void);
__A_CORE_API__ double    calculate_last_frame_time(void);

//===============================================================================
#endif //CORE_RENDERER_H