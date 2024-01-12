#ifndef CORE_COMPONENT_H
#define CORE_COMPONENT_H

#include "../../util/std_include.h"
#include "../../util/data/vector.h"
#include "../../util/math/vec.h"

#include "color.h"

// ==============================================================================
// COMPONENT FACTORY | Used to easily create components
// ==============================================================================

#define CORE_COMPONENT_FACTORY(_name, ...) typedef struct       \
									  {                         \
										  c_str component_name; \
									 	  __VA_ARGS__		    \
									  } _name



// ==============================================================================
// COMPONENTS:

__A_CORE_API__ CORE_COMPONENT_FACTORY(component);
__A_CORE_API__ CORE_COMPONENT_FACTORY(mesh_component, vector(float64_t) values; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(transform_component, vec3 position; vec3 rotation; vec3 scale;);
__A_CORE_API__ CORE_COMPONENT_FACTORY(shader_component, GLuint VAO; GLuint VBO; GLuint vertex_shader; GLuint fragment_shader; GLuint shader_program; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(render_component, mesh_component mesh; shader_component shader; transform_component transform; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(texture_component, ubyte* image_data; GLuint texture; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(color_component, color color; );
__A_CORE_API__ CORE_COMPONENT_FACTORY(normal_component);

// ==============================================================================



// ==============================================================================
// COMPONENT FUNCTIONS:

__A_CORE_API__ mesh_component      mesh_component_default(void);
__A_CORE_API__ transform_component transform_component_default(void);
__A_CORE_API__ shader_component    shader_component_default(void);
__A_CORE_API__ render_component	   render_component_default(void);
__A_CORE_API__ texture_component   texture_component_default(void);
__A_CORE_API__ color_component	   color_component_default(void);
__A_CORE_API__ normal_component	   normal_component_default(void);

__A_CORE_API__ mesh_component	   mesh_component_new(vector(float64_t) values);
__A_CORE_API__ transform_component transform_component_new(vec3 position, vec3 rotation, vec3 scale);
__A_CORE_API__ shader_component	   shader_component_new(vector(float64_t) vertices, c_str vertex_path, c_str fragment_path);
__A_CORE_API__ shader_component	   _shader_component_new(c_str vertex_path, c_str fragment_path);
__A_CORE_API__ render_component	   render_component_new(mesh_component mesh, shader_component shader, transform_component transform);
__A_CORE_API__ texture_component   texture_component_new(ubyte* image_data, GLuint texture);
__A_CORE_API__ color_component	   color_component_new(color color);
__A_CORE_API__ normal_component    normal_component_new(void);

__A_CORE_API__ void                shader_component_change_shader(shader_component* sc, c_str shader_path, GLint shader_type);

__A_CORE_API__ void                mesh_component_change_vertices(mesh_component* mc, vector(float64_t) vertices);

// ==============================================================================

#endif // CORE_COMPONENT_H 