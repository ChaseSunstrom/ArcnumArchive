#ifndef CORE_STRING_H
#define CORE_STRING_H

#include "../std_include.h"
#include "types.h"

typedef struct
{
	char* data;
	u64 length;
} str;

__A_CORE_API__ str* str_default();
__A_CORE_API__ str* str_new(c_str c_str);
__A_CORE_API__ void str_concat(str* str1, str* str2);
__A_CORE_API__ void str_cconcat(str* str, c_str c_str);
__A_CORE_API__ void str_replace_c_strs(str* str, c_str substr, c_str replace);
__A_CORE_API__ u64  str_find_char(str* str, char c);
__A_CORE_API__ u64* str_find_chars(str* str, char c);
__A_CORE_API__ u64* str_find_str(str* str1, str* str2);
__A_CORE_API__ u64* str_find_strs(str* str1, str* str2);
__A_CORE_API__ u64* str_find_c_str(str* str, c_str c_str);
__A_CORE_API__ u64* str_find_c_strs(str* str, c_str c_str);
__A_CORE_API__ void str_remove_char(str* str, char c);
__A_CORE_API__ void str_remove_chars(str* str, char c);
__A_CORE_API__ void _str_remove_char(str* str, u64 index);
__A_CORE_API__ void _str_remove_chars(str* str, u64 index, u64 amount);
__A_CORE_API__ void str_free(str* str);

#endif