
#include <vector>

#include <filesystem>


#include <core/window/window.hpp>
#include <core/window/entity.hpp>
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

		std::filesystem::path vertex_shader = std::filesystem::path("shaders/vertex_shader.glsl");
		std::filesystem::path fragment_shader = std::filesystem::path("shaders/fragment_shader.glsl");

		arcnum_core::entity* entity = new arcnum_core::entity(&this->_main_window->_renderer->_shader_program, vertex_shader, fragment_shader, vertices);
		arcnum_core::entity* entity2 = new arcnum_core::entity(&this->_main_window->_renderer->_shader_program, vertex_shader, fragment_shader, vertices2);

		this->_main_entities->add_entity(entity);
		this->_main_entities->add_entity(entity2);

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