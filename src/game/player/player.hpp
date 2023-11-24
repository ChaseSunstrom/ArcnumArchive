#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <core/world/entity.hpp>
#include <core/window/camera.hpp>

namespace arcnum_main
{
	class player : public arcnum_core::entity
	{
	public: 
		using arcnum_core::entity::entity;
		~player();
		void move_camera_x();
		void move_camera_y();
	public:
		arcnum_core::camera* _main_camera = new arcnum_core::camera();
	};
}

#endif