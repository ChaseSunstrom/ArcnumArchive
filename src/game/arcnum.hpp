#ifndef ARCNUM_HPP
#define ARCNUM_HPP

#include <core/window/window.hpp>
#include <core/world/entity.hpp>

namespace arcnum_main
{
	class arcnum
	{
	public:
		arcnum();
		~arcnum();

		void arcnum_main();
		void main_loop(arcnum_core::camera* player_camera);
	private:
		arcnum_core::window* _main_window;
		arcnum_core::entity_manager* _main_entities;
		
	};
}

#endif
