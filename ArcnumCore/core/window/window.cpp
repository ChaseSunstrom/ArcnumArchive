#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "window.hpp"
#include "entity.hpp"

#define SCR_WIDTH 800
#define SCR_HEIGHT 800

namespace arc_core
{
	window::window()
	{
		this->init_gl();
		this->_renderer = new renderer();
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
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glewInit();
	}

	void window::update(std::vector<entity*> entity)
	{
		for (auto e : entity)
		{
			e->render();
		}
		glfwPollEvents();
		glfwSwapBuffers(this->_window);
	}

	bool window::is_running()
	{
		return !glfwWindowShouldClose(this->_window);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}