#pragma once

#include "terminate.h"

#include <glfw3.h>

void game_terminate(GLFWwindow* main_window)
{
	glfwDestroyWindow(main_window);
	glfwTerminate();
}