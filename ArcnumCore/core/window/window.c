#include "window.h"

// ==============================================================================
// WINDOW FUNCTIONS:

GLFWwindow* window_init_gl(void)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* gl_window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arcnum", NULL, NULL);

	glfwMakeContextCurrent(gl_window);
	glfwSetFramebufferSizeCallback(gl_window, framebuffer_size_callback);
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glEnable(GL_DEPTH_TEST);

	glewInit();

	return gl_window;
}

window* window_new(void)
{
	window* _window   = ALLOC(window);
	_window->window   = window_init_gl();
	_window->renderer = renderer_new();
	return _window;
}

void window_update(window* window)
{
	renderer_render(window->renderer);

	glfwSwapBuffers(window->window);
	glfwPollEvents();
}

bool window_is_running(window* window)
{
	return !glfwWindowShouldClose(window->window);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// ==============================================================================