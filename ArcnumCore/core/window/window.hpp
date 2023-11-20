#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <glew.h>
#include <glfw3.h>

#include "renderer.hpp"
#include "entity.hpp"

namespace arc_core
{
	class window
	{
	public:
		window();
		~window();
		void init_gl();
		void update(entities* entities);
		bool is_running();
	public:
		renderer* _renderer;
	private:
		bool _running = true;
		GLFWwindow* _window;
	};


	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void calculate_framerate();
}

#endif