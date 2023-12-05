#ifndef CORE_LAYER_STACK_H
#define CORE_LAYER_STACK_H

#include "../util/data/vector.h"


// ==============================================================================
// LAYER STACK:   | Used for different rendering layers
// ==============================================================================
typedef struct
{
	struct_vec layers;
} layer_stack;

// ==============================================================================
// LAYER STACK:   | Functions

layer_stack* layer_stack_new(void);
// ==============================================================================

#endif //CORE_LAYER_STACK_H