#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

#include "../../util/std_include.h"

// Tells the renderer how to render different entities
__AC_CORE_API__ typedef void (*system_function)(void);

__AC_CORE_API__ void system_handle_color(void);
__AC_CORE_API__ void system_handle_texture(void);
__AC_CORE_API__ void system_handle_position(void);


#endif