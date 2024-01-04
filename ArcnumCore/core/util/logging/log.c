#include "log.h"


// Magic windows color codes
#define TEXT_COLOR_GREEN  2
#define TEXT_COLOR_RED    4
#define TEXT_COLOR_CYAN   11
#define TEXT_COLOR_YELLOW 14

#ifdef _MSC_VER
#include <windows.h>

__A_CORE_API__ static void set_console_color(u32 color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#else

static void set_console_color(u32 color) { }

#endif


__A_CORE_API__ void _a_core_trace_f_(c_str format, ...)
{
    set_console_color(TEXT_COLOR_CYAN);
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

__A_CORE_API__ void _a_core_error_f_(c_str format, ...)
{
	set_console_color(TEXT_COLOR_RED);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

__A_CORE_API__ void _a_core_warn_f_(c_str format, ...)
{
	set_console_color(TEXT_COLOR_YELLOW);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

__A_CORE_API__ void _a_core_info_f_(c_str format, ...)
{
	set_console_color(TEXT_COLOR_GREEN);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

__A_CORE_API__ void _a_core_trace_uf_(c_str uformat)
{
	set_console_color(TEXT_COLOR_CYAN);
	printf(uformat);
}

__A_CORE_API__ void _a_core_error_uf_(c_str uformat)
{
	set_console_color(TEXT_COLOR_RED);
	printf(uformat);
}

__A_CORE_API__ void _a_core_warn_uf_(c_str uformat)
{
	set_console_color(TEXT_COLOR_YELLOW);
	printf(uformat);
}

__A_CORE_API__ void _a_core_info_uf_(c_str uformat)
{
	set_console_color(TEXT_COLOR_GREEN);
	printf(uformat);
}