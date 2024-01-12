#ifndef CORE_ECS_H
#define CORE_ECS_H

#include "../util/std_include.h"
#include "../util/data/vector.h"
#include "entity/entity.h"


// ==============================================================================
// ECS: | List of entities and their systems
// ==============================================================================

__A_CORE_API__ typedef struct
{
	vector(generic_entity) entities;
} ecs;

// ==============================================================================
// ECS FUNCTIONS:

__A_CORE_API__ ecs* ecs_default();
__A_CORE_API__ void ecs_add_entity(ecs* ecs, generic_entity* entity);
__A_CORE_API__ void ecs_remove_entity(ecs* ecs, generic_entity* entity);
__A_CORE_API__ void ecs_free(ecs* ecs);

// ==============================================================================

#endif // CORE_ECS_H