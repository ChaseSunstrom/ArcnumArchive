#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include "../util/std_include.h"

#include "../renderer/renderer.h"
#include "../events/event.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080

typedef void (*event_callback)(generic_event*);

// ==============================================================================
// WINDOW:       | Used for storing window information
// ==============================================================================

typedef struct 
{
	const char* title;
	bool        vsync;
	uint32_t    width;
	uint32_t    height;

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

GLFWwindow* window_init_gl(window_data window_data);
window*     window_new(void);
void        window_free(window* window);
void        window_on_update(window window);
void        window_vsync(bool vsync);
void        window_on_event(window window, generic_event* event);
bool        window_is_running(window window);
bool        window_close_event(window window);

// ==============================================================================



// ==============================================================================
// EVENT CALLBACKS:

void window_event_callback(generic_event* event);
void window_resized_event_callback(GLFWwindow* window, uint32_t width, uint32_t height);
void window_close_event_callback(GLFWwindow* window);
void window_key_event_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void window_mouse_button_event_callback(GLFWwindow* window, int button, int action, int mods);
void window_mouse_scroll_event_callback(GLFWwindow* window, double xoffset, double yoffset);
void window_mouse_move_event_callback(GLFWwindow* window, double x, double y);

// ==============================================================================

// ==============================================================================
// GLFW CALLBACKS:

void        glfw_error_callback(int error, const char* description);
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// ==============================================================================

#endif // CORE_WINDOW_H