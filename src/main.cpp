#include <core/core_main.hpp>
#include <core/logging/log.hpp>

#include "arcnum.hpp"

int main()
{
	A_CORE_INFO("[COMPILED AT]: " << __DATE__ << " " << __TIME__ << "\n");
	register_functions();
	ac::core_main();
}