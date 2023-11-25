#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <core/world/voxel.hpp>
#include <core/window/camera.hpp>

namespace arcnum_main
{
	class player : public arcnum_core::voxel
	{
	public: 
		using arcnum_core::voxel::voxel;
		~player();
	public:
		arcnum_core::camera* _main_camera = new arcnum_core::camera();
	};
}

#endif