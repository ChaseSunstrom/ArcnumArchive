#ifndef CORE_SYSTEM_H
#define CORE_SYSTEM_H

// Tells the renderer how to render different entities
typedef void (*system_function)(void);

void system_handle_color(void);
void system_handle_texture(void);
void system_handle_position(void);


#endif