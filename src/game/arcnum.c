
#include "arcnum.h"

// ===============================================================================
// GAME FUNCTIONS:

void application_main(void)
{
	const application _app =
	{
		.window = *window_new(),
		.layer_stack = *layer_stack_new(),
	};

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

void application_on_event(generic_event* event)
{
	switch (event->type)
	{
	case WINDOW_RESIZED:
		ARCNUM_CORE_LOG("[EVENT]: WINDOW RESIZED {X: %d, Y: %d}\n", ((window_resized_event*)event)->width, ((window_resized_event*)event)->height);
		break;
	case MOUSE_MOVED:
		ARCNUM_CORE_LOG("[EVENT]: MOUSE POSITION {X: %f, Y: %f}\n", ((mouse_move_event*)event)->x_pos, ((mouse_move_event*)event)->y_pos);
		break;
	case MOUSE_SCROLLED:
		ARCNUM_CORE_LOG("[EVENT]: MOUSE SCROLLED \n", );
		break;
	case KEY_PRESSED:
		ARCNUM_CORE_LOG("[EVENT]: KEY PRESSED {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
		break;
	case KEY_RELEASED:
		ARCNUM_CORE_LOG("[EVENT]: KEY RELEASED {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
		break;
	case KEY_REPEAT:
		ARCNUM_CORE_LOG("[EVENT]: KEY HELD {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
		break;
	case MOUSE_PRESSED:
		ARCNUM_CORE_LOG("[EVENT]: MOUSE BUTTON PRESSED {KEYCODE: %d}\n", ((mouse_pressed_event*)event)->button);
		break;
	case MOUSE_RELEASED:
		ARCNUM_CORE_LOG("[EVENT]: MOUSE BUTTON RELEASED {KEYCODE: %d}\n", ((mouse_pressed_event*)event)->button);
		break;
	}
}

void application_loop(const application app)
{

	layer* _layer = layer_new();
	application_push_layer(app, _layer);


	subscription* subscription = subscription_new(EVENT_TOPIC, application_on_event);

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