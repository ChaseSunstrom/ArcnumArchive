#include <iostream>
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "renderer.hpp"
#include "shader.hpp"

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

namespace arc_core
{
    renderer::renderer()
    {
        this->_shaders = std::vector<shader*>{ new shader() };
        for (auto shader : this->_shaders)
        {
            shader->compile_shaders(std::vector<const char*>{vertex_source}, std::vector<const char*>{fragment_source});
            this->attach_shaders();
            shader->bind_objects();
        }
    }

    renderer::~renderer()
    {
        glDeleteProgram(this->_shader_program);
		for (auto shader : this->_shaders)
        {
            shader->~shader();
            shader->_gl_objects->~gl_objects();
		}
    }

    void renderer::render()
    {
        glUseProgram(this->_shader_program);
		for (auto shader : this->_shaders)
		{
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glBindVertexArray(shader->_gl_objects->_VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
    }

    void renderer::attach_shaders()
    {
        this->_shader_program = glCreateProgram();
        for (auto shader : this->_shaders)
        {
            glAttachShader(_shader_program, shader->_gl_vertex_shader);
            glAttachShader(_shader_program, shader->_gl_fragment_shader);
            glLinkProgram(_shader_program);
            shader->~shader();
        }
    }
}