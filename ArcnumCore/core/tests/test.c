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
	vector(uint64_t) v = vector_new(((uint64_t[]) { 1, 2, 3, 4, 5 }));

	vector_insert(v, 2, 8);

	if ((uint64_t)vector_get(v, 2) == 8)
		return true;

	test_fail_reason = "VECTOR INSERTED INCORRECTLY";
	return false;
}

TEST(test_vector_assign_data)
{
	vector(uint64_t) v = vector_new(((uint64_t[]) { 1, 2, 3, 4, 5 }));

	vector_assign_data(v, 2, 0);

	if ((uint64_t)vector_get(v, 0) == 2)
		return true;

	test_fail_reason = "VECTOR ASSIGNED INCORRECTLY";
	return false;
}

TEST(test_vector_size)
{
	vector(uint64_t) v = vector_default();

	for (uint64_t i = 0; i < HUNDRED_MIL; i++)
		vector_push(v, i);

	if ((uint64_t)v->size == HUNDRED_MIL)
		return true;

	test_fail_reason = "VECTOR SIZE WAS INCORRECT";
	return false;
}

TEST(test_set)
{
	set(uint64_t) s = set_default();

	for (uint64_t i = 0; i < HUNDRED_MIL; i++)
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

	hashmap_insert(hmap, "key1", "value1", strlen("key1"));
	hashmap_insert(hmap, "key2", "value2", strlen("key2"));
	hashmap_insert(hmap, "key3", "value3", strlen("key3"));
	hashmap_insert(hmap, "key4", "value4", strlen("key4"));

	if (hmap->size = 4)
		return true;

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_insertss)
{
	hashmap(c_str, c_str) hmap = hashmap_default();

	c_str keys[] = { "key1", "key2", "key3", "key4" };
	c_str values[] = { "value1", "value2", "value3", "value4" };
	uint64_t size = 4;

	hashmap_insertss(hmap, keys, values, size);

	if (hmap->size = 4)
		return true;

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_insert_entries)
{
	hashmap(c_str, c_str) hmap = hashmap_default();
	entry entries[] = { { "key1", "value1" }, { "key2", "value2" }, { "key3", "value3" }, { "key4", "value4" } };
	hashmap_insert_entriess(hmap, entries, 4);

	if (hmap->size = 4)
		return true;

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_remove)
{
	hashmap(c_str, c_str) hmap = hashmap_default();
	entry entries[] = { { "key1", "value1" }, { "key2", "value2" }, { "key3", "value3" }, { "key4", "value4" } };
	uint64_t key_sizes[4] = { 4, 4, 4, 4 };
	hashmap_insert_entries(hmap, entries, key_sizes);

	hashmap_remove(hmap, "key1", strlen("key1"));
	hashmap_remove(hmap, "key3", strlen("key3"));

	if (hmap->size == 2)
		return true;

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_compare_keys)
{
	if (hashmap_compare_keys("key1", "key1", strlen("key1")))
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

	hashmap_insert_entriess(hmap, entries, 4);

	c_str key1 = hashmap_get(hmap, "key1", 4);
	c_str key2 = hashmap_get(hmap, "key2", 4);
	c_str key3 = hashmap_get(hmap, "key3", 4);
	c_str key4 = hashmap_get(hmap, "key4", 4);

	if (!key1 || !key2 || !key3 || !key4)
		goto FAIL;

	if ((strcmp(key1, "value1") == 0 && strcmp(key2, "value2") == 0 && strcmp(key3, "value3") == 0 && strcmp(key4, "value4") == 0))
		return true;

FAIL:

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
	ADD_TEST(test_hashmap_insertss);
	ADD_TEST(test_hashmap_remove);
	ADD_TEST(test_hashmap_insert_entries);
	ADD_TEST(test_hashmap_get);

	for (uint64_t i = 0; i < current_test_id; i++)
	{
		test current_test = tests[i];

		bool result = current_test.fn();

		if (result)
			A_CORE_INFO_F("[TEST PASSED]: %s     SUCCESS\n", current_test.name);

		else
			A_CORE_ERROR_F("[TEST FAILED]: %s     REASON - %s     FAILURE\n", current_test.name, test_fail_reason);
	}
}