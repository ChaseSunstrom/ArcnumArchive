#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "../../util/data/vector.h"
#include "../component/component.h"



// ===============================================================
// GENERIC ENTITY: | Used to store render information about any entity
// ===============================================================

typedef struct
{
	render_component render_component;
} generic_entity;


#endif //CORE_ENTITY_H