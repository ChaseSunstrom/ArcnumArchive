#include "test.h"

#include "../util/data/ptr.h"
#include "../util/logging/log.h"
#include "../util/data/set.h"
#include "../util/data/hashmap.h"

#define HUNDRED_MIL 100000000
int64_t tests_add_callback(int64_t x)
{
	return x;
}

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
	{
		vector_free(v);
		return true;
	}

	vector_free(v);

	test_fail_reason = "VECTOR INSERTED INCORRECTLY";
	return false;
}

TEST(test_vector_assign_data)
{
	vector(uint64_t) v = vector_new(((uint64_t[]) { 1, 2, 3, 4, 5 }));

	vector_assign_data(v, 2, 0);

	if ((uint64_t)vector_get(v, 0) == 2)
	{
		return true;
		vector_free(v);
	}

	vector_free(v);
	test_fail_reason = "VECTOR ASSIGNED INCORRECTLY";
	return false;
}

TEST(test_vector_size)
{
	vector(uint64_t) v = vector_default();

	for (uint64_t i = 0; i < HUNDRED_MIL; i++)
		vector_push(v, i);

	if ((uint64_t)v->size == HUNDRED_MIL)
	{
		vector_free(v);
		return true;
	}

	vector_free(v);

	test_fail_reason = "VECTOR SIZE WAS INCORRECT";
	return false;
}

TEST(test_vector_get)
{
	vector(uint64_t) v = vector_default();

	for (uint64_t i = 0; i < HUNDRED_MIL + 1; i++)
		vector_push(v, i);

	if (vector_get(v, HUNDRED_MIL) == HUNDRED_MIL)
		return true;

	test_fail_reason = "VECTOR GET RETURNED INCORRECT VALUE";
	return false;
}

TEST(test_vector_new)
{
	vector(uint64_t) v = vector_new(((uint64_t[]) { 1, 2, 3, 4 }));

	if (v->size == 4)
	{
		vector_free(v);
		return true;
	}

	vector_free(v);

	test_fail_reason = "VECTOR NEW HAD INCORRECT SIZE";
	return false;
}

TEST(test_vector_add_array)
{
	vector(uint64_t) v = vector_default();

	vector_add_array(v, ((uint64_t[]) { 1, 2, 3, 4}));

	if (v->size == 4)
	{
		vector_free(v);
		return true;
	}

	vector_free(v);

	test_fail_reason = "VECTOR ADD ARRAY HAD INCORRECT SIZE";
	return false;
}

TEST(test_set)
{
	set(uint64_t) s = set_default();

	for (uint64_t i = 0; i < HUNDRED_MIL; i++)
		set_push(s, 1);

	if (s->size == 1)
	{
		set_free(s);
		return true;
	}

	set_free(s);

	test_fail_reason = "SET SIZE WAS INCORRECT";
	return false;
}

TEST(test_hashmap_insertss)
{
	hashmap(c_str, c_str) hmap = hashmap_default();

	c_str keys[] = { "key1", "key2", "key3", "key4" };
	c_str values[] = { "value1", "value2", "value3", "value4" };
	uint64_t size = 4;

	hashmap_insertss(hmap, keys, values, size);

	c_str key1 = hashmap_get(hmap, "key1", 4);
	c_str key2 = hashmap_get(hmap, "key2", 4);
	c_str key3 = hashmap_get(hmap, "key3", 4);
	c_str key4 = hashmap_get(hmap, "key4", 4);

	if ((strcmp(key1, "value1") == 0 && strcmp(key2, "value2") == 0 && strcmp(key3, "value3") == 0 && strcmp(key4, "value4") == 0))
	{
		hashmap_free_d(hmap);
		return true;
	}

	hashmap_free_d(hmap);

	test_fail_reason = "HASHMAP SIZE INCORRECT";
	return false;
}

TEST(test_hashmap_remove)
{
	hashmap(c_str, c_str) hmap = hashmap_default();
	entry entries[] = { { "key1", "value1" }, { "key2", "value2" }, { "key3", "value3" }, { "key4", "value4" } };
	hashmap_insert_entriess(hmap, entries, 4);

	hashmap_remove(hmap, "key1", strlen("key1"));
	hashmap_remove(hmap, "key3", strlen("key3"));

	if (hashmap_get(hmap, "key1", strlen("key1")) == NULL &&
		hashmap_get(hmap, "key3", strlen("key3")) == NULL) {
		hashmap_free_d(hmap);
		return true;
	}

	hashmap_free_d(hmap);

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

	hashmap_insert(hmap, "key1", "value1", 4);
	hashmap_insert(hmap, "key2", "value2", 4);
	hashmap_insert(hmap, "key3", "value3", 4);
	hashmap_insert(hmap, "key4", "value4", 4);

	c_str key1 = hashmap_get(hmap, "key1", 4);
	c_str key2 = hashmap_get(hmap, "key2", 4);
	c_str key3 = hashmap_get(hmap, "key3", 4);
	c_str key4 = hashmap_get(hmap, "key4", 4);

	if (!key1 || !key2 || !key3 || !key4)
		goto FAIL;

	if ((strcmp(key1, "value1") == 0 && strcmp(key2, "value2") == 0 && strcmp(key3, "value3") == 0 && strcmp(key4, "value4") == 0))
	{
		hashmap_free_d(hmap);
		return true;
	}

FAIL:

	hashmap_free_d(hmap);

	test_fail_reason = "HASHMAP GET RETURNED BAD VALUES";
	return false;
}

TEST(test_handled_ptr)
{
	handled_ptr(int64_t) handled = handled_ptr_default();
	int64_t value = 5;
	handled_ptr_set_ptr(&handled, &value);

	if (*(int64_t*)handled.ptr == 5)
		return true;

	test_fail_reason = "HANDLED_PTR PTR WAS WRONG";
	return false;
}

TEST(test_optional_ptr_none)
{
	optional_ptr(int64_t) optional = optional_ptr_default();

	if (optional.state == NONE)
		return true;

	test_fail_reason = "OPTIONAL_PTR WAS NOT NONE";
	return false;
}

TEST(test_optional_ptr_some)
{
	optional_ptr(int64_t) optional = optional_ptr_default();
	uint64_t value = 5;
	optional_ptr_set_ptr(&optional, &value);
	
	if (optional.state == SOME && *(int64_t*)optional.ptr == 5)
		return true;

	test_fail_reason = "OPTIONAL_PTR WAS NOT SOME";
	return false;
}

TEST(test_optional_ptr_deref)
{
	optional_ptr(int64_t) optional = optional_ptr_default();

	// This should be NONE
	void* value = optional_ptr_deref(&optional);

	if (value == NONE)
		return true;

	test_fail_reason = "VALUE RETURNED BY DEREF WAS NOT NONE";
	return false;
}

TEST(test_optional_ptr_deref_or)
{
	optional_ptr(int64_t) optional = optional_ptr_default();
	optional_ptr_set_ptr(&optional, NULL);
	int64_t* res = optional_ptr_deref_or(&optional, tests_add_callback, 5);

	if (*res == 5)
		return true;

	test_fail_reason = "OPTIONAL_PTR DEREF OR CALLBACK FUNCTION FAILED";
	return false;
}

bool core_test_main(void)
{
	ADD_TEST(test_vector_insert);
	ADD_TEST(test_vector_assign_data);
	ADD_TEST(test_vector_size);
	ADD_TEST(test_vector_get);
	ADD_TEST(test_vector_new);
	ADD_TEST(test_vector_add_array);

	ADD_TEST(test_set);

	ADD_TEST(test_hashmap_compare_keys);
	ADD_TEST(test_hashmap_insertss);
	ADD_TEST(test_hashmap_remove);
	ADD_TEST(test_hashmap_get);

	ADD_TEST(test_handled_ptr);

	ADD_TEST(test_optional_ptr_none);
	ADD_TEST(test_optional_ptr_some);
	ADD_TEST(test_optional_ptr_deref);
	ADD_TEST(test_optional_ptr_deref_or);

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