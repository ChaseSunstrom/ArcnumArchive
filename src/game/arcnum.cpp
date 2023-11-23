
#include <vector>
#include <filesystem>
#include <iostream>

#include <core/window/window.hpp>
#include <core/world/entity.hpp>
#include <core/world/geometry.hpp>
#include <core/world/texture.hpp>

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
			// positions          // colors           // texture coords
		 TOP_RIGHT,      1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
		 BOTTOM_RIGHT,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		 BOTTOM_LEFT,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		};

		std::vector<float> vertices2 = {
			TOP_RIGHT,    1.0f, 0.0f, 0.0f,  1.0f, 1.0f,
			BOTTOM_LEFT,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,
			TOP_LEFT,     1.0f, 1.0f, 0.0f,  0.0f, 1.0f
		};

		arcnum_core::triangle* triangle1 = new arcnum_core::triangle(vertices, new float[3] {0, 0, 0});
		arcnum_core::triangle* triangle2 = new arcnum_core::triangle(vertices2, new float[3] {0, 0, 0});
		arcnum_core::texture* texture = new arcnum_core::texture(std::filesystem::absolute("assets/sprites/container.jpg"));

		this->_main_entities->add_texture(texture);

			arcnum_core::entity* entity = new arcnum_core::entity(
				&this->_main_window->_renderer->_shader_program,
				"shaders/vertex_shader.glsl",
				"shaders/fragment_shader.glsl",
				triangle1->_vertices,
				texture
			);

			this->_main_entities->add_entity(entity);

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