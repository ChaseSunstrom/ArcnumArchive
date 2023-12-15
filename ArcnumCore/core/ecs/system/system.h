#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

#include "../../util/std_include.h"

// Tells the renderer how to render different entities
AC_CORE_API typedef void (*system_function)(void);

AC_CORE_API void system_handle_color(void);
AC_CORE_API void system_handle_texture(void);
AC_CORE_API void system_handle_position(void);


#endif