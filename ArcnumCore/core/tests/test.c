#include "test.h"

#include "../util/data/hashmap.h"

#ifdef _MSC_VER

#include <windows.h>

void set_console_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#else

void set_console_color(int color) { }

#endif // _MSC_VER

void add_test(test test)
{
	tests[current_test_id] = test;
	current_test_id++;
}

TEST(test_hashmap_insert)
{

	return true;
}

TEST(test_hashmap_insert_entries)
{
	test_fail_reason = "FUCK YOU";
	return false;
}

TEST(test_hashmap_remove)
{
	return true;
}

TEST(test_hashmap_compare_keys)
{
	test_fail_reason = "CUZ YOU SUCK";
	return false;
} 

TEST(test_hashmap_get)
{
	hashmap(c_str, u64) hashmap = hashmap_default();

	hashmap_insert(hashmap, "a", 5);
	hashmap_insert(hashmap, "e", 6);
	hashmap_insert(hashmap, "l", 7);

	

}

bool core_test_main(void)
{

	ADD_TEST(test_hashmap_compare_keys);
	ADD_TEST(test_hashmap_insert);
	ADD_TEST(test_hashmap_remove);
	ADD_TEST(test_hashmap_insert_entries);
	ADD_TEST(test_hashmap_get);

	for (u64 i = 0; i < current_test_id; i++)
	{
		test current_test = tests[i];

		bool result = current_test.fn();

		if (result)
		{
			set_console_color(FOREGROUND_GREEN);
			printf("[TEST PASSED]: %s\n", current_test.name);
		}

		else
		{
			set_console_color(FOREGROUND_RED);
			printf("[TEST FAILED]: %s       REASON - %s\n", current_test.name, test_fail_reason);
		}
	}
}