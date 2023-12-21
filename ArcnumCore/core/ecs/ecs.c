#include "ecs.h"

ecs* ecs_default()
{
	ecs* _ecs = ALLOC(ecs);
	_ecs->entities = vector_default();
	return _ecs;
}