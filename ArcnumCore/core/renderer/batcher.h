#ifndef CORE_BATCHER_H
#define CORE_BATCHER_H

#include "../util/std_include.h"
#include "../util/data/vector.h"
#include "../ecs/entity/entity.h"



// ==============================================================================
// BATCHER:        | Used to store related entities to batch render
// ==============================================================================

__A_CORE_API__ typedef struct
{
	GLuint shader_program;
	GLuint VAO;
	GLuint VBO;

	// This is used to store the amount of entities in the batcher
	u64 entity_count;

	float64_vec vertices;
} batcher;



// ==============================================================================
// BATCHER FUNCTIONS:

__A_CORE_API__ batcher* batcher_default();
__A_CORE_API__ batcher* batcher_new(float64_vec vertices, u64 entity_count);
__A_CORE_API__ void     batcher_add_entity(batcher* batcher, generic_entity* entity);

// ==============================================================================

#endif