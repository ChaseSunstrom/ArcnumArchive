#ifndef VOXEL_H
#define VOXEL_H

#include "../../core_include.h"



// ==============================================================================
// VOXEL VERTICES: | The vertices that make up a voxel.
// ==============================================================================

static const float voxel_vertices[] = {
	//position           //color           //texture          //normal
    -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
        // second triangle
         0.0f, -0.5f, 0.0f,  // left
         0.9f, -0.5f, 0.0f,  // right
         0.45f, 0.5f, 0.0f   // top 
};



// ==============================================================================
// VOXEL:      | A container for an entity that will contain components that 
//             | render a voxel.
// ==============================================================================
typedef struct
{
    entity entity;
} voxel;

voxel* voxel_default();
voxel voxel_new(vec3 position, vec3 scale, vec3 rotation, color color);

#endif