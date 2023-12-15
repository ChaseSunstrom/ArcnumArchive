#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H
#include "../../util/data/vector.h"



// ===============================================================
// ENTITY:       | Used to store entity related data
// ===============================================================

__A_CORE_API__ typedef struct
{
	function_ptr_vec systems;
	struct_vec components;
} entity;





#endif //CORE_ENTITY_H