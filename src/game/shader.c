#include <stdlib.h>
#include <stdio.h>

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