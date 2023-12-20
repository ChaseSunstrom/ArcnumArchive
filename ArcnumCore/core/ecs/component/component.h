#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../../util/std_include.h"
#include "../../util/math/vec.h"

#include "color.h"

typedef u64 component_id;
typedef u64 archetype_id;

__A_CORE_API__ typedef struct
{
	component_id component_id;
	vec3 position;
	vec3 rotation;
	vec3 scale;
} transform_component;

__A_CORE_API__ typedef struct
{
	component_id component_id;
	GLuint VAO;
	GLuint VBO;
	GLuint vertex_shader;
	GLuint fragment_shader;
} shader_component;

__A_CORE_API__ typedef struct
{
	component_id component_id;
	bool rendering;
	shader_component shader;
	transform_component transform;
} render_component;

__A_CORE_API__ typedef struct
{
	component_id component_id;
	byte* image_data;
	GLuint texture;
} texture_component;

__A_CORE_API__ typedef struct
{
	component_id component_id;
	color color;
} color_component;

#endif // CORE_COMPONENT_H 