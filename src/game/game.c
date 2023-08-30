#pragma once

#include <glad.h>
#include <glfw3.h>

#include "terminate.h"

void game_main(GLFWwindow* main_window)
{
    while (!glfwWindowShouldClose(main_window))
    {
        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }

    game_terminate(main_window);
}