#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "../util/std_include.h"
#include "../util/memory/bump_allocator.h"

#include "../renderer/renderer.h"
#include "../events/event.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080

__A_CORE_API__ typedef generic_event* (*event_callback)(generic_event*);

// ==============================================================================
// WINDOW:       | Used for storing window information
// ==============================================================================

__A_CORE_API__ typedef struct
{
	string title;
	bool   vsync;
	u32    width;
	u32    height;

	// A function that gets called every event
	event_callback event_callback;
} window_data;

__A_CORE_API__ typedef struct
{
	GLFWwindow* window;
	renderer*   renderer;
	bool        running;
	window_data window_data;
} window;



// ==============================================================================
// WINDOW FUNCTIONS:

__A_CORE_API__ GLFWwindow*    window_init_gl(window_data* window_data);
__A_CORE_API__ window*        window_new(void);
__A_CORE_API__ window*		  _window_new(bump_allocator* allocator);
__A_CORE_API__ generic_event* window_propagate_event(generic_event* event);
__A_CORE_API__ void		      window_free(window* window);
__A_CORE_API__ void           window_on_update(window* window);
__A_CORE_API__ void           window_vsync(bool vsync);
__A_CORE_API__ void           window_on_event(window* window, generic_event* event);
__A_CORE_API__ bool           window_is_running(window* window);
__A_CORE_API__ bool           window_close_event(window* window);

// ==============================================================================



// ==============================================================================
// EVENT CALLBACKS:

__A_CORE_API__ void window_event_callback(generic_event* event);
__A_CORE_API__ void window_resized_event_callback(GLFWwindow* window, u32 width, u32 height);
__A_CORE_API__ void window_close_event_callback(GLFWwindow* window);
__A_CORE_API__ void window_key_event_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);
__A_CORE_API__ void window_mouse_button_event_callback(GLFWwindow* window, i32 button, i32 action, i32 mods);
__A_CORE_API__ void window_mouse_scroll_event_callback(GLFWwindow* window, f64 xoffset, f64 yoffset);
__A_CORE_API__ void window_mouse_move_event_callback(GLFWwindow* window, f64 x, f64 y);

// ==============================================================================

// ==============================================================================
// GLFW CALLBACKS:

__A_CORE_API__ void        glfw_error_callback(i32 error, string description);
__A_CORE_API__ static void framebuffer_size_callback(GLFWwindow* window, i32 width, i32 height);

// ==============================================================================

#endif // CORE_WINDOW_H