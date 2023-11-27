#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <glew.h>
#include <glfw3.h>

#include "renderer.hpp"
#include "camera.hpp"
#include "../world/voxel.hpp"
#include "../world/voxel_manager.hpp"
#include "../player/player.hpp"

namespace arcnum_core
{
	class window
	{
	public:
		window();
		~window();
		void init_gl();
		void update(voxel_manager* entities, player* player, std::vector<world_position> voxel_positions);
		bool is_running();
		void handle_input(camera* player_camera);
	public:
		renderer* _renderer;
	private:
		bool _running = true;
		GLFWwindow* _window;
		camera* _camera;
	};


	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void calculate_framerate();
}

#endif