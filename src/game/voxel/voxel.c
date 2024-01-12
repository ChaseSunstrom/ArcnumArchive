#include "voxel.h"
#include <stdlib.h>
static uint64_t voxel_id = 0;

voxel voxel_default()
{
	voxel vox;

	char fullpath_buffer1[1024]; 
	char fullpath_buffer2[1024];

	_fullpath(fullpath_buffer1, "ArcnumCore/shaders/vertex_shader.vert", 1024); 
	_fullpath(fullpath_buffer2, "ArcnumCore/shaders/color_shader.frag", 1024);

	vox.rc = render_component_new(mesh_component_new(vector_new(voxel_vertices)),
		shader_component_new(vector_new(voxel_vertices), fullpath_buffer1, fullpath_buffer2),
		transform_component_new(vec3_default(), vec3_default(), vec3_default()));
	
	
	return vox;
}

voxel voxel_new(vec3 position, vec3 scale, vec3 rotation, color color)
{
	voxel vox;

	char fullpath_buffer1[1024];
	char fullpath_buffer2[1024];

	_fullpath(fullpath_buffer1, "ArcnumCore/shaders/vertex_shader.vert", 1024);
	_fullpath(fullpath_buffer2, "ArcnumCore/shaders/color_shader.frag", 1024);
	
	vox.rc = render_component_new(mesh_component_new(vector_new(voxel_vertices)),
		_shader_component_new(fullpath_buffer1, fullpath_buffer2),
		transform_component_new(position, rotation, scale));

	vox.cc = color_component_new(color);

	return vox;
}