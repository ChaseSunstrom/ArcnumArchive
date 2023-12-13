#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#include <stdbool.h>

#define BIT_SHIFT(x) (1 << x)

// ===============================================================
// EVENT FACTORY: | Used to easily create an event
// ===============================================================
#define EVENT_FACTORY(_name, ...)	typedef  struct           \
									{                         \
										bool handled;         \
										__VA_ARGS__;          \
									} _name                   \



// ===============================================================
// EVENT TYPES: | Used to store the type of event
// ===============================================================
enum event_type
{
	NO_TYPE,
	APP_UPDATE,
	APP_TICK,
	APP_RENDER,
	WINDOW_CLOSED,
	WINDOW_RESIZED,
	WINDOW_MOVED,
	KEY_PRESSED,
	KEY_RELEASED,
	KEY_REPEAT,
	MOUSE_PRESSED,
	MOUSE_RELEASED,
	MOUSE_MOVED,
	MOUSE_SCROLLED,
} ;



// ===============================================================
// EVENT CATEGORIES: | Used to store the category of event
// ===============================================================
enum event_category
{ 
	NO_CATEGORY  = 0,
	INPUT        = BIT_SHIFT(1),
	KEYBOARD     = BIT_SHIFT(2),
	MOUSE        = BIT_SHIFT(3),
	MOUSE_BUTTON = BIT_SHIFT(4),
	APPLICATION  = BIT_SHIFT(5),
};



// ===============================================================
// EVENT STRUCTS: | Used to hold event data related to their type

EVENT_FACTORY(generic_event,  enum event_type type);
EVENT_FACTORY(app_update_event, enum event_type type);
EVENT_FACTORY(app_tick_event, enum event_type type);
EVENT_FACTORY(app_render_event, enum event_type type);
EVENT_FACTORY(window_closed_event, enum event_type type);
EVENT_FACTORY(window_resized_event, enum event_type type; int width; int height );
EVENT_FACTORY(window_moved_event, enum event_type type; int x_pos; int y_pos  );
EVENT_FACTORY(key_pressed_event, enum event_type type; int key_code );
EVENT_FACTORY(key_released_event, enum event_type type; int key_code );
EVENT_FACTORY(key_repeat_event, enum event_type type; int key_code);
EVENT_FACTORY(mouse_pressed_event, enum event_type type; int button  );
EVENT_FACTORY(mouse_released_event, enum event_type type; int button );
EVENT_FACTORY(mouse_move_event, enum event_type type; double x_pos; double y_pos );
EVENT_FACTORY(mouse_scroll_event, enum event_type type;  double x_offset; double y_offset);

// ===============================================================



// ===============================================================
// EVENT DISPATCHER: | Used to dispatch and handle events
// ===============================================================
typedef struct
{
	generic_event* event;
} event_dispatcher;



// ===============================================================
// EVENT RELATED METHODS:

bool        event_dispatcher_dispatch(event_dispatcher dispatcher, void* function_to_call);
const char* event_type_to_string(enum event_type event_type);

// ===============================================================
// EVENT FUNCTION_PTR: | Used as a function pointer to call any event
//                     | function
// ===============================================================
#define EVENT_FUNCTION_PTR( _name, _function) bool(*_name)(generic_event*) = _function

// ===============================================================

#endif // CORE_EVENT_H