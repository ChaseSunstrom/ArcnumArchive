#include <vector>

#include <core/window/window.hpp>
#include <core/window/entity.hpp>

const char* vertex_source = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragment_source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

int main()
{
	std::vector<float> vertices = {
			 0.5f,  0.5f, 0.0f,  // top right
			 0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			//-0.5f,  0.5f, 0.0f   // top left
	};

	std::vector<float> vertices2 = {
			 0.5f,  0.5f, 0.0f,  // top right
			// 0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left
	};
	std::vector<float> vertices3 = {
			 1.5f,  0.5f, 0.0f,  // top right
			 // 0.5f, -0.5f, 0.0f,  // bottom right
			 -1.5f, -0.5f, 0.0f,  // bottom left
			 -3.5f,  0.5f, 0.0f   // top left
	};

	std::vector<int> indices = {
		0, 1, 3,
		//1, 2, 3
	};


	arc_core::window* window = new arc_core::window();
	arc_core::entity* entity = new arc_core::entity(&window->_renderer->_shader_program, vertex_source, fragment_source, vertices, indices);
	arc_core::entity* entity2 = new arc_core::entity(&window->_renderer->_shader_program, vertex_source, fragment_source, vertices2, indices);
	arc_core::entity* entity3 = new arc_core::entity(&window->_renderer->_shader_program, vertex_source, fragment_source, vertices3, indices);

	std::vector<arc_core::entity*> entities_vec;
	entities_vec.emplace_back(entity);
	entities_vec.emplace_back(entity2);
	entities_vec.emplace_back(entity3);

	arc_core::entities* entities = new arc_core::entities(entities_vec);

	while (window->is_running())
	{
		window->update(entities);
	}

	return 0;
}