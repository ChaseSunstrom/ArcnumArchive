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

u64 str_find_char(str* str, char c)
{
	for (u64 i = 0; i < str->length; i++)
		if (str->data[i] == c)
			return i;
}

u64* str_find_chars(str* str, char c)
{
	u64* arr = ALLOC(u64);
	u64 arr_length = 1;

	for (u64 i = 0; i < str->length; i++)
	{
		if (str->data[i] == c)
		{
			arr_length++;
			arr = REALLOC(arr, u64, arr_length);
			arr[arr_length - 1] = i;
		}
	}
	// sets the first value in the array to the length of the array
	arr[0] = arr_length - 1;
	return arr;
}

void str_remove_char(str* str, char c)
{
	u64 index = str_find_char(str, c);

	for (u64 i = index; i < str->length - 1; i++)
	{
		str->data[i] = str->data[i + 1];
	}

	str->length -= 1;
}

void str_remove_chars(str* str, char c)
{
	u64* indices = str_find_chars(str, c);

	for (u64 i = indices[0]; i > 0; i--)
	{
		u64 index = indices[i];

		for (u64 j = index; j < str->length - 1; j++)
			str->data[j] = str->data[j + 1];

		str->length -= 1;
	}

	FREE(indices);
	REALLOC(str->data, char, str->length);
}

void _str_remove_char(str* str, u64 index)
{
	if (index >= str->length)
		return;

	for (u64 i = index; i < str->length - 1; i++)
		str->data[i] = str->data[i + 1];

	str->length -= 1;
	REALLOC(str->data, char, str->length);
}

void _str_remove_chars(str* str, u64 index, u64 amount)
{
	if (index + amount > str->length)
		return;

	for (u64 i = index; i < str->length - amount; i++)
		str->data[i] = str->data[i + amount];

	str->length -= amount;
	REALLOC(str->data, char, str->length);
}

u64* str_find_c_str(const str* str, c_str c_str)
{
	u64* result = malloc(2 * sizeof(u64));

	u64 str_len = str->length;
	u64 c_str_len = strlen(c_str);

	for (u64 i = 0; i <= str_len - c_str_len; ++i)
	{
		u64 j;
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

u64* str_find_c_strs(const str* str, const char* c_str) 
{
	u64* result = NULL;
	u64 num_occurrences = 0;

	u64 c_str_len = strlen(c_str);

	for (u64 i = 0; i <= str->length - c_str_len; ++i) 
	{
		u64 j;
		for (j = 0; j < c_str_len; ++j)
			if (str->data[i + j] != c_str[j])
				break;

		if (j == c_str_len) 
		{
			result = realloc(result, (num_occurrences + 1) * 2 * sizeof(u64));

			result[num_occurrences * 2] = i;                 // start position
			result[num_occurrences * 2 + 1] = i + c_str_len; // end position (exclusive)

			num_occurrences++;
		}
	}

	result = realloc(result, num_occurrences * 2 * sizeof(u64));

	// Shift elements to make space for an additional element at the beginning
	memmove(result + 1, result, num_occurrences * 2 * sizeof(u64));


	result[0] = num_occurrences;

	return result;
}

u64* str_find_str(str* str1, str* str2)
{
	return str_find_c_str(str1, str2->data);
}

u64* str_find_strs(str* str1, str* str2)
{
	return str_find_c_strs(str1, str2->data);
}

void str_replace_c_strs(str* str, c_str substr, c_str replace)
{
	str->data[str->length] = '\0';
	u64* indices = str_find_c_str(str, substr);

	u64 new_length = str->length + (strlen(replace) * indices[0]);
	c_str output = malloc(new_length + 1);

	u64 i = 0, j = 0, output_index = 0;

	while (str->data[i] != '\0')
	{
		if (str->data[i] == substr[j])
		{
			if (substr[j + 1] == '\0')
			{
				for (u64 k = 0; replace[k] != '\0'; k++)
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