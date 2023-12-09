
#include "arcnum.h"

// ===============================================================================
// GAME FUNCTIONS:

void application_main(void)
{
	const application app =
	{
		.window = *window_new(),
		.layer_stack = *layer_stack_new(),
	};

	application_loop(app);
}

void application_push_layer(const application app, layer* layer)
{
	layer_stack_push_layer(app.layer_stack, layer);
}

void application_push_overlay(const application app, layer* layer)
{
	layer_stack_push_overlay(app.layer_stack, layer);
}

void application_on_event(const application app, generic_event* event)
{
	event_dispatcher dispatcher;
	dispatcher.event = event;

	window_closed_event _event;
	_event.handled = false;
	_event.type = WINDOW_CLOSED;

	event_dispatcher_dispatch(dispatcher, window_close_event, &_event);
}

void application_loop(const application app)
{

	layer* _layer = layer_new();
	application_push_layer(app, _layer);


	while (window_is_running(app.window))
	{
		while (iterator_b_iterate(app.layer_stack.layers_it) != ITERATOR_BEGIN)
		{
			layer* current_layer = iterator_get_current_data(app.layer_stack.layers_it);
			layer_on_update(current_layer);
		}

		iterator_reset(app.layer_stack.layers_it);

		window_on_update(app.window);
	}
}

// ============================================================================