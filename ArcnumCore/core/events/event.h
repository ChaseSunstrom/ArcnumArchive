#ifndef CORE_EVENT_H
#define CORE_EVENT_H

#include "../util/std_include.h"

// ===============================================================
// EVENT TYPES: | Used to store the type of event
// ===============================================================
__A_CORE_API__ enum event_type
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
};



// ===============================================================
// EVENT FACTORY: | Used to easily create an event
// ===============================================================
#define EVENT_FACTORY(_name, ...)	typedef  struct           \
									{                         \
										bool handled;	      \
										enum event_type type; \
										__VA_ARGS__           \
									} _name                   \



// ===============================================================
// EVENT STRUCTS: | Used to hold event data related to their type

__A_CORE_API__ EVENT_FACTORY(generic_event);
__A_CORE_API__ EVENT_FACTORY(app_update_event);
__A_CORE_API__ EVENT_FACTORY(app_tick_event);
__A_CORE_API__ EVENT_FACTORY(app_render_event);
__A_CORE_API__ EVENT_FACTORY(window_closed_event);
__A_CORE_API__ EVENT_FACTORY(window_resized_event, i32 width; i32 height;);
__A_CORE_API__ EVENT_FACTORY(window_moved_event, i32 x_pos; i32 y_pos;);
__A_CORE_API__ EVENT_FACTORY(key_pressed_event, i32 key_code; );
__A_CORE_API__ EVENT_FACTORY(key_released_event, i32 key_code; );
__A_CORE_API__ EVENT_FACTORY(key_repeat_event, i32 key_code;);
__A_CORE_API__ EVENT_FACTORY(mouse_pressed_event, i32 button;);
__A_CORE_API__ EVENT_FACTORY(mouse_released_event, i32 button;);
__A_CORE_API__ EVENT_FACTORY(mouse_move_event, f64 x_pos; f64 y_pos;);
__A_CORE_API__ EVENT_FACTORY(mouse_scroll_event, f64 x_offset; f64 y_offset;);

// ===============================================================



// ===============================================================
// EVENT DISPATCHER: | Used to dispatch and handle events
// ===============================================================
__A_CORE_API__ typedef struct
{
	generic_event* event;
} event_dispatcher;



// ===============================================================
// EVENT RELATED METHODS:

__A_CORE_API__ bool        event_dispatcher_dispatch(event_dispatcher dispatcher, generic function_to_call);
__A_CORE_API__ c_str event_type_to_string(enum event_type event_type);

// ===============================================================
// EVENT FUNCTION_PTR: | Used as a function pointer to call any event
//                     | function
// ===============================================================
#define EVENT_FUNCTION_PTR( _name, _function) bool(*(_name))(generic_event*) = _function

// ===============================================================

#endif // CORE_EVENT_H