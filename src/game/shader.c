#include <stdlib.h>
#include <stdio.h>

#include <glfw3.h>

#include "shader.h"

char* read_shader_file(FILE* file, char* file_name)
{
	char contents;

	file = fopen(file_name, "r");

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