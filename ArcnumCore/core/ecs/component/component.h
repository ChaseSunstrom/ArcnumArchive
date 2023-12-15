#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../../util/std_include.h"
#include "../../util/memory/alloc.h"
#include "../../util/math/vec.h"

#include "color.h"

AC_CORE_API typedef struct
{
	GLuint VAO;
	GLuint VBO;
	GLuint vertex_shader;
	GLuint fragment_shader;
} shader_component;

AC_CORE_API typedef struct
{
	bool rendering;
	shader_component shader;
} renderable_component;

AC_CORE_API typedef struct
{
	byte* image_data;
	GLuint texture;
} texture_component;

AC_CORE_API typedef struct
{
	color color;
} color_component;

AC_CORE_API typedef struct
{
	vec3 position;
} position_component;

AC_CORE_API typedef struct
{
	vec3 position;
} size_component;


#endif // CORE_COMPONENT_H 