#include "layer_stack.hpp"

namespace ac
{
	template<typename T, typename... Args>
	__A_CORE_API__ void layer_stack::push_layer(Args&&... args)
	{
		auto layer = std::make_unique<T>(std::forward<Args>(args)...);
		layer->on_attach();
		m_layers.push(std::move(layer));
	}

	template<typename T, typename... Args>
	__A_CORE_API__ void layer_stack::push_overlay(Args&&... args)
	{
		auto overlay = std::make_unique<T>(std::forward<Args>(args)...);
		overlay->on_attach();
		m_layers.push(std::move(overlay));
	}

	__A_CORE_API__ void layer_stack::pop_layer()
	{
		m_layers.pop_back();
	}

	__A_CORE_API__ void layer_stack::pop_overlay()
	{
		m_layers.pop_back();
	}
}