#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <glew.h>
#include <glfw3.h>

namespace arc_core
{
	class window
	{
	public:
		window();
		~window();
		void init_window();
		void init_gl();
		void attach_gl_context();
		void update();
		void render();
	private:
		bool _running = true;
		GLuint _VBO = 0;
		GLuint _VAO = 0;
		GLuint _EBO = 0;
		GLuint _gl_program = 0;
		GLFWwindow* _sdl_window;
	};


	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void error_callback(int id, const char* description);
}

#endif