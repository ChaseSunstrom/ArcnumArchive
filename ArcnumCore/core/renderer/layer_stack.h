#ifndef CORE_LAYER_STACK_H
#define CORE_LAYER_STACK_H

#include "../util/memory/bump_allocator.h"
#include "../util/data/vector.h"
#include "../util/data/iterator.h"

#include "layer.h"

// ==============================================================================
// LAYER STACK:   | Used for different rendering layers
// ==============================================================================
__A_CORE_API__ typedef struct
{
	struct_vec layers;
	iterator*  layers_it;
} layer_stack;



// ==============================================================================
// LAYER STACK:   | Functions

__A_CORE_API__ layer_stack* layer_stack_new(void);
__A_CORE_API__ layer_stack* _layer_stack_new(bump_allocator* allocator);
__A_CORE_API__ void         layer_stack_push_layer(layer_stack layer_stack, layer* layer);
__A_CORE_API__ void         layer_stack_push_overlay(layer_stack layer_stack, layer* overlay);
__A_CORE_API__ void         layer_stack_pop_layer(layer_stack layer_stack, layer* layer);
__A_CORE_API__ void         layer_stack_pop_overlay(layer_stack layer_stack, layer* overlay);
__A_CORE_API__ void         layer_stack_free(layer_stack* layer_stack);

// ==============================================================================

#endif //CORE_LAYER_STACK_H