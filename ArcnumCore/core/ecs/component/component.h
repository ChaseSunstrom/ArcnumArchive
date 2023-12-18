#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../../util/std_include.h"
#include "../../util/memory/alloc.h"
#include "../../util/math/vec.h"

#include "color.h"

__A_CORE_API__ typedef struct
{
	vec3 position;
} position_component;

__A_CORE_API__ typedef struct
{
	vec3 position;
} size_component;

__A_CORE_API__ typedef struct
{
	//this is just a placeholder until quaternions are implemented
	vec3 rotation;
} rotation_component;

__A_CORE_API__ typedef struct
{
	GLuint VAO;
	GLuint VBO;
	GLuint vertex_shader;
	GLuint fragment_shader;
} shader_component;

__A_CORE_API__ typedef struct
{
	bool rendering;
	shader_component shader;
	position_component position;
	size_component size;
	rotation_component rotation;
} render_component;

__A_CORE_API__ typedef struct
{
	byte* image_data;
	GLuint texture;
} texture_component;

__A_CORE_API__ typedef struct
{
	color color;
} color_component;

#endif // CORE_COMPONENT_H 