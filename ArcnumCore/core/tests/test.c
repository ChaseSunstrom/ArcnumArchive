#include "test.h"

#include "../util/logging/log.h"

#include "../util/data/hashmap.h"

void add_test(test test)
{
	tests[current_test_id] = test;
	current_test_id++;
}

TEST(test_hashmap_insert)
{
	hashmap(c_str, c_str) hmap = hashmap_default();

	hashmap_insert(hmap, "key1", "value1");
	hashmap_insert(hmap, "key2", "value2");
	hashmap_insert(hmap, "key3", "value3");
	hashmap_insert(hmap, "key4", "value4");

	if (hmap->size = 4)
		return true;

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_insert_entries)
{
	hashmap(c_str, c_str) hmap = hashmap_default();
	entry entries[] = { { "key1", "value1" }, { "key2", "value2" }, { "key3", "value3" }, { "key4", "value4" } };
	hashmap_insert_entries(hmap, entries);

	if (hmap->size = 4)
		return true;

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_remove)
{
	hashmap(c_str, c_str) hmap = hashmap_default();
	entry entries[] = { { "key1", "value1" }, { "key2", "value2" }, { "key3", "value3" }, { "key4", "value4" } };
	hashmap_insert_entries(hmap, entries);

	hashmap_remove(hmap, "key1");
	hashmap_remove(hmap, "key3");

	if (hmap->size == 2)
		return true;

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_compare_keys)
{
	if (hashmap_compare_keys("key1", "key1"))
		return true;

	test_fail_reason = "HASHMAP COMPARE KEYS RETURNED FALSE";
	return false;
} 

TEST(test_hashmap_get)
{

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
			A_CORE_INFO_F("[TEST PASSED]: %s     SUCCESS\n", current_test.name);

		else
			A_CORE_ERROR_F("[TEST FAILED]: %s     REASON - %s     FAILURE\n", current_test.name, test_fail_reason);
	}
}