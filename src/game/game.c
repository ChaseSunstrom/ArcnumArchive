#pragma once

#include <stdlib.h>
#include <stdio.h>

#include <glad.h>
#include <glfw3.h>

#include "terminate.h"
#include "shader.h"

void render_triangle()
{
    unsigned int VBO;
    unsigned int VAO;
    unsigned int* shader_program = handle_shaders();
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(shader_program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void game_main(GLFWwindow* main_window)
{
    while (!glfwWindowShouldClose(main_window))
    {
        render_triangle();
        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }

    game_terminate(main_window);
}