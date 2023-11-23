#include <iostream>
#include <chrono>

#include <glew.h>
#include <glfw3.h>

#include "window.hpp"
#include "../world/entity.hpp"

#define SCR_WIDTH 1080
#define SCR_HEIGHT 1080

namespace arcnum_core
{
	window::window()
	{
		this->init_gl();
		this->_renderer = new renderer();
		this->_camera = new camera();
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
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

		this->_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Arcnum", NULL, NULL);

		glfwMakeContextCurrent(this->_window);
		glfwSetFramebufferSizeCallback(this->_window, framebuffer_size_callback);
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glewInit();
	}

	void window::update(entities* entities)
	{
		handle_input();

		entities->render();

		//calculate_framerate();

		glfwSwapBuffers(this->_window);
		glfwPollEvents();
	}

	bool window::is_running()
	{
		return !glfwWindowShouldClose(this->_window);
	}

	void window::handle_input()
	{
		if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(this->_window, true);
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	double last_time = 0.0f;

	void calculate_framerate()
	{
		double current_time = glfwGetTime();
		double delta_time = current_time - last_time;
		last_time = current_time;
		std::cout << "FPS: " << (1 / delta_time) << std::endl;
	}
}