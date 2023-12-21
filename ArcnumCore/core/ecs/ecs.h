#ifndef CORE_ECS_H
#define CORE_ECS_H

#include "../util/std_include.h"
#include "../util/data/vector.h"


typedef struct
{
	struct_vec entities;
} ecs;

ecs* ecs_default();

#endif // CORE_ECS_H