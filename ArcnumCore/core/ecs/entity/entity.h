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
	// Access components through a const char* name, this could be anything, it just has to be unique
	hashmap(c_str, component) components;

	// This is used internally to tell OpenGL the size of the stride needed to render the entity
	stride_type stride;

	uint64_t component_mask;
} entity;

__A_CORE_API__ entity entity_default(void);
__A_CORE_API__ entity entity_new(component components[]);
__A_CORE_API__ void   entity_render(entity* entity);
__A_CORE_API__ void   entity_change_vertices(entity* entity, vector(float64_t) vertices);

__A_CORE_API__ void   entity_add_component(entity* entity, component* component);
__A_CORE_API__ void   entity_remove_component(entity* entity, c_str component_name);
__A_CORE_API__ component* entity_get_component(entity* entity, c_str component_name);
__A_CORE_API__ __A_CORE_INLINE__ bool entity_has_component(entity* entity, c_str component_name);

#endif //CORE_ENTITY_H