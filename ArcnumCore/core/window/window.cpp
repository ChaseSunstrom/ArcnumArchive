#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "window.hpp"

#define SCR_WIDTH 800
#define SCR_HEIGHT 800

namespace arc_core
{
	window::window()
	{
        this->init_gl();
	}

	window::~window()
	{
		glfwTerminate();
	}

    void window::init_gl()
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        this->_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);

        glfwMakeContextCurrent(this->_window);
        glfwSetFramebufferSizeCallback(this->_window, framebuffer_size_callback);
        glewInit();
    }

	void window::update()
	{
        this->_renderer = new renderer();

        while (!glfwWindowShouldClose(this->_window))
        {
			this->_renderer->render();
            glfwPollEvents();
            glfwSwapBuffers(this->_window);
        }

        glfwTerminate();
	}

    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}