#include "layer_stack.h"

// ==============================================================================
// LAYER STACK FUNCTIONS:

layer_stack* layer_stack_new()
{
	layer_stack* _layer_stack = ALLOC(layer_stack);
	_layer_stack->layers      = vector_new();
	return _layer_stack;
}