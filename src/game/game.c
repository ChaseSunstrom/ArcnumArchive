#pragma once

#include <stdlib.h>

#include <glad.h>
#include <glfw3.h>

#include "terminate.h"
#include "shader.h"

void game_main(GLFWwindow* main_window)
{
    while (!glfwWindowShouldClose(main_window))
    {
        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }

    game_terminate(main_window);
}

void render_triangle()
{
    int success;
    char info_log[512];
    unsigned int VBO;
    unsigned int vertex_shader;
    unsigned int fragment_shader;
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };
    char* vertex_shader_source = read_shader_file();
    char* fragment_shader_source = read_shader_file();
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
        printf("ERROR: Shader/Vertex compilation failed! \n%s", info_log);
    }

}