#include <glew.h>
#include <glfw3.h>

#include "renderer.h"

// ==============================================================================
// RENDERER FUNCTIONS:

renderer* renderer_new()
{
	renderer* _renderer    = ALLOC(renderer);
	_renderer->layer_stack = layer_stack_new();
	return _renderer;
}

void renderer_render(renderer* renderer)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

// ==============================================================================