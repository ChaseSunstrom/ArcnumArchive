#include "file.h"


__A_CORE_API__ c_str read_file(c_str file_path)
{
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
     long file_size = ftell(file);
    rewind(file);

    char buffer[3000];

	for (uint64_t i = 0; i < file_size; i++) {
		buffer[i] = fgetc(file);
	}

	*(buffer + file_size) = '\0';

	fclose(file);

    return buffer;
}