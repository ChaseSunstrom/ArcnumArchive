#include "../util/std_include.h"

#include "../util/memory/alloc.h"
#include "renderer.h"

// ==============================================================================
// RENDERER FUNCTIONS:

__A_CORE_API__ renderer* renderer_new()
{
	renderer* _renderer         = ALLOC(renderer);
	_renderer->last_frame_time  = 0;
	_renderer->delta_time       = 0;
	_renderer->fixed_delta_time = 0.01f;
	_renderer->tick_time        = 0;
	_renderer->batcher          = batcher_default();
	return _renderer;
}

__A_CORE_API__ renderer* _renderer_new(bump_allocator* allocator)
{
	renderer* _renderer         = bump_allocator_alloc(allocator, sizeof(renderer));
	_renderer->last_frame_time  = 0;
	_renderer->delta_time       = 0;
	_renderer->fixed_delta_time = 0.01f;
	_renderer->tick_time        = 0;
	_renderer->batcher          = batcher_default();
	return _renderer;
}

__A_CORE_API__ void renderer_render(renderer* renderer)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	batcher_render(renderer->batcher);

	renderer_set_delta_time(renderer);
}

__A_CORE_API__ void renderer_set_delta_time(renderer* renderer)
{
	float64_t current_time = glfwGetTime();
	renderer->delta_time = current_time - renderer->last_frame_time;
	renderer->last_frame_time = current_time;
}

__A_CORE_API__ void renderer_free(renderer* renderer)
{
	batcher_free(renderer->batcher);
	free(renderer);
}

// ==============================================================================