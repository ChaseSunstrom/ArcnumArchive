#include "file.h"

#ifdef _MSC_VER
	#pragma warning(disable : 4996)
#endif // _MSC_VER

__A_CORE_API__ string read_file(string file_path)
{
	FILE* file = fopen(file_path, "r");

	char* result = "";

	i32 success = fscanf(file, "%s", result);

	if (success)
		return NULL;

	fclose(file);

	return result;	
}