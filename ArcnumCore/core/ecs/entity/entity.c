#include "entity.h"

void entity_free(generic_entity* entity)
{
	vector_free_d(entity->systems);
	free(entity);
}