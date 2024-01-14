#include "game/arcnum.hpp"
#include <core/tests/test.hpp>

//#define UNIT_TESTS

int main()
{
	A_CORE_TRACE("[COMPILED AT]: %s\n", __DATE__ " " __TIME__);

#ifndef UNIT_TESTS
	arc::arcnum arcnum;
	arcnum.main();
#else
	core_test_main();
#endif
}