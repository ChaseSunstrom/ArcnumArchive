#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "../../util/data/vector.h"
#include "../../util/data/hashmap.h"
#include "../component/component.h"



// ===============================================================
// GENERIC ENTITY: | Used to store render information about any entity
// ===============================================================

__A_CORE_API__ typedef struct
{
	uint64_t entity_id;
	vector(uint64_t) systems;
} generic_entity;

__A_CORE_API__ typedef struct
{
	uint64_t entity_id;
	vector(uint64_t) systems;

	render_component rc;
} renderable_entity;

__A_CORE_API__ void entity_free(generic_entity* e);

#endif //CORE_ENTITY_H