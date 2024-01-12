#include "ecs.h"

ecs* ecs_default()
{
	ecs* _ecs = ALLOC(ecs);
	_ecs->entities = vector_default();
	return _ecs;
}

void ecs_manager_add_entity(ecs* ecs, generic_entity* entity)
{
	vector_push(ecs->entities, entity);
}

void ecs_manager_remove_entity(ecs* ecs, generic_entity* _entity)
{
	for (uint64_t i = 0; i < ecs->entities->size; i++)
		if (((generic_entity*)vector_get(ecs->entities, i))->entity_id == _entity->entity_id)
			vector_remove(ecs->entities, i);
}

void ecs_free(ecs* ecs)
{
	vector_free(ecs->entities, entity_free);
	free(ecs);
}