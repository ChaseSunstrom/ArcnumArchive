#include "game/arcnum.hpp"

//#define UNIT_TESTS

int main()
{
	A_CORE_INFO("[COMPILED AT]: " << __DATE__ << " " << __TIME__ << "\n");

#ifndef UNIT_TESTS
	arc::arcnum arcnum;
	arcnum.main();
#else
	core_test_main();
#endif
}