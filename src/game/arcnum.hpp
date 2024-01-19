#ifndef ARCNUM_HPP
#define ARCNUM_HPP

#include  "../core_include.hpp"

namespace arc
{
	class arcnum
	{
	public:
		arcnum();
		~arcnum() = default;

		void main();
		void update();

		static bool on_event(std::shared_ptr<ac::event> event);

		template <typename T, typename... Args>
		void push_layer(Args&&... args);

		void pop_layer();
	private:
		std::unique_ptr<ac::layer_stack> m_layer_stack = std::make_unique<ac::layer_stack>();
		std::unique_ptr<ac::scene_manager> m_scene_manager = std::make_unique<ac::scene_manager>();
	};

	bool print_event(std::shared_ptr<ac::event> event);
}

#endif // ARCNUM_H