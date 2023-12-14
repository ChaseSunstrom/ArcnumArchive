#include "../util/std_include.h"
#include "../util/memory/alloc.h"
#include "../events/sub.h"

#include "window.h"

#include "../util/log.h"
 

// ==============================================================================
// WINDOW FUNCTIONS:

GLFWwindow* window_init_gl(window_data window_data)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* gl_window = glfwCreateWindow(window_data.width, window_data.height, window_data.title, NULL, NULL);

	glfwMakeContextCurrent(gl_window);
	glfwSetFramebufferSizeCallback(gl_window, framebuffer_size_callback);
	glfwSetErrorCallback(glfw_error_callback);
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glfwSetWindowUserPointer(gl_window, &window_data);
	glEnable(GL_DEPTH_TEST);

	glewInit();

	window_vsync(window_data.vsync);

	//glfw callbacks
	glfwSetWindowSizeCallback(gl_window, window_resized_event_callback);
	glfwSetWindowCloseCallback(gl_window, window_close_event_callback);
	glfwSetKeyCallback(gl_window, window_key_event_callback);
	glfwSetMouseButtonCallback(gl_window, window_mouse_button_event_callback);
	glfwSetCursorPosCallback(gl_window, window_mouse_move_event_callback);
	glfwSetScrollCallback(gl_window, window_mouse_scroll_event_callback);

	return gl_window;
}

window* window_new(void)
{
	window* _window = ALLOC(window);
	_window->renderer = renderer_new();
	_window->running = true;
	_window->window_data.title = "Arcnum";
	_window->window_data.vsync = false;
	_window->window_data.width = SCREEN_WIDTH;
	_window->window_data.height = SCREEN_HEIGHT;
	_window->window_data.event_callback = window_on_event;
	_window->window = window_init_gl(_window->window_data);
	return _window;
}

void window_on_update(window window)
{
	renderer_render(window.renderer);

	glfwSwapBuffers(window.window);
	glfwPollEvents();
}

bool window_is_running(window window)
{
	return !glfwWindowShouldClose(window.window);
}

bool window_close_event(window window)
{
	window.running = false;
	return true;
}

void window_vsync(bool vsync)
{
	if (vsync)
	{
		glfwSwapInterval(1);
	}
	else
	{
		glfwSwapInterval(0);
	}
}

void window_on_event(generic_event* event)
{
	publish(WINDOW_EVENT_TOPIC, event);
}

generic_event* window_propagate_event(generic_event* event) { return event; }

// ==============================================================================



// ==============================================================================
// EVENT CALLBACKS:

void window_resized_event_callback(GLFWwindow* window, u32 width, u32 height)
{
	window_data* _window_data = (window_data*)glfwGetWindowUserPointer(window);
	window_resized_event event = { .width = width, .height = height, .type = WINDOW_RESIZED };

	_window_data->width = width;
	_window_data->height = height;

	_window_data->event_callback(&event);
}

void window_close_event_callback(GLFWwindow* window)
{
	window_data* _window_data = (window_data*)glfwGetWindowUserPointer(window);
	window_closed_event event = {.type = WINDOW_CLOSED};

	_window_data->event_callback(&event);
}

void window_key_event_callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods)
{
	window_data* _window_data = (window_data*)glfwGetWindowUserPointer(window);

	switch (action)
	{
		case GLFW_PRESS:
		{
			key_pressed_event event = { .key_code = key, .type = KEY_PRESSED };
			_window_data->event_callback(&event);
			break;
		}
		case GLFW_RELEASE:
		{
			key_released_event event = { .key_code = key, .type = KEY_RELEASED };
			_window_data->event_callback(&event);
			break;
		}
		case GLFW_REPEAT:
		{
			key_repeat_event event = { .key_code = key, .type = KEY_REPEAT };
			_window_data->event_callback(&event);
			break;
		}
	}
}

void window_mouse_button_event_callback(GLFWwindow* window, i32 button, i32 action, i32 mods)
{
	window_data* _window_data = (window_data*)glfwGetWindowUserPointer(window);

	switch (action)
	{
		case GLFW_PRESS:
		{
			mouse_pressed_event event = { .button = button, .type = MOUSE_PRESSED };
			_window_data->event_callback(&event);
			break;
		}
		case GLFW_RELEASE:
		{
			mouse_released_event event = { .button = button, .type = MOUSE_RELEASED };
			_window_data->event_callback(&event);
			break;
		}
	}
}

void window_mouse_scroll_event_callback(GLFWwindow* window, f64 xoffset, f64 yoffset)
{
	window_data* _window_data = (window_data*)glfwGetWindowUserPointer(window);

	mouse_scroll_event event = { .x_offset = xoffset, .y_offset = yoffset, .type = MOUSE_SCROLLED };
	_window_data->event_callback(&event);
}

void window_mouse_move_event_callback(GLFWwindow* window, f64 xpos, f64 ypos)
{
	window_data* _window_data = (window_data*)glfwGetWindowUserPointer(window);
	mouse_move_event event = { .x_pos = xpos, .y_pos = ypos, .type = MOUSE_MOVED };
	_window_data->event_callback(&event);
}

// ==============================================================================



// ==============================================================================
// GLFW CALLBACKS:

void glfw_error_callback(i32 error, string description)
{
	ARCNUM_CORE_LOG("GLFW ERROR: %s\n", description);
}

static void framebuffer_size_callback(GLFWwindow* window, i32 width, i32 height)
{
	glViewport(0, 0, width, height);
}

// ==============================================================================