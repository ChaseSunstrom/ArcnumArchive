#include "../util/data/iterator.h"

#include "batcher.h"


// ==============================================================================
// BATCHER FUNCTIONS:

__A_CORE_API__ batcher* batcher_default()
{
	batcher* _batcher = ALLOC(batcher);
	_batcher->VAO = 0;
	_batcher->VBO = 0;
	_batcher->entity_count = 0;
	_batcher->vertices = vector_default();
	_batcher->entity_ids = vector_default();
	_batcher->entities = vector_default();
	_batcher->shader_program = glCreateProgram();
	batcher_bind(_batcher);
	return _batcher;
}

__A_CORE_API__ batcher* batcher_new(struct_vec entities, u64 entity_count)
{
	batcher* _batcher = ALLOC(batcher);
	_batcher->VAO = 0;
	_batcher->VBO = 0;
	_batcher->entity_count = entity_count;
	_batcher->vertices = vector_default();
	_batcher->entity_ids = vector_default();
	_batcher->entities = vector_default();
	_batcher->shader_program = glCreateProgram();
	batcher_add_entities(_batcher, entities);
	batcher_bind(_batcher);
	return _batcher;
}

__A_CORE_API__ void batcher_bind(batcher* batcher)
{
	glUseProgram(batcher->shader_program);

	glGenVertexArrays(1, &batcher->VAO);
	glBindVertexArray(batcher->VAO);

	glGenBuffers(1, &batcher->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, batcher->VBO);
	glBufferData(GL_ARRAY_BUFFER, batcher->vertices->size * sizeof(f64), batcher->vertices->data, GL_DYNAMIC_DRAW);
}

__A_CORE_API__ void batcher_add_entity(batcher* batcher, generic_entity* entity)
{
	batcher->entity_count++;

	vector_push(batcher->entity_ids, entity->entity_id);
	vector_push(batcher->entities, entity);

	vector_add_vector(batcher->vertices, entity->render_component.mesh.values);

	glBufferSubData(GL_ARRAY_BUFFER, batcher->vertices->size, entity->render_component.mesh.values->size * sizeof(f64), entity->render_component.mesh.values);
}

__A_CORE_API__ void batcher_add_entities(batcher* batcher, struct_vec entities)
{
	iterator* it = iterator_new(entities);

	while (iterator_has_next(it))
	{
		generic_entity* entity = iterator_get_current_data(it);
		batcher_add_entity(batcher, entity);
	}

	iterator_free(it);
}

__A_CORE_API__ void batcher_remove(batcher* batcher, generic_entity* entity)
{
	for (u64 i = 0; i < batcher->entity_count; i++)
	{
		if ((u64)vector_get(batcher->entity_ids, i) == entity->entity_id)
		{
			vector_remove_slice(batcher->vertices, i, entity->render_component.mesh.values->size);
			vector_remove(batcher->entity_ids, i);
			return;
		}
	}
}

__A_CORE_API__ void batcher_render(batcher* batcher)
{
	glBindVertexArray(batcher->VAO);
	glUseProgram(batcher->shader_program);

	glDrawArrays(GL_TRIANGLES, 0, batcher->vertices->size / 11);
}
// ==============================================================================