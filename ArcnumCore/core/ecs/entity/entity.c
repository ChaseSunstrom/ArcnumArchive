#include "entity.h"

static u64 globabl_entity_id = 0;

__A_CORE_API__ entity entity_default(void)
{
	entity entity;
	entity.entity_id = ++globabl_entity_id;
	entity.component_mask = 0;
	entity.components = vector_default();
	return entity;
}

__A_CORE_API__ entity entity_new(component components[])
{
	entity entity;
	entity.entity_id = ++globabl_entity_id;
	entity.component_mask = 0;
	entity.components = vector_default();
	vector_add_array(entity.components, components);

	for (u64 i = 0; i < entity.components->size; ++i)
		entity.component_mask |= ((component*)vector_get(entity.components, i))->type;

	return entity;
}

__A_CORE_API__ component* entity_get_component(entity* entity, component_type type)
{
	// Checks if the entity has the component, if not returns NULL
	// would be a waste of performace to loop through the components
	if (!entity_has_component(entity, type))
		return NULL;

	for (u64 i = 0; i < entity->components->size; ++i)
		if (((component*)vector_get(entity->components, i))->type == type)
			return (component*)vector_get(entity->components, i);
}

__A_CORE_API__ void entity_add_component(entity* entity, component* component)
{
	vector_push(entity->components, component);
	entity->component_mask |= component->type;
}

__A_CORE_API__ __A_CORE_INLINE__ bool entity_has_component(entity* entity, component_type component_type)
{
	return entity->component_mask & component_type;
}