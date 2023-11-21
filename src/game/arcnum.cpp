
#include <vector>

#include <filesystem>

#include <core/window/window.hpp>
#include <core/window/entity.hpp>
#include "world/triangle.hpp"
#include "arcnum.hpp"

#define TOP_RIGHT 0.5f,  0.5f, 0.0f
#define BOTTOM_RIGHT 0.5f, -0.5f, 0.0f
#define BOTTOM_LEFT -0.5f, -0.5f, 0.0f
#define TOP_LEFT -0.5f,  0.5f, 0.0f


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

		triangle* triangle1 = new triangle(vertices, new float[3] {0, 0, 0});
		triangle* triangle2 = new triangle(vertices2, new float[3] {0, 0, 2});
		triangle* triangle3 = new triangle(vertices, new float[3] {0, 0.5, 0});

		arcnum_core::entity* entity = new arcnum_core::entity(&this->_main_window->_renderer->_shader_program, "shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl", triangle1->_vertices);
		arcnum_core::entity* entity2 = new arcnum_core::entity(&this->_main_window->_renderer->_shader_program, "shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl", triangle2->_vertices);
		arcnum_core::entity* entity3 = new arcnum_core::entity(&this->_main_window->_renderer->_shader_program, "shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl", triangle3->_vertices);

		this->_main_entities->add_entity(entity);
		this->_main_entities->add_entity(entity2);
		this->_main_entities->add_entity(entity3);

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