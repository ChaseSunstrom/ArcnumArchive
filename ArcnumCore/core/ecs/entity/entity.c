#include "entity.h"

static u64 globabl_entity_id = 0;

generic_entity generic_entity_default(void)
{
	generic_entity entity;
	entity.entity_id = ++globabl_entity_id;
	entity.render_component = render_component_default();
	return entity;
}

generic_entity generic_entity_new(render_component render_component)
{
	generic_entity entity;
	entity.entity_id = ++globabl_entity_id;
	entity.render_component = render_component;
	return entity;
}