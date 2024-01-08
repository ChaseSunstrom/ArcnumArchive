#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

#include "../util/memory/bump_allocator.h"
#include "../util/data/vector.h"
#include "../ecs/ecs.h"
#include "batcher.h"



// ==============================================================================
// RENDERER:     | Used for rendering and storing rendering data
// ==============================================================================

__A_CORE_API__ typedef struct
{
	float64_t delta_time;
	float64_t fixed_delta_time;
	float64_t last_frame_time;
	float64_t tick_time;

	batcher* batcher;

	ecs* ecs;
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
__A_CORE_API__ float64_t       calculate_tick_time(void);
__A_CORE_API__ float64_t       calculate_delta_time(void);
__A_CORE_API__ float64_t       calculate_fixed_delta_time(void);
__A_CORE_API__ float64_t       calculate_last_frame_time(void);

//===============================================================================

#endif //CORE_RENDERER_H