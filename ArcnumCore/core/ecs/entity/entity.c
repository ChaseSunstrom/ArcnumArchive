#include "entity.h"

static uint64_t globabl_entity_id = 0;

__A_CORE_API__ entity entity_default(void)
{
	entity entity;
	entity.entity_id = ++globabl_entity_id;
	entity.component_mask = 0;
	entity.components = hashmap_default();
	return entity;
}

__A_CORE_API__ entity entity_new(component components[])
{
	entity entity;
	entity.entity_id = ++globabl_entity_id;
	entity.component_mask = 0;
	entity.components = hashmap_new(components);

	for (uint64_t i = 0; i < entity.components->size; ++i)
		//entity.component_mask |= ((component*)vector_get(entity.components, i))->component_name;

	return entity;
}

__A_CORE_API__ void entity_render(entity* entity)
{
	// rc becomes NULL after the second call to this function
	render_component* rc = entity_get_component(entity, "render_component");

	glUseProgram(rc->shader->shader_program);
	glBindVertexArray(rc->shader->VAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

__A_CORE_API__ void entity_change_vertices(entity* entity, vector(float64_t) vertices)
{
	if (!entity_has_component(entity, "render_component"))
		return;

	render_component* rc = entity_get_component(entity, "render_component");

	glBindBuffer(GL_ARRAY_BUFFER, rc->shader->VBO);
	glBufferSubData(GL_ARRAY_BUFFER, rc->mesh->values->size, vertices->size * sizeof(float64_t), vertices);

	vector_change_data(entity, vertices);
}

__A_CORE_API__ component* entity_get_component(entity* entity, c_str type)
{
	// Checks if the entity has the component, if not returns NULL
	// would be a waste of performace to loop through the components
	if (!entity_has_component(entity, type))
		return NULL;

	for (uint64_t i = 0; i < entity->components->size; i++)
		if (strcmp(((component*)vector_get(entity->components, i))->component_name, type) == 0)
			return (component*)vector_get(entity->components, i);
}

__A_CORE_API__ void entity_add_component(entity* entity, component* component)
{
	vector_push(entity->components, component);
	//entity->component_mask |= component->component_name;
}

__A_CORE_API__ void entity_remove_component(entity* entity, c_str component_type)
{
	for (uint64_t i = 0; i < entity->components->size; i++)
		if (((component*)vector_get(entity->components, i))->component_name == component_type)
			vector_remove(entity->components, i);
	//entity->component_mask &= ~component_type;
}

__A_CORE_API__ __A_CORE_INLINE__ bool entity_has_component(entity* entity, c_str component_type)
{
	//return entity->component_mask & component_type;
}