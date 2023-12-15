#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "../util/std_include.h"

#include "../renderer/renderer.h"
#include "../events/event.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080

AC_CORE_API typedef generic_event* (*event_callback)(generic_event*);

// ==============================================================================
// WINDOW:       | Used for storing window information
// ==============================================================================

AC_CORE_API typedef struct
{
	string title;
	bool   vsync;
	u32    width;
	u32    height;

	// A function that gets called every event
	event_callback event_callback;
} window_data;

AC_CORE_API typedef struct
{
	GLFWwindow* window;
	renderer*   renderer;
	bool        running;
	window_data window_data;
} window;



// ==============================================================================
// WINDOW FUNCTIONS:

AC_CORE_API GLFWwindow*    window_init_gl(window_data window_data);
AC_CORE_API window*        window_new(void);
AC_CORE_API generic_event* window_propagate_event(generic_event* event);
AC_CORE_API void		   window_free(window* window);
AC_CORE_API void           window_on_update(window window);
AC_CORE_API void           window_vsync(bool vsync);
AC_CORE_API void           window_on_event(window window, generic_event* event);
AC_CORE_API bool           window_is_running(window window);
AC_CORE_API bool           window_close_event(window window);

// ==============================================================================



// ==============================================================================
// EVENT CALLBACKS:

AC_CORE_API void window_event_callback(generic_event* event);
AC_CORE_API void window_resized_event_callback(GLFWwindow* window, u32 width, u32 height);
AC_CORE_API void window_close_event_callback(GLFWwindow* window);
AC_CORE_API void window_key_event_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);
AC_CORE_API void window_mouse_button_event_callback(GLFWwindow* window, i32 button, i32 action, i32 mods);
AC_CORE_API void window_mouse_scroll_event_callback(GLFWwindow* window, f64 xoffset, f64 yoffset);
AC_CORE_API void window_mouse_move_event_callback(GLFWwindow* window, f64 x, f64 y);

// ==============================================================================

// ==============================================================================
// GLFW CALLBACKS:

AC_CORE_API void        glfw_error_callback(i32 error, string description);
AC_CORE_API static void framebuffer_size_callback(GLFWwindow* window, i32 width, i32 height);

// ==============================================================================

#endif // CORE_WINDOW_H