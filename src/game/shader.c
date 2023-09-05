#include <stdio.h>

#include <glad.h>
#include <glfw3.h>

#include "shader.h"


unsigned int setup_vertex_shader(const char* vertex_shader_source)
{
    unsigned int vertex_shader;
    char info_log[512];
    int success;


    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
        printf("ERROR: Shader/Vertex compilation failed! \n%s", info_log);
    }

	glGetError();

    return vertex_shader;
}

unsigned int setup_fragment_shader(const char* fragment_shader_source)
{
    unsigned int fragment_shader;
    char info_log[512];
    int success;

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        printf("ERROR: Shader/Fragment compilation failed! \n%s", info_log);
    }

    glGetError();

    return fragment_shader;
}

unsigned int setup_vertex_buffer(float* vertices[])
{
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW);

    glGetError();

    return VBO;
}

unsigned int setup_vertex_array(float* vertices[], unsigned int* VBO)
{
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, &VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    glGetError();

    return VAO;
}