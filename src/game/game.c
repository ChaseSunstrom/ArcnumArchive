#pragma once

#include <stdlib.h>
#include <stdio.h>

#include <glad.h>
#include <glfw3.h>

#include "terminate.h"
#include "shader.h"

void render_triangle()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void game_main(GLFWwindow* main_window)
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };

    unsigned int VBO = setup_vertex_buffer(vertices);
    unsigned int VAO = setup_vertex_array(vertices, &VBO);

    int* VBO_PTR = &VBO;
    int* VAO_PTR = &VAO;

    printf("VBO: %p\n", VBO_PTR);
    printf("VAO: %p\n", VAO_PTR);

    unsigned int shader_program = handle_shaders();

    while (!glfwWindowShouldClose(main_window))
    {
        glfwSwapBuffers(main_window);
        glfwPollEvents();
        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        render_triangle();
    }

    game_terminate(main_window);
}