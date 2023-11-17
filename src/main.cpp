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
			-0.5f,  0.5f, 0.0f   // top left 
	};

	arc_core::window* window = new arc_core::window();
	arc_core::entity* entity = new arc_core::entity(&window->_renderer->_shader_program, vertex_source, fragment_source, vertices);

	std::vector<arc_core::entity*> entities;
	entities.emplace_back(entity);

	while (window->is_running())
	{
		window->update(entities);
	}

	return 0;
}