#ifndef CORE_VOXEL_MANAGER_HPP
#define CORE_VOXEL_MANAGER_HPP

#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "texture.hpp"
#include "entity.hpp"	
#include "../lighting/light.hpp"
#include "../player/player.hpp"

namespace arcnum_core
{
	class ecs
	{
	public:
		ecs();
		~ecs();
		void bind_objects();
		void bind_all_objects();
		void add_entity(entity* entity);
		void add_entities(std::vector<entity*> entities);
	public:
		texture_manager* _texture_manager;
		std::vector<entity*> _entities;
		std::vector<GLuint> _VAOs;
	private:
		std::vector<GLuint> _VBOs;
		uint64_t            _current_entity = 0;
		uint64_t            _current_light  = 0;
	};
}

#endif