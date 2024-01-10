#ifndef CORE_TEST_H
#define CORE_TEST_H

#include <stdbool.h>

#include "../core.h"
#include "../util/data/types.h"

#define TEST_AMOUNT 1000

static uint64_t  current_test_id = 0;
static char* test_fail_reason = "";

__A_CORE_API__ bool core_test_main(void);

typedef bool(*test_fn)(void);

typedef struct
{
	const char* name;
	test_fn fn;
} test;

static test tests[TEST_AMOUNT];

__A_CORE_API__ void add_test(test test);

#define TEST(_name) bool(_name)(void); \
                    bool _name(void)

#define ADD_TEST(_name) test _name##_var = (test){.name = #_name, .fn = _name}; \
						add_test(_name##_var) 

// =================================================================
// TEST UTILTY FUNCTIONS: | For helping with testing

int64_t tests_add_callback(int64_t x, int64_t y);

#endif // CORE_TEST_H