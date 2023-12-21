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

	vector_push(batcher->entities_in_vertices, entity->entity_id);

	vector_add_vector(batcher->vertices, entity->render_component.mesh.values);
}

void batcher_remove(batcher* batcher, generic_entity* entity)
{
	for (u64 i = 0; i < batcher->entity_count; i++)
	{
		if ((u64)vector_get(batcher->entities_in_vertices, i) == entity->entity_id)
		{
			vector_remove_slice(batcher->vertices, i, entity->render_component.mesh.values->size);
			vector_remove(batcher->entities_in_vertices, i);
			return;
		}
	}
}

// ==============================================================================