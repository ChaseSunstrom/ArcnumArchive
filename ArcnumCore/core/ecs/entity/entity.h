#ifndef CORE_ENTITY_H
#define CORE_ENTITY_H
#include "../../util/data/vector.h"



// ===============================================================
// ENTITY:       | Used to store entity related data
// ===============================================================

AC_CORE_API typedef struct
{
	function_ptr_vec systems;
	struct_vec components;
} entity;





#endif //CORE_ENTITY_H