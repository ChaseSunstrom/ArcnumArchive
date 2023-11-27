#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../world/voxel.hpp"
#include "../window/camera.hpp"

namespace arcnum_core
{
	class player : public voxel
	{
	public: 
		player(world_position world_pos, texture_type texture_type, color_type color, entity_type entity_type)
			:
			voxel(world_pos, texture_type, color, entity_type)
		{
			this->bind_objects();
		}
		~player();
		void bind_objects();
	public:
		camera* _main_camera = new camera();
		GLuint _VAO = 0;
		GLuint _VBO = 0;
	};
}

#endif