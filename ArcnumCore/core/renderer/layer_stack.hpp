#ifndef CORE_LAYER_STACK_H
#define CORE_LAYER_STACK_H

#include "layer.hpp"

namespace ac
{
	// ==============================================================================
	// LAYER STACK:   | Used for different application layers
	// ==============================================================================

	class layer_stack
	{
	public:
		layer_stack() = default;
		~layer_stack() = default;

		template<typename T, typename... Args>
		void push_layer(Args&&... args);

		template<typename T, typename... Args>
		void push_overlay(Args&&... args);
		
		void pop_layer();
		void pop_overlay();

		std::vector<std::unique_ptr<layer>>& get_layers() { return m_layers; }
	private:
		std::vector<std::unique_ptr<layer>> m_layers = std::vector<std::unique_ptr<layer>>();
	};

}

#endif //CORE_LAYER_STACK_H