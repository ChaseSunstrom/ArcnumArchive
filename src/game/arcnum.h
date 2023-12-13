#ifndef ARCNUM_H
#define ARCNUM_H

#include  "../core_include.h"

// ===============================================================================
// APPLICATION:   | Used for storing application information
// ===============================================================================
typedef struct
{
	window window;
	layer_stack layer_stack;
} application;



// ===============================================================================
// APPLICATION FUNCTIONS:

void application_main(void);
void application_loop(const application app);
void application_push_layer(const application app, layer* layer);
void application_pop_layer(const application app);
void application_cleanup(const application app);
void application_on_event(generic_event* event);
bool application_print_event(generic_event* event);

// ===============================================================================

#endif // ARCNUM_H