#ifndef ARCNUM_HPP
#define ARCNUM_HPP

#include <core/window/window.hpp>
#include <core/world/voxel.hpp>
#include <core/player/player.hpp>

namespace arcnum_main
{
	class arcnum
	{
	public:
		arcnum();
		~arcnum();

		void arcnum_main();
		void main_loop(arcnum_core::player* player);
	private:
		arcnum_core::window* _main_window;
		arcnum_core::voxel_manager* _main_entities;
		
	};
}

#endif
