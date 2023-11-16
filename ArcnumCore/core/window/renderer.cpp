#include <iostream>

#include <glew.h>
#include <glfw3.h>

#include "renderer.hpp"

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
        this->_shaders = new shader();
        this->_shaders->compile_shaders(vertex_source, fragment_source);
        this->attach_shaders();
		this->_shaders->bind_objects();
    }

    renderer::~renderer()
    {
        glDeleteProgram(this->_shader_program);
		this->_shaders->~shader();
		this->_shaders->_gl_objects->~gl_objects();
    }

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

    void renderer::render()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(this->_shader_program);
        glBindVertexArray(this->_shaders->_gl_objects->_VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    void renderer::attach_shaders()
    {
        this->_shader_program = glCreateProgram();
        glAttachShader(_shader_program, this->_shaders->_gl_vertex_shader);
        glAttachShader(_shader_program, this->_shaders->_gl_fragment_shader);
        glLinkProgram(_shader_program);
        this->_shaders->~shader();
    }

    void shader::compile_shaders(const char* vertex_source, const char* fragment_source)
    {
        this->_gl_vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(_gl_vertex_shader, 1, &vertex_source, NULL);
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
        // fragment shader
        this->_gl_fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(_gl_fragment_shader, 1, &fragment_source, NULL);
        glCompileShader(_gl_fragment_shader);
        // check for shader compile errors
        glGetShaderiv(_gl_fragment_shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(_gl_fragment_shader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
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