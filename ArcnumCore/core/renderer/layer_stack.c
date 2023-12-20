#include "layer_stack.h"

// ==============================================================================
// LAYER STACK FUNCTIONS:

__A_CORE_API__ layer_stack* layer_stack_new()
{
	layer_stack* _layer_stack = ALLOC(layer_stack);
	_layer_stack->layers      = vector_new();
	_layer_stack->layers_it   = iterator_new(_layer_stack->layers);
	return _layer_stack;
}

__A_CORE_API__ layer_stack* _layer_stack_new(bump_allocator* allocator)
{
	layer_stack* _layer_stack = bump_allocator_alloc(allocator, sizeof(layer_stack));
	_layer_stack->layers      = vector_new();
	_layer_stack->layers_it   = iterator_new(_layer_stack->layers);
	return _layer_stack;
}

__A_CORE_API__ void layer_stack_push_layer(layer_stack layer_stack, layer* layer)
{
	vector_push(layer_stack.layers, layer);

	iterator_update(layer_stack.layers_it, layer_stack.layers);
}

__A_CORE_API__ void layer_stack_push_overlay(layer_stack layer_stack, layer* layer)
{
	vector_push(layer_stack.layers, layer);

	iterator_update(layer_stack.layers_it, layer_stack.layers);
}

__A_CORE_API__ void layer_stack_pop_layer(layer_stack layer_stack)
{
	vector_pop(layer_stack.layers);

	iterator_update(layer_stack.layers_it, layer_stack.layers);
}

__A_CORE_API__ void layer_stack_pop_overlay(layer_stack layer_stack)
{
	vector_pop(layer_stack.layers);
	
	iterator_update(layer_stack.layers_it, layer_stack.layers);
}

__A_CORE_API__ void layer_stack_free(layer_stack* layer_stack)
{
	vector_free(layer_stack->layers);
	iterator_free(layer_stack->layers_it);
	FREE(layer_stack);
}