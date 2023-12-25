#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../../util/std_include.h"
#include "../../util/data/vector.h"
#include "../../util/math/vec.h"

#include "color.h"

// ==============================================================================
// COMPONENT FACTORY | Used to easily create components
// ==============================================================================

#define CORE_COMPONENT_FACTORY(_name, ...) typedef struct           \
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
	COMPONENT_TYPE_NORMAL,
} component_type;



//===============================================================================
// STRIDE TYPE: | Used to store different stride sizes
//===============================================================================
__A_CORE_API__ typedef enum
{
	POSITION = 3,
	POSITION_TEXTURE = 5,
	POSITION_COLOR = 6,
	POSITION_NORMAL = 6,
	POSITION_COLOR_TEXTURE = 8,
	POSITION_NORMAL_TEXTURE = 8,
	POSITION_NORMAL_COLOR = 9,
	POSITION_NORMAL_COLOR_TEXTURE = 11,
} stride_type;



// ==============================================================================
// COMPONENTS:

__A_CORE_API__ CORE_COMPONENT_FACTORY(component);
__A_CORE_API__ CORE_COMPONENT_FACTORY(mesh_component, f64_vec values; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(transform_component, vec3 position; vec3 rotation; vec3 scale;);
__A_CORE_API__ CORE_COMPONENT_FACTORY(shader_component, GLuint VAO; GLuint VBO; GLuint vertex_shader; GLuint fragment_shader; GLuint shader_program; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(render_component, mesh_component mesh; shader_component shader; transform_component transform; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(texture_component, byte* image_data; GLuint texture; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(color_component, color color; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(normal_component);

// ==============================================================================



// ==============================================================================
// COMPONENT FUNCTIONS:

__A_CORE_API__ mesh_component      mesh_component_default(void);
__A_CORE_API__ transform_component transform_component_default(void);
__A_CORE_API__ shader_component	   shader_component_default(void);
__A_CORE_API__ render_component	   render_component_default(void);
__A_CORE_API__ texture_component   texture_component_default(void);
__A_CORE_API__ color_component	   color_component_default(void);
__A_CORE_API__ normal_component	   normal_component_default(void);

__A_CORE_API__ mesh_component	   mesh_component_new(f64_vec values);
__A_CORE_API__ transform_component transform_component_new(vec3 position, vec3 rotation, vec3 scale);
__A_CORE_API__ shader_component	   shader_component_new(string vertex_path, string fragment_path);
__A_CORE_API__ render_component	   render_component_new(mesh_component mesh, shader_component shader, transform_component transform);
__A_CORE_API__ texture_component   texture_component_new(byte* image_data, GLuint texture);
__A_CORE_API__ color_component	   color_component_new(color color);
__A_CORE_API__ normal_component	   normal_component_new(void);

__A_CORE_API__ void                color_on_attach(stride_type stride_size);
__A_CORE_API__ void                texture_on_attach(stride_type stride_size);
__A_CORE_API__ void                normal_on_attach(stride_type stride_size);

// ==============================================================================

#endif // CORE_COMPONENT_H 