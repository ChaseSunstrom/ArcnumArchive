#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../../util/std_include.h"
#include "../../util/math/vec.h"

#include "color.h"

__A_CORE_API__ typedef struct
{
	u64 component_id;
	vec3 position;
	vec3 rotation;
	vec3 scale;
} transform_component;

__A_CORE_API__ typedef struct
{
	u64 component_id;
	GLuint VAO;
	GLuint VBO;
	GLuint vertex_shader;
	GLuint fragment_shader;
} shader_component;

__A_CORE_API__ typedef struct
{
	u64 component_id;
	bool rendering;
	shader_component shader;
	transform_component transform;
} render_component;

__A_CORE_API__ typedef struct
{
	u64 component_id;
	byte* image_data;
	GLuint texture;
} texture_component;

__A_CORE_API__ typedef struct
{
	u64 component_id;
	color color;
} color_component;

__A_CORE_API__ typedef struct
{
	u64 id;
	struct_vec components;
} archetype;

__A_CORE_API__ typedef struct
{
	u64 id;
	struct_vec archetypes;
} archetype_index;

#endif // CORE_COMPONENT_H 