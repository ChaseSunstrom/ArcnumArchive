#include "../util/std_include.h"

#include "../util/memory/alloc.h"
#include "renderer.h"

// ==============================================================================
// RENDERER FUNCTIONS:

renderer* renderer_new()
{
	renderer* _renderer         = ALLOC(renderer);
	_renderer->last_frame_time  = 0;
	_renderer->delta_time       = 0;
	_renderer->fixed_delta_time = 0.01f;
	_renderer->tick_time        = 0;
	return _renderer;
}

void renderer_render(renderer* renderer)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	renderer_set_delta_time(renderer);
}

void renderer_set_delta_time(renderer* renderer)
{
	f64 current_time = glfwGetTime();
	renderer->delta_time = current_time - renderer->last_frame_time;
	renderer->last_frame_time = current_time;
}

// ==============================================================================