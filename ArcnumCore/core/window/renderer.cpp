#include <iostream>
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "renderer.hpp"
#include "../world/voxel.hpp"


namespace arcnum_core
{
    renderer::renderer()
    {
        this->_voxels = std::vector<voxel*>();
        this->_shader_program = glCreateProgram();
    }

    renderer::~renderer()
    {
        glDeleteProgram(this->_shader_program);
        for (auto voxel : this->_voxels)
        {
            delete voxel->_shader;
        }
    }
}