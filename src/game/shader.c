#include <stdio.h>

#include <glad.h>
#include <glfw3.h>

#include "shader.h"

char* read_shader_file(char* file_name)
{
	FILE* file;
	char contents;

	file = fopen_s(file_name, "r", 100);

	if (file == NULL)
	{
		printf("File could not be opened. \n");
	}

	do {
		contents = fgetc(file);
	} while (contents != EOF);

	fclose(file);

	return contents;
}

unsigned int* handle_vertex_shader()
{
    unsigned int vertex_shader;
    char* vertex_shader_source = read_shader_file("triangle.glvs");
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

    return &vertex_shader;
}

unsigned int* handle_fragment_shader()
{
    unsigned int fragment_shader;
    char* fragment_shader_source = read_shader_file("triangle.glfs");
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

    return &fragment_shader;
}

unsigned int* handle_shaders()
{
    unsigned int shader_program;
    unsigned int* vertex_shader = handle_vertex_shader();
    unsigned int* fragment_shader = handle_fragment_shader();
    char info_log[512];
    int success;

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

    glUseProgram(shader_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return &shader_program;
}