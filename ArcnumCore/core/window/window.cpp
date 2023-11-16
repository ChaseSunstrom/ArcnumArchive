#include <iostream>

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

#include "window.hpp"


namespace arc_core
{
	window::window()
	{
		this->init_window();
	}

	window::~window()
	{
		SDL_Quit();
	}

	void window::init_window()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			exit(-1);
		}
		this->_sdl_window = SDL_CreateWindow("OpenGL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

		if (!this->_sdl_window)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			exit(-1);
		}

		this->attach_gl_context();
	}

	void window::attach_gl_context()
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		this->_gl_context = SDL_GL_CreateContext(this->_sdl_window);
		
		glewExperimental = GL_TRUE;

		this->init_gl();
	}

	void window::window_event()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					_running = false;
					break;
					// Other input here
				default:
					break;
				}
			}
			else if (event.type == SDL_QUIT)
			{
				_running = 0;
			}
		}
	}

	void window::update()
	{
		while (this->_running)
		{
			this->window_event();

			this->render();

			SDL_GL_SwapWindow(this->_sdl_window);
		}
	}

	void window::render()
	{
		GLint vertex_pos = glGetAttribLocation(this->_gl_program, "LVertexPos2D");
		glUseProgram(this->_gl_program);
		glEnableVertexAttribArray(vertex_pos);
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);
		glVertexAttribPointer(vertex_pos, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);
		glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL);

		glDisableVertexAttribArray(vertex_pos);
		glUseProgram(NULL);
	}

	void window::init_gl()
	{
		this->_gl_program = glCreateProgram();
		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* vertex_shader_source[] =
		{
			"#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }"
		};

		glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
		glCompileShader(vertex_shader);

		glAttachShader(this->_gl_program, vertex_shader);

		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

		const GLchar* fragment_shader_source[] =
		{
			"#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
		};

		glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
		glCompileShader(fragment_shader);

		glAttachShader(this->_gl_program, fragment_shader);
		glLinkProgram(this->_gl_program);

		glClearColor(0.f, 0.f, 0.f, 1.f);

		GLfloat vertex_data[] =
		{
			-0.5f, -0.5f,
			 0.5f, -0.5f,
			 0.5f,  0.5f,
			-0.5f,  0.5f
		};
		GLuint index_data[] = { 0, 1, 2, 3 };

		glGenBuffers(1, &_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, _VBO);
		glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), vertex_data, GL_STATIC_DRAW);

		glGenBuffers(1, &_IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), index_data, GL_STATIC_DRAW);
	}
}