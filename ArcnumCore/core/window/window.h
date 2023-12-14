#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "../util/std_include.h"

#include "../renderer/renderer.h"
#include "../events/event.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080

typedef generic_event* (*event_callback)(generic_event*);

// ==============================================================================
// WINDOW:       | Used for storing window information
// ==============================================================================

typedef struct 
{
	string title;
	bool   vsync;
	u32    width;
	u32    height;

	// A function that gets called every event
	event_callback event_callback;
} window_data;

typedef struct
{
	GLFWwindow* window;
	renderer*   renderer;
	bool        running;
	window_data window_data;
} window;



// ==============================================================================
// WINDOW FUNCTIONS:

GLFWwindow*    window_init_gl(window_data window_data);
window*        window_new(void);
generic_event* window_propagate_event(generic_event* event);
void		   window_free(window* window);
void           window_on_update(window window);
void           window_vsync(bool vsync);
void           window_on_event(window window, generic_event* event);
bool           window_is_running(window window);
bool           window_close_event(window window);

// ==============================================================================



// ==============================================================================
// EVENT CALLBACKS:

void window_event_callback(generic_event* event);
void window_resized_event_callback(GLFWwindow* window, u32 width, u32 height);
void window_close_event_callback(GLFWwindow* window);
void window_key_event_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);
void window_mouse_button_event_callback(GLFWwindow* window, i32 button, i32 action, i32 mods);
void window_mouse_scroll_event_callback(GLFWwindow* window, f64 xoffset, f64 yoffset);
void window_mouse_move_event_callback(GLFWwindow* window, f64 x, f64 y);

// ==============================================================================

// ==============================================================================
// GLFW CALLBACKS:

void        glfw_error_callback(i32 error, string description);
static void framebuffer_size_callback(GLFWwindow* window, i32 width, i32 height);

// ==============================================================================

#endif // CORE_WINDOW_H