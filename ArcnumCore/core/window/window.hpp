#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <glew.h>
#include <glfw3.h>

#include "camera.hpp"
#include "renderer.hpp"
#include "../entity/entity.hpp"
#include "../entity/ecs.hpp"
#include "../player/player.hpp"

namespace arcnum_core
{
	class window
	{
	public:
		window();
		~window();
		void init_gl();
		void update();
		bool is_running();
		void handle_input(camera* player_camera);
		void calculate_delta_time();
	public:
		renderer* _renderer;
	private:
		bool _running = true;
		GLFWwindow* _window;
	};


	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}

#endif