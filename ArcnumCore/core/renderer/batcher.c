#include "batcher.h"


// ==============================================================================
// BATCHER FUNCTIONS:

batcher* batcher_default()
{
	batcher* _batcher = ALLOC(batcher);
	_batcher->VAO = 0;
	_batcher->VBO = 0;
	_batcher->entity_count = 0;
	_batcher->shader_program = glCreateProgram();
	_batcher->vertices = vector_default();
	return _batcher;
}

batcher* batcher_new(float64_vec vertices, u64 entity_count)
{
	batcher* _batcher = ALLOC(batcher);
	_batcher->VAO = 0;
	_batcher->VBO = 0;
	_batcher->entity_count = entity_count;
	_batcher->shader_program = glCreateProgram();
	_batcher->vertices = vertices;
	return _batcher;
}

void batcher_add(batcher* batcher, generic_entity* entity)
{
	batcher->entity_count++;

	vector_add_vector(batcher->vertices, entity->render_component.mesh.values);
}

// ==============================================================================