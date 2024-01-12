#ifndef CORE_BATCHER_H
#define CORE_BATCHER_H

#include "../util/std_include.h"
#include "../util/data/vector.h"
#include "../ecs/entity/entity.h"



// ==============================================================================
// BATCHER:        | Used to store related entities to batch render
// ==============================================================================

typedef struct
{
	GLuint shader_program;
	GLuint VAO;
	GLuint VBO;

	// This is used to store the amount of entities in the batcher
	uint64_t entity_count;

	vector(float64_t) vertices;

	// This is just in case access to entities data is needed;
	vector(generic_entity) entities;

	// This is used as a way to store the entity ids of the entities in the batcher
	vector(uint64_t) entity_ids;
} batcher;



// ==============================================================================
// BATCHER FUNCTIONS:

__A_CORE_API__ batcher* batcher_default();
__A_CORE_API__ batcher* batcher_new(vector(float64_t) vertices, uint64_t entity_count);
__A_CORE_API__ void     batcher_bind(batcher* batcher);
__A_CORE_API__ void     batcher_add_entity(batcher* batcher, renderable_entity* entity);
__A_CORE_API__ void     batcher_add_entities(batcher* batcher, vector(renderable_entity) entities);
__A_CORE_API__ void     batcher_render(batcher* batch);
__A_CORE_API__ void     batcher_free(batcher* batcher);

// ==============================================================================

#endif