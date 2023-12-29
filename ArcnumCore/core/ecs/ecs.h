#ifndef CORE_ECS_H
#define CORE_ECS_H

#include "../util/std_include.h"
#include "../util/data/vector.h"
#include "entity/entity.h"


typedef struct
{
	struct_vec entities;
} ecs;

ecs* ecs_default();
void ecs_add_entity(ecs* ecs, entity* entity);

#endif // CORE_ECS_H