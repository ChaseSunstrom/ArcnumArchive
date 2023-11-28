#ifndef ARCNUM_HPP
#define ARCNUM_HPP

#include <core/window/window.hpp>
#include <core/entity/entity.hpp>
#include <core/player/player.hpp>

namespace arcnum_main
{
	class arcnum
	{
	public:
		arcnum();
		~arcnum();

		void arcnum_main();
		void main_loop();
	private:
		arcnum_core::window* _main_window;
	};
}

#endif
