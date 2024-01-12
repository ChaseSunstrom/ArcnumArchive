#include "../util/memory/alloc.h"
#include "layer.h"

__A_CORE_API__ renderer_layer* renderer_layer_default()
{
	renderer_layer* _layer = ALLOC(renderer_layer);
	_layer->renderer = renderer_new();
	_layer->layer_on_update_fn = renderer_layer_on_update;
	_layer->layer_on_attach_fn = renderer_layer_on_attach;
	_layer->layer_on_detach_fn = renderer_layer_on_detach;
	_layer->layer_on_event_fn = renderer_layer_on_event;
	_layer->layer_free_fn = renderer_layer_free;
	return _layer;
}

__A_CORE_API__ window_layer* window_layer_default()
{
	window_layer* _layer = ALLOC(window_layer);
	_layer->window = window_default();
	_layer->layer_on_update_fn = window_layer_on_update;
	_layer->layer_on_attach_fn = window_layer_on_attach;
	_layer->layer_on_detach_fn = window_layer_on_detach;
	_layer->layer_on_event_fn = window_layer_on_event;
	_layer->layer_free_fn = window_layer_free;
	return _layer;
}

__A_CORE_API__ window_layer* window_layer_new(c_str title, bool vsync, uint32_t height, uint32_t width)
{
	window_layer* _layer = ALLOC(window_layer);
	_layer->window = window_new(title, vsync, height, width);
	_layer->layer_on_update_fn = window_layer_on_update;
	_layer->layer_on_attach_fn = window_layer_on_attach;
	_layer->layer_on_detach_fn = window_layer_on_detach;
	_layer->layer_on_event_fn = window_layer_on_event;
	_layer->layer_free_fn = window_layer_free;
	return _layer;
}

__A_CORE_API__ ecs_layer* ecs_layer_default()
{
	ecs_layer* _layer = ALLOC(ecs_layer);
	_layer->ecs = ecs_default();
	_layer->layer_on_update_fn = ecs_layer_on_update;
	_layer->layer_on_attach_fn = ecs_layer_on_attach;
	_layer->layer_on_detach_fn = ecs_layer_on_detach;
	_layer->layer_on_event_fn = ecs_layer_on_event;
	_layer->layer_free_fn = ecs_layer_free;
	return _layer;
}

__A_CORE_API__ input_layer* input_layer_default()
{
	input_layer* _layer = ALLOC(input_layer);
	_layer->layer_on_update_fn = input_layer_on_update;
	_layer->layer_on_attach_fn = input_layer_on_attach;
	_layer->layer_on_detach_fn = input_layer_on_detach;
	_layer->layer_on_event_fn = input_layer_on_event;
	_layer->layer_free_fn = input_layer_free;
	return _layer;
}

__A_CORE_API__ void renderer_layer_on_attach(renderer_layer* layer)
{

}

__A_CORE_API__ void renderer_layer_on_detach(renderer_layer* layer)
{
}

__A_CORE_API__ void renderer_layer_on_update(renderer_layer* layer)
{
	renderer_render(layer->renderer);
}

__A_CORE_API__ void renderer_layer_on_event(renderer_layer* layer)
{
}

__A_CORE_API__ void renderer_layer_free(renderer_layer* layer)
{
	renderer_free(layer->renderer);
	free(layer);
}

__A_CORE_API__ void window_layer_on_attach(window_layer* layer)
{
}

__A_CORE_API__ void window_layer_on_detach(window_layer* layer)
{
}

__A_CORE_API__ void window_layer_on_update(window_layer* layer)
{
	window_on_update(layer->window);
}

__A_CORE_API__ void window_layer_on_event(window_layer* layer)
{
}

__A_CORE_API__ void window_layer_free(window_layer* layer)
{
	window_free(layer->window);
	free(layer);
}

__A_CORE_API__ void ecs_layer_on_attach(ecs_layer* layer)
{
}

__A_CORE_API__ void ecs_layer_on_detach(ecs_layer* layer)
{
}

__A_CORE_API__ void ecs_layer_on_update(ecs_layer* layer)
{
}

__A_CORE_API__ void ecs_layer_on_event(ecs_layer* layer)
{
}

__A_CORE_API__ void ecs_layer_free(ecs_layer* layer)
{
	ecs_free(layer->ecs);
	free(layer);
}

__A_CORE_API__ void input_layer_on_attach(input_layer* layer)
{
}

__A_CORE_API__ void input_layer_on_detach(input_layer* layer)
{
}

__A_CORE_API__ void input_layer_on_update(input_layer* layer)
{
}

__A_CORE_API__ void input_layer_on_event(input_layer* layer)
{
}

__A_CORE_API__ void input_layer_free(input_layer* layer)
{
	free(layer);
}