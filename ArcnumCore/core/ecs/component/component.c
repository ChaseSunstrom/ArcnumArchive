#include "component.h"

#include "../../util/data/vector.h"

__A_CORE_API__ __A_CORE_INLINE__ mesh_component      mesh_component_default(void)
{
	return (mesh_component) { COMPONENT_TYPE_MESH, vector_default() };
}

__A_CORE_API__ __A_CORE_INLINE__ transform_component transform_component_default(void)
{
	return (transform_component) { COMPONENT_TYPE_TRANSFORM, vec3_default(), vec3_default(), vec3_default() };
}

__A_CORE_API__ __A_CORE_INLINE__ shader_component	   shader_component_default(void)
{
	return (shader_component) { COMPONENT_TYPE_SHADER, 0, 0, 0, 0 };
}

__A_CORE_API__ __A_CORE_INLINE__ render_component	   render_component_default(void)
{
	return (render_component) { COMPONENT_TYPE_RENDER, mesh_component_default(), shader_component_default(), transform_component_default() };
}

__A_CORE_API__ __A_CORE_INLINE__ texture_component   texture_component_default(void)
{
	return (texture_component) { COMPONENT_TYPE_TEXTURE, NULL, 0 };
}

__A_CORE_API__ __A_CORE_INLINE__ color_component	   color_component_default(void)
{
	return (color_component) { COMPONENT_TYPE_COLOR, color_default() };
}

__A_CORE_API__ __A_CORE_INLINE__ mesh_component	   mesh_component_new(float64_vec values)
{
	return (mesh_component) { COMPONENT_TYPE_MESH, values };
}

__A_CORE_API__ __A_CORE_INLINE__ transform_component transform_component_new(vec3 position, vec3 rotation, vec3 scale)
{
	return (transform_component) { COMPONENT_TYPE_TRANSFORM, position, rotation, scale };
}

__A_CORE_API__ __A_CORE_INLINE__ shader_component	   shader_component_new(GLuint vertex_shader, GLuint fragment_shader)
{
	return (shader_component) { COMPONENT_TYPE_SHADER, 0, 0, vertex_shader, fragment_shader };
}

__A_CORE_API__ __A_CORE_INLINE__ render_component	   render_component_new(mesh_component mesh, shader_component shader, transform_component transform)
{
	return (render_component) { COMPONENT_TYPE_RENDER, mesh, shader, transform };
}

__A_CORE_API__ __A_CORE_INLINE__ texture_component   texture_component_new(byte* image_data, GLuint texture)
{
	return (texture_component) { COMPONENT_TYPE_TEXTURE, image_data, texture };
}

__A_CORE_API__ __A_CORE_INLINE__ color_component	   color_component_new(color color)
{
	return (color_component) { COMPONENT_TYPE_COLOR, color };
}