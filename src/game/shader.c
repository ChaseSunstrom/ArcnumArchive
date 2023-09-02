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

unsigned int handle_vertex_shader()
{
    unsigned int vertex_shader;
    char* vertex_shader_source = 
    "#version 330 core\nlayout(location = 0) in vec3 aPos;\nvoid main()\n{\ngl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}";
     
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

    return vertex_shader;
}

unsigned int handle_fragment_shader()
{
    unsigned int fragment_shader;
    char* fragment_shader_source =
        "#version 330 core\nout vec4 FragColor;\nvoid main()\n{\nFragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n}";
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

    return fragment_shader;
}

unsigned int handle_shaders()
{
    unsigned int* shader_program;
    unsigned int vertex_shader = handle_vertex_shader();
    unsigned int fragment_shader = handle_fragment_shader();
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

unsigned int setup_vertex_buffer(float vertices[])
{
    unsigned int VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    return VBO;
}

unsigned int setup_vertex_array(float vertices[], unsigned int* VBO)
{
    unsigned int VAO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    return VAO;
}