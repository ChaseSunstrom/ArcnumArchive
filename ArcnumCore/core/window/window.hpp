#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <glew.h>
#include <glfw3.h>

#include "renderer.hpp"

namespace arc_core
{
	class window
	{
	public:
		window();
		~window();
		void init_gl();
		void update();
	private:
		bool _running = true;
		renderer* _renderer;
		GLFWwindow* _window;
	};


	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void error_callback(int id, const char* description);
}

#endif