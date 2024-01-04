#include "game/arcnum.h"

#include <core/tests/test.h>

#include "core/util/data/hashmap.h"

#define UNIT_TESTS

int main()
{
#ifndef UNIT_TESTS
	application_main();
#else
	core_test_main();
#endif
}