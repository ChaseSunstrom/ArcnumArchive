#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <stdint.h>

#include <glew.h>
#include <glfw3.h>

#include "../renderer/renderer.h"

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080

// ==============================================================================
// WINDOW:       | Used for storing window information
// ==============================================================================
typedef struct
{
	GLFWwindow* window;
	renderer*   renderer;
	bool        running;
	uint32_t    width;
	uint32_t    height;
} window;



// ==============================================================================
// WINDOW FUNCTIONS:

GLFWwindow* window_init_gl(void );
window*     window_new(void);
void        window_free(window* window);
void        window_update(window* window);
bool        window_is_running(window* window);
void        framebuffer_size_callback(GLFWwindow* window, int width, int height);

// ==============================================================================

#endif // CORE_WINDOW_H