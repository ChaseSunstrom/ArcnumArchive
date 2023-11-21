
#include <vector>

#include <filesystem>

#include <core/window/window.hpp>
#include <core/world/entity.hpp>
#include <core/world/geometry.hpp>
#include "arcnum.hpp"

#define TOP_RIGHT 0.5f,  0.5f, 0.0f
#define BOTTOM_RIGHT 0.5f, -0.5f, 0.0f
#define BOTTOM_LEFT -0.5f, -0.5f, 0.0f
#define TOP_LEFT -0.5f,  0.5f, 0.0f

#define WORLD_POS_X 0
#define WORLD_POS_Y 0
#define WORLD_POS_Z 0

namespace arcnum_main 
{
	arcnum::arcnum()
	{
		this->_main_window = new arcnum_core::window();
		this->_main_entities = new arcnum_core::entities();
	}

	arcnum::~arcnum()
	{
		this->_main_entities->~entities();
		this->_main_window->~window();
	}

	void arcnum::arcnum_main()
	{
		std::vector<float> vertices = {
			TOP_RIGHT,
			BOTTOM_RIGHT,
			BOTTOM_LEFT,
		};

		std::vector<float> vertices2 = {
			TOP_RIGHT,
			BOTTOM_LEFT,
			TOP_LEFT,
		};

		for (int i = 0; i < 100; i++)
		{
			srand((unsigned)time(0));

			// Get a random number
			float random_x = rand() / 10000;
			float random_y = rand() / 10000;
			float random_z = rand() / 10000;

			arcnum_core::triangle* triangle1 = new arcnum_core::triangle(vertices, new float[3] {random_x*2/i, random_y*2/i, random_z*2/i});
			arcnum_core::entity* entity = new arcnum_core::entity(&this->_main_window->_renderer->_shader_program, "shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl", triangle1->_vertices);
			this->_main_entities->add_entity(entity);
		}

		this->main_loop();
	}

	void arcnum::main_loop()
	{
		while (this->_main_window->is_running())
		{
			this->_main_window->update(this->_main_entities);
		}
	}
}