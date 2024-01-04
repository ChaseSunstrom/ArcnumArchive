#include "game/arcnum.h"
#include <core/tests/test.h>

#define UNIT_TESTS

int main()
{
	A_CORE_TRACE_F("[COMPILED AT]: %s\n\n", __DATE__ " " __TIME__);

#ifndef UNIT_TESTS
	application_main();
#else
	core_test_main();
#endif
}