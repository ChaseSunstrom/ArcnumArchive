#ifndef VOXEL_H
#define VOXEL_H

#include "../../core_include.hpp"



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


#endif