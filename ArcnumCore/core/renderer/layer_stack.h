#ifndef CORE_LAYER_STACK_H
#define CORE_LAYER_STACK_H

#include "../util/data/vector.h"
#include "../util/data/iterator.h"

#include "layer.h"

// ==============================================================================
// LAYER STACK:   | Used for different rendering layers
// ==============================================================================
typedef struct
{
	struct_vec layers;
	iterator*  layers_it;
} layer_stack;



// ==============================================================================
// LAYER STACK:   | Functions

layer_stack* layer_stack_new(void);
void         layer_stack_push_layer(layer_stack layer_stack, layer* layer);
void         layer_stack_push_overlay(layer_stack layer_stack, layer* overlay);
void         layer_stack_pop_layer(layer_stack layer_stack, layer* layer);
void         layer_stack_pop_overlay(layer_stack layer_stack, layer* overlay);
void         layer_stack_free(layer_stack* layer_stack);

// ==============================================================================

#endif //CORE_LAYER_STACK_H