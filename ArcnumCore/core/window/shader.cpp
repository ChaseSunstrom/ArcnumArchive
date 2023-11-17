#include <iostream>
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "shader.hpp"



namespace arc_core
{
    shader::shader()
    {
        this->_gl_objects = new gl_objects();
    }

    shader::~shader()
    {
        glDeleteShader(this->_gl_vertex_shader);
        glDeleteShader(this->_gl_fragment_shader);
    }

    gl_objects::~gl_objects()
    {
        glDeleteVertexArrays(1, &this->_VAO);
        glDeleteBuffers(1, &this->_VBO);
        glDeleteBuffers(1, &this->_EBO);
    }

    void shader::compile_shaders(std::vector<const char*> vertex_source, std::vector<const char*> fragment_source)
    {
        for (auto _vertex_source : vertex_source)
        {
            this->_gl_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(_gl_vertex_shader, 1, &_vertex_source, NULL);
            glCompileShader(_gl_vertex_shader);
            // check for shader compile errors
            int success;
            char infoLog[512];
            glGetShaderiv(_gl_vertex_shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(_gl_vertex_shader, 512, NULL, infoLog);
                std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            }

			for (auto _fragment_source : fragment_source)
			{
                // fragment shader
                this->_gl_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(_gl_fragment_shader, 1, &_fragment_source, NULL);
                glCompileShader(_gl_fragment_shader);
                // check for shader compile errors
                glGetShaderiv(_gl_fragment_shader, GL_COMPILE_STATUS, &success);
                if (!success)
                {
                    glGetShaderInfoLog(_gl_fragment_shader, 512, NULL, infoLog);
                    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
                }
			}
        }
    }

    void shader::bind_objects()
    {
        float vertices[] = {
             0.5f,  0.5f, 0.0f,  // top right
             0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left 
        };
        unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
        };

        glGenVertexArrays(1, &this->_gl_objects->_VAO);
        glGenBuffers(1, &this->_gl_objects->_VBO);
        glGenBuffers(1, &this->_gl_objects->_EBO);
        glBindVertexArray(this->_gl_objects->_VAO);

        glBindBuffer(GL_ARRAY_BUFFER, this->_gl_objects->_VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_gl_objects->_EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }
}