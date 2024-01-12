#ifndef CORE_LAYER_H
#define CORE_LAYER_H

#include "../ecs/ecs.h"
#include "../window/window.h"
#include "renderer.h"

// ==============================================================================
// LAYER:        | Used for organizing related data in the layer stack and application
// ==============================================================================

__A_CORE_API__ typedef struct layer
{
	void (*layer_on_update_fn)(struct layer* layer);
	void (*layer_on_attach_fn)(struct layer* layer);
	void (*layer_on_detach_fn)(struct layer* layer);
	void (*layer_on_event_fn)(struct layer* layer);
	void (*layer_free_fn)(struct layer* layer);
} layer;

__A_CORE_API__ typedef struct renderer_layer
{
	renderer* renderer;

	void (*layer_on_update_fn)(struct renderer_layer* layer);
	void (*layer_on_attach_fn)(struct renderer_layer* layer);
	void (*layer_on_detach_fn)(struct renderer_layer* layer);
	void (*layer_on_event_fn)(struct renderer_layer* layer);
	void (*layer_free_fn)(struct renderer_layer* layer);
} renderer_layer;

__A_CORE_API__ typedef struct window_layer
{
	window* window;

	void (*layer_on_update_fn)(struct window_layer* layer);
	void (*layer_on_attach_fn)(struct window_layer* layer);
	void (*layer_on_detach_fn)(struct window_layer* layer);
	void (*layer_on_event_fn)(struct window_layer* layer);
	void (*layer_free_fn)(struct window_layer* layer);
} window_layer;

__A_CORE_API__ typedef struct ecs_layer
{
	ecs* ecs;

	void (*layer_on_update_fn)(struct ecs_layer* layer);
	void (*layer_on_attach_fn)(struct ecs_layer* layer);
	void (*layer_on_detach_fn)(struct ecs_layer* layer);
	void (*layer_on_event_fn)(struct ecs_layer* layer);
	void (*layer_free_fn)(struct ecs_layer* layer);
} ecs_layer;

typedef layer input_layer;

// ==============================================================================
// LAYER FUNCTIONS:

__A_CORE_API__ renderer_layer* renderer_layer_default();
__A_CORE_API__ void			   renderer_layer_on_attach(renderer_layer* layer);
__A_CORE_API__ void			   renderer_layer_on_detach(renderer_layer* layer);
__A_CORE_API__ void			   renderer_layer_on_update(renderer_layer* layer);
__A_CORE_API__ void			   renderer_layer_on_event(renderer_layer* layer);
__A_CORE_API__ void			   renderer_layer_free(renderer_layer* layer);

__A_CORE_API__ window_layer*   window_layer_default();
__A_CORE_API__ window_layer*   window_layer_new(c_str title, bool vsync, uint32_t height, uint32_t width);
__A_CORE_API__ void			   window_layer_on_attach(window_layer* layer);
__A_CORE_API__ void			   window_layer_on_detach(window_layer* layer);
__A_CORE_API__ void			   window_layer_on_update(window_layer* layer);
__A_CORE_API__ void			   window_layer_on_event(window_layer* layer);
__A_CORE_API__ void			   window_layer_free(window_layer* layer);

__A_CORE_API__ ecs_layer*      ecs_layer_default();
__A_CORE_API__ void		       ecs_layer_on_attach(ecs_layer* layer);
__A_CORE_API__ void		       ecs_layer_on_detach(ecs_layer* layer);
__A_CORE_API__ void		       ecs_layer_on_update(ecs_layer* layer);
__A_CORE_API__ void		       ecs_layer_on_event(ecs_layer* layer);
__A_CORE_API__ void		       ecs_layer_free(ecs_layer* layer);

__A_CORE_API__ input_layer*    input_layer_default();
__A_CORE_API__ void		       input_layer_on_attach(input_layer* layer);
__A_CORE_API__ void			   input_layer_on_detach(input_layer* layer);
__A_CORE_API__ void			   input_layer_on_update(input_layer* layer);
__A_CORE_API__ void			   input_layer_on_event(input_layer* layer);
__A_CORE_API__ void			   input_layer_free(input_layer* layer);

// ==============================================================================

#endif //CORE_LAYER_H