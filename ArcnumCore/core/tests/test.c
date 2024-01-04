#include "test.h"

#include "../util/logging/log.h"
#include "../util/data/set.h"
#include "../util/data/hashmap.h"

#define HUNDRED_MIL 100000000

// Tests leak memory due to not freeing the data inside them.
// This is fine because nothing happens after all tests are done anyways.

void add_test(test test)
{
	tests[current_test_id] = test;
	current_test_id++;
}

TEST(test_vector_insert)
{
	vector(u64) v = vector_new(((u64[]) { 1, 2, 3, 4, 5 }));

	vector_insert(v, 2, 8);

	if ((u64)vector_get(v, 2) == 8)
		return true;

	test_fail_reason = "VECTOR INSERTED INCORRECTLY";
	return false;
}

TEST(test_vector_assign_data)
{
	vector(u64) v = vector_new(((u64[]) { 1, 2, 3, 4, 5 }));

	vector_assign_data(v, 2, 0);

	if ((u64)vector_get(v, 0) == 2)
		return true;

	test_fail_reason = "VECTOR ASSIGNED INCORRECTLY";
	return false;
}

TEST(test_vector_size)
{
	vector(u64) v = vector_default();

	for (u64 i = 0; i < HUNDRED_MIL; i++)
		vector_push(v, i);

	if ((u64)v->size == HUNDRED_MIL)
		return true;

	test_fail_reason = "VECTOR SIZE WAS INCORRECT";
	return false;
}

TEST(test_set)
{
	set(u64) s = set_default();

	for (u64 i = 0; i < HUNDRED_MIL; i++)
		set_push(s, 1);

	if (s->size == 1)
		return true;

	test_fail_reason = "SET SIZE WAS INCORRECT";
	A_CORE_TRACE_F("SIZE WAS: %d\n", s->size);
	return false;
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
	A_CORE_TRACE_F("SIZE WAS: %d\n", hmap->size);
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
	hashmap(c_str, c_str) hmap = hashmap_default();

	entry entries[] = {
		{ "key1", "value1" },
		{ "key2", "value2" },
		{ "key3", "value3" },
		{ "key4", "value4" } };
	hashmap_insert_entries(hmap, entries);

	c_str key1 = hashmap_get(hmap, "key1");
	c_str key2 = hashmap_get(hmap, "key2");
	c_str key3 = hashmap_get(hmap, "key3");
	c_str key4 = hashmap_get(hmap, "key4");

	if (strcmp(key1, "value1") == 0 && strcmp(key2, "value2") == 0 && strcmp(key3, "value3") == 0 && strcmp(key4, "value4") == 0)
		return true;

	test_fail_reason = "HASHMAP GET RETURNED BAD VALUES";
	return false;
}

bool core_test_main(void)
{
	ADD_TEST(test_vector_insert);
	ADD_TEST(test_vector_assign_data);
	ADD_TEST(test_vector_size);

	ADD_TEST(test_set);

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