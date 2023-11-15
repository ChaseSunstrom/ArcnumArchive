#include <iostream>

#include <Windows.h>
#include "glfw3.h"
#include "SDL.h"
#undef main
#include "SDL_opengl.h"

#include "window.hpp"


namespace arc_core
{
	window::window()
	{

		if (SDL_Init(SDL_INIT_VIDEO) < 0) 
		{
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			exit(-1);
		}
		// Open Window
		SDL_Window* window = SDL_CreateWindow("OpenGL Test", 0, 0, 640, 480, SDL_WINDOW_OPENGL);
		
		if (!window) 
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			exit(-1);
		}
		// OpenGL attributes
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		// Create OpenGL context
		SDL_GLContext Context = SDL_GL_CreateContext(window);

		bool running = true;
		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						running = false;
						break;
						// Other input here
					default:
						break;
					}
				}
				else if (event.type == SDL_QUIT)
				{
					running = 0;
				}
			}

			glViewport(0, 0, 640, 480);
			glClearColor(1.f, 0.f, 1.f, 0.f);
			glClear(GL_COLOR_BUFFER_BIT);

			// OpenGL rendering goes here

			SDL_GL_SwapWindow(window);
		}
		SDL_Quit();
	}
}