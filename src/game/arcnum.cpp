#include <vector>
#include <filesystem>
#include <iostream>

#include <core/window/window.hpp>
#include <core/world/entity.hpp>
#include <core/world/entity_type.hpp>
#include <core/world/geometry.hpp>
#include <core/world/texture.hpp>

#include "arcnum.hpp"

#define TOP_RIGHT 0.5f,  0.5f, 0.0f
#define BOTTOM_RIGHT 0.5f, -0.5f, 0.0f
#define BOTTOM_LEFT -0.5f, -0.5f, 0.0f
#define TOP_LEFT -0.5f,  0.5f, 0.0f

#define SHADERS "shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl"

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

		this->_main_entities->_texture_manager = new arcnum_core::texture_manager();

		std::vector<float> vertices = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		};

		std::vector<float> vertices2 = {
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};

		arcnum_core::triangle* triangle1 = new arcnum_core::triangle(vertices);
		arcnum_core::triangle* triangle2 = new arcnum_core::triangle(vertices2);

		arcnum_core::entity* entity = new arcnum_core::entity(
			&this->_main_window->_renderer->_shader_program,
			SHADERS,
			vertices,
			arcnum_core::entity_type::test_container
		);

		arcnum_core::entity* entity2 = new arcnum_core::entity(
			&this->_main_window->_renderer->_shader_program,
			SHADERS,
			vertices2,
			arcnum_core::entity_type::test_container
		);

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