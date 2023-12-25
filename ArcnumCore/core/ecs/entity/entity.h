#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H

#include "../../util/data/vector.h"
#include "../component/component.h"



// ===============================================================
// GENERIC ENTITY: | Used to store render information about any entity
// ===============================================================

__A_CORE_API__ typedef struct
{
	u64 entity_id;
	struct_vec components;

	// This is used internally to tell OpenGL the size of the stride needed to render the entity
	stride_type stride;

	u64 component_mask;
} entity;

__A_CORE_API__ entity entity_default(void);
__A_CORE_API__ entity entity_new(component components[]);

__A_CORE_API__ void   entity_add_component(entity* entity, component* component);
__A_CORE_API__ component* entity_get_component(entity* entity, component_type type);
__A_CORE_API__ __A_CORE_INLINE__ bool entity_has_component(entity* entity, component_type type);

#endif //CORE_ENTITY_H