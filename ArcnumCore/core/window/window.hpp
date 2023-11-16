#ifndef CORE_WINDOW_HPP
#define CORE_WINDOW_HPP

#include <SDL.h>
#undef main
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>


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
		void window_event();
		void update();
		void render();
	private:
		bool _running = true;
		GLuint _VBO = 0;
		GLuint _IBO = 0;
		GLuint _gl_program = 0;
		SDL_Window* _sdl_window;
		SDL_GLContext _gl_context;
	};
}

#endif