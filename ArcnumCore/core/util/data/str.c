#include "../memory/alloc.h"

#include "str.h"



str* str_default()
{
	str* _str = ALLOC(str);
	_str->length = 1;
	_str->data = malloc(1);
	_str->data = strcpy(_str->data, "\0");
	return _str;
}

str* str_new(c_str c_str)
{
	str* _str = ALLOC(str);
	_str->length = strlen(c_str);
	_str->data = malloc(_str->length + 1);
	_str->data = strcpy(_str->data, c_str);
	return _str;
}

void str_concat(str* str1, str* str2)
{
	strcat(str1->data, str2->data);
	str1->length += str2->length;
}

void str_cconcat(str* str, c_str c_str)
{
	strcat(str->data, c_str);
	str->length += strlen(c_str);
}

uint64_t str_find_char(str* str, char c)
{
	for (uint64_t i = 0; i < str->length; i++)
		if (str->data[i] == c)
			return i;
}

uint64_t* str_find_chars(str* str, char c)
{
	uint64_t* arr = ALLOC(uint64_t);
	uint64_t arr_length = 1;

	for (uint64_t i = 0; i < str->length; i++)
	{
		if (str->data[i] == c)
		{
			arr_length++;
			arr = REALLOC(arr, uint64_t, arr_length);
			arr[arr_length - 1] = i;
		}
	}
	// sets the first value in the array to the length of the array
	arr[0] = arr_length - 1;
	return arr;
}

void str_remove_char(str* str, char c)
{
	uint64_t index = str_find_char(str, c);

	for (uint64_t i = index; i < str->length - 1; i++)
	{
		str->data[i] = str->data[i + 1];
	}

	str->length -= 1;
}

void str_remove_chars(str* str, char c)
{
	uint64_t* indices = str_find_chars(str, c);

	for (uint64_t i = indices[0]; i > 0; i--)
	{
		uint64_t index = indices[i];

		for (uint64_t j = index; j < str->length - 1; j++)
			str->data[j] = str->data[j + 1];

		str->length -= 1;
	}

	FREE(indices);
	REALLOC(str->data, char, str->length);
}

void _str_remove_char(str* str, uint64_t index)
{
	if (index >= str->length)
		return;

	for (uint64_t i = index; i < str->length - 1; i++)
		str->data[i] = str->data[i + 1];

	str->length -= 1;
	REALLOC(str->data, char, str->length);
}

void _str_remove_chars(str* str, uint64_t index, uint64_t amount)
{
	if (index + amount > str->length)
		return;

	for (uint64_t i = index; i < str->length - amount; i++)
		str->data[i] = str->data[i + amount];

	str->length -= amount;
	REALLOC(str->data, char, str->length);
}

uint64_t* str_find_c_str(const str* str, c_str c_str)
{
	uint64_t* result = malloc(2 * sizeof(uint64_t));

	uint64_t str_len = str->length;
	uint64_t c_str_len = strlen(c_str);

	for (uint64_t i = 0; i <= str_len - c_str_len; ++i)
	{
		uint64_t j;
		for (j = 0; j < c_str_len; ++j)
		{
			if (str->data[i + j] != c_str[j])
			{
				break;
			}
		}

		if (j == c_str_len)
		{
			result[0] = i;                  // start position
			result[1] = i + c_str_len - 1;  // end position
			return result;
		}
	}

	// Substring not found
	free(result);
	return NULL;
}

uint64_t* str_find_c_strs(const str* str, const char* c_str) 
{
	uint64_t* result = NULL;
	uint64_t num_occurrences = 0;

	uint64_t c_str_len = strlen(c_str);

	for (uint64_t i = 0; i <= str->length - c_str_len; ++i) 
	{
		uint64_t j;
		for (j = 0; j < c_str_len; ++j)
			if (str->data[i + j] != c_str[j])
				break;

		if (j == c_str_len) 
		{
			result = realloc(result, (num_occurrences + 1) * 2 * sizeof(uint64_t));

			result[num_occurrences * 2] = i;                 // start position
			result[num_occurrences * 2 + 1] = i + c_str_len; // end position (exclusive)

			num_occurrences++;
		}
	}

	result = realloc(result, num_occurrences * 2 * sizeof(uint64_t));

	// Shift elements to make space for an additional element at the beginning
	memmove(result + 1, result, num_occurrences * 2 * sizeof(uint64_t));


	result[0] = num_occurrences;

	return result;
}

uint64_t* str_find_str(str* str1, str* str2)
{
	return str_find_c_str(str1, str2->data);
}

uint64_t* str_find_strs(str* str1, str* str2)
{
	return str_find_c_strs(str1, str2->data);
}

void str_replace_c_strs(str* str, c_str substr, c_str replace)
{
	str->data[str->length] = '\0';
	uint64_t* indices = str_find_c_str(str, substr);

	uint64_t new_length = str->length + (strlen(replace) * indices[0]);
	c_str output = malloc(new_length + 1);

	uint64_t i = 0, j = 0, output_index = 0;

	while (str->data[i] != '\0')
	{
		if (str->data[i] == substr[j])
		{
			if (substr[j + 1] == '\0')
			{
				for (uint64_t k = 0; replace[k] != '\0'; k++)
				{
					output[output_index++] = replace[k];
				}
				j = 0;
			}
			else
			{
				j++;
			}
		}
		else
		{
			output[output_index++] = str->data[i];
			j = 0;
		}
		i++;
	}

	free(indices);

	free(str->data);
	str->data = malloc(output_index + 1);
	memcpy(str->data, output, output_index);
	str->length = output_index;

	str->data[str->length] = '\0';
}

void str_free(str* str)
{
	if (str)
	{
		if (str->data)
			free(str->data);

		free(str);
	}
}