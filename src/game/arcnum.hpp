#ifndef ARCNUM_H
#define ARCNUM_H

#include  "../core_include.hpp"

namespace arc
{
	class arcnum
	{
	public:
		arcnum();
		~arcnum();

		void main();
		void update();

		void on_event(std::shared_ptr<ac::event> event);

		template <typename T, typename... Args>
		void push_layer(Args&&... args);

		void pop_layer();
		bool print_event(std::shared_ptr<ac::event> event);
	private:
		std::unique_ptr<ac::layer_stack> m_layer_stack;
	};
}

#endif // ARCNUM_H