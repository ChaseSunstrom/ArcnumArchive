
#include "arcnum.h"

// ===============================================================================
// GAME FUNCTIONS:

void application_main(void)
{
	application _app =
	{
		.allocator = bump_allocator_new(KILOBYTE)
	};

	_app.window      = *_window_new(_app.allocator);
	_app.layer_stack = *_layer_stack_new(_app.allocator);

	application_loop(_app);
}

void application_push_layer(const application app, layer* layer)
{
	layer_stack_push_layer(app.layer_stack, layer);
}

void application_push_overlay(const application app, layer* layer)
{
	layer_stack_push_overlay(app.layer_stack, layer);
}

bool application_print_event(generic_event* event)
{
	switch (event->type)
	{
	case WINDOW_RESIZED:
		ARCNUM_CORE_LOG("[EVENT]: WINDOW RESIZED {X: %d, Y: %d}\n", ((window_resized_event*)event)->width, ((window_resized_event*)event)->height);
		return true;
	case MOUSE_MOVED:
		ARCNUM_CORE_LOG("[EVENT]: MOUSE POSITION {X: %f, Y: %f}\n", ((mouse_move_event*)event)->x_pos, ((mouse_move_event*)event)->y_pos);
		return true;
	case MOUSE_SCROLLED:
		printf("[EVENT]: MOUSE SCROLLED \n");
		return true;
	case KEY_PRESSED:
		ARCNUM_CORE_LOG("[EVENT]: KEY PRESSED {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
		return true;
	case KEY_RELEASED:
		ARCNUM_CORE_LOG("[EVENT]: KEY RELEASED {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
		return true;
	case KEY_REPEAT:
		ARCNUM_CORE_LOG("[EVENT]: KEY HELD {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
		return true;
	case MOUSE_PRESSED:
		ARCNUM_CORE_LOG("[EVENT]: MOUSE BUTTON PRESSED {KEYCODE: %d}\n", ((mouse_pressed_event*)event)->button);
		return true;
	case MOUSE_RELEASED:
		ARCNUM_CORE_LOG("[EVENT]: MOUSE BUTTON RELEASED {KEYCODE: %d}\n", ((mouse_pressed_event*)event)->button);
		return true;
	}
	return false;
}

void application_on_event(generic_event* event)
{
	event_dispatcher dispatcher = { .event = event };

	event_dispatcher_dispatch(dispatcher, application_print_event, event);
}

void application_loop(const application app)
{
	layer* _layer = layer_new();
	application_push_layer(app, _layer);

	subscription_new(WINDOW_EVENT_TOPIC, application_on_event);

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