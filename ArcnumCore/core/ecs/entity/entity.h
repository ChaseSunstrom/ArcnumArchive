#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "../../util/data/vector.h"
#include "../component/component.h"



// ===============================================================
// GENERIC ENTITY: | Used to store render information about any entity
// ===============================================================

typedef struct
{
	u64 entity_id;
	render_component render_component;
} generic_entity;

generic_entity generic_entity_default(void);
generic_entity generic_entity_new(render_component render_component);

#endif //CORE_ENTITY_H