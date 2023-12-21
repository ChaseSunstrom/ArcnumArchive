#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../../util/std_include.h"
#include "../../util/data/vector.h"
#include "../../util/math/vec.h"

#include "color.h"

// ==============================================================================
// COMPONENT FACTORY | Used to easily create components
// ==============================================================================

#define COMPONENT_FACTORY(_name, ...) typedef struct           \
									  {                        \
										  component_type type; \
									 	  __VA_ARGS__		   \
									  } _name



// ==============================================================================
// COMPONENT TYPE  | Used to store different component types
// ==============================================================================
__A_CORE_API__ typedef enum
{
	COMPONENT_TYPE_NONE = 0,
	COMPONENT_TYPE_MESH,
	COMPONENT_TYPE_TRANSFORM,
	COMPONENT_TYPE_SHADER,
	COMPONENT_TYPE_RENDER,
	COMPONENT_TYPE_TEXTURE,
	COMPONENT_TYPE_COLOR,
} component_type;


// ==============================================================================
// COMPONENTS:

__A_CORE_API__ COMPONENT_FACTORY(mesh_component, float64_vec values; );
__A_CORE_API__ COMPONENT_FACTORY(transform_component, vec3 position; vec3 rotation; vec3 scale;);
__A_CORE_API__ COMPONENT_FACTORY(shader_component, GLuint VAO; GLuint VBO; GLuint vertex_shader; GLuint fragment_shader; );
__A_CORE_API__ COMPONENT_FACTORY(render_component, mesh_component mesh; shader_component shader; transform_component transform; );
__A_CORE_API__ COMPONENT_FACTORY(texture_component, byte* image_data; GLuint texture; );
__A_CORE_API__ COMPONENT_FACTORY(color_component, color color; );

// ==============================================================================



// ==============================================================================
// COMPONENT FUNCTIONS:

__A_CORE_API__ __A_CORE_INLINE__ mesh_component      mesh_component_default(void);
__A_CORE_API__ __A_CORE_INLINE__ transform_component transform_component_default(void);
__A_CORE_API__ __A_CORE_INLINE__ shader_component	 shader_component_default(void);
__A_CORE_API__  render_component	 render_component_default(void);
__A_CORE_API__ __A_CORE_INLINE__ texture_component   texture_component_default(void);
__A_CORE_API__ __A_CORE_INLINE__ color_component	 color_component_default(void);

__A_CORE_API__ __A_CORE_INLINE__ mesh_component	     mesh_component_new(float64_vec values);
__A_CORE_API__ __A_CORE_INLINE__ transform_component transform_component_new(vec3 position, vec3 rotation, vec3 scale);
__A_CORE_API__ __A_CORE_INLINE__ shader_component	 shader_component_new(GLuint vertex_shader, GLuint fragment_shader);
__A_CORE_API__ __A_CORE_INLINE__ render_component	 render_component_new(mesh_component mesh, shader_component shader, transform_component transform);
__A_CORE_API__ __A_CORE_INLINE__ texture_component   texture_component_new(byte* image_data, GLuint texture);
__A_CORE_API__ __A_CORE_INLINE__ color_component	 color_component_new(color color);

// ==============================================================================

#endif // CORE_COMPONENT_H 