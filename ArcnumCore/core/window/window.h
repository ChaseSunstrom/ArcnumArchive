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
	c_str title;
	bool   vsync;
	uint32_t    width;
	uint32_t    height;

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
__A_CORE_API__ void window_resized_event_callback(GLFWwindow* window, uint32_t width, uint32_t height);
__A_CORE_API__ void window_close_event_callback(GLFWwindow* window);
__A_CORE_API__ void window_key_event_callback(GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mods);
__A_CORE_API__ void window_mouse_button_event_callback(GLFWwindow* window, int32_t button, int32_t action, int32_t mods);
__A_CORE_API__ void window_mouse_scroll_event_callback(GLFWwindow* window, float64_t xoffset, float64_t yoffset);
__A_CORE_API__ void window_mouse_move_event_callback(GLFWwindow* window, float64_t x, float64_t y);

// ==============================================================================

// ==============================================================================
// GLFW CALLBACKS:

__A_CORE_API__ void        glfw_error_callback(int32_t error, c_str description);
__A_CORE_API__ static void framebuffer_size_callback(GLFWwindow* window, int32_t width, int32_t height);

// ==============================================================================

#endif // CORE_WINDOW_H