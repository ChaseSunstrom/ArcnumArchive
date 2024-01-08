#include "ecs.h"

ecs* ecs_default()
{
	ecs* _ecs = ALLOC(ecs);
	_ecs->entities = vector_default();
	return _ecs;
}

void ecs_add_entity(ecs* ecs, entity* entity)
{
	vector_push(ecs->entities, entity);
}

void ecs_remove_entity(ecs* ecs, entity* _entity)
{
	for (uint64_t i = 0; i < ecs->entities->size; i++)
		if (((entity*)vector_get(ecs->entities, i))->entity_id == _entity->entity_id)
			vector_remove(ecs->entities, i);
}