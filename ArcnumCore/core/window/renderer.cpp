#include <iostream>
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "renderer.hpp"
#include "shader.hpp"


namespace arc_core
{
    renderer::renderer()
    {
        this->_entities = std::vector<entity*>();
        this->_shader_program = glCreateProgram();
    }

    renderer::~renderer()
    {
        glDeleteProgram(this->_shader_program);
        for (auto entity : this->_entities)
        {
            entity->_shader->~shader();
        }
    }
}