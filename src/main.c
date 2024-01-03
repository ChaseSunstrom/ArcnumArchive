#include "game/arcnum.h"

#define UNIT_TESTS

int main()
{
#ifndef UNIT_TESTS
	application_main();
#else
	core_unit_test_main();
#endif
}