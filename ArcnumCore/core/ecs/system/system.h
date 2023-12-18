#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

#include "../../util/std_include.h"

// alias for all system functions
__A_CORE_API__ typedef void (*system_function)(void);

__A_CORE_API__ void system_handle_color(void);
__A_CORE_API__ void system_handle_texture(void);
__A_CORE_API__ void system_handle_position(void);
__A_CORE_API__ void system_handle_size(void);
__A_CORE_API__ void system_handle_rotation(void);
__A_CORE_API__ void system_handle_rendering(void);
__A_CORE_API__ void system_handle_shader(void);

#endif