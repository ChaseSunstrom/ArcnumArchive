#include <iostream>
#include <chrono>

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "window.hpp"
#include "../world/entity.hpp"

#define SCR_WIDTH 1080
#define SCR_HEIGHT 1080

namespace arcnum_core
{
	double delta_time = 0.0;
	double last_frame = 0.0;

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
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Arcnum", NULL, NULL);

		glfwMakeContextCurrent(this->_window);
		glfwSetFramebufferSizeCallback(this->_window, framebuffer_size_callback);
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glEnable(GL_DEPTH_TEST);

		glewInit();
	}

	void window::update(entity_manager* entities, camera* player_camera)
	{
		handle_input(player_camera);

		entities->render(player_camera);

		calculate_framerate();

		glfwSwapBuffers(this->_window);
		glfwPollEvents();
	}

	bool window::is_running()
	{
		return !glfwWindowShouldClose(this->_window);
	}

	void window::handle_input(camera* player_camera)
	{
		player_camera->_camera_speed = 2.5 * delta_time;

		if (glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(this->_window, true);
		if (glfwGetKey(this->_window, GLFW_KEY_W) == GLFW_PRESS)
			player_camera->camera_up();
		if (glfwGetKey(this->_window, GLFW_KEY_S) == GLFW_PRESS)
			player_camera->camera_down();
		if (glfwGetKey(this->_window, GLFW_KEY_A) == GLFW_PRESS)
			player_camera->camera_left();
		if (glfwGetKey(this->_window, GLFW_KEY_D) == GLFW_PRESS)
			player_camera->camera_right();
	}

	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void calculate_framerate()
	{
		double current_time = glfwGetTime();
		delta_time = current_time - last_frame;
		last_frame = current_time;
		std::cout << "FPS: " << (1 / delta_time) << std::endl;
	}
}