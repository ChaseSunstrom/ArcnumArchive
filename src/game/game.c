#include <stdlib.h>
#include <stdio.h>

#include <glad.h>
#include <glfw3.h>

#include "terminate.h"
#include "shader.h"

const char* vertex_shader_source = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragment_shader_source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.2f, 0.9f, 0.4, 0.8f);\n"
"}\n\0";

void render_triangle()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void game_main(GLFWwindow* main_window)
{
    int success;
	unsigned int shader_program;
    char info_log[512];
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };

	unsigned int* vertex_shader = setup_vertex_shader(vertex_shader_source);
	unsigned int* fragment_shader = setup_fragment_shader(fragment_shader_source); 
    
    shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shader_program, 512, NULL, info_log);
        printf("ERROR: Program linking failed!\n%s", info_log);
    }

    unsigned int VBO = setup_vertex_buffer(&vertices);
	unsigned int VAO = setup_vertex_array(&vertices, &VBO);

    while (!glfwWindowShouldClose(main_window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        render_triangle();

        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }

    game_terminate(main_window);
}