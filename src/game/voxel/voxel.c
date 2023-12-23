#include "voxel.h"

static u64 voxel_id = 0;

voxel voxel_default()
{
	voxel vox;

	vox.entity_id = voxel_id++;
	vox.color_component = color_component_default();
	vox.render_component = render_component_new(mesh_component_new(vector_new(voxel_vertices)), 
		shader_component_new("ArcnumCore/shaders/vertex_shader.vert", "ArcnumCore/shaders/color_shader.frag"), 
		transform_component_default());

	return vox;
}

voxel voxel_new(vec3 position, vec3 scale, vec3 rotation, color color)
{
	voxel vox;

	vox.entity_id = voxel_id++;
	vox.color_component = color_component_new(color);
	vox.render_component = render_component_new(mesh_component_new(vector_new(voxel_vertices)), 
		shader_component_new("ArcnumCore/shaders/vertex_shader.vert", "ArcnumCore/shaders/color_shader.frag"),
		transform_component_new(position, rotation, scale));
	return vox;
}