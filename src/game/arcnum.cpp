
#include "arcnum.hpp"
#include "voxel/voxel.hpp"

// ===============================================================================
// GAME FUNCTIONS:

namespace arc
{
	arcnum::arcnum()
	{
		push_layer<ac::renderer_layer>();
		push_layer<ac::ecs_layer>();
		push_layer<ac::window_layer>("Arcnum", 1280, 720, false);
	}

	void arcnum::main()
	{
		while (true)
		{
			update();
		}
	}

	template <typename T, typename... Args>
	void arcnum::push_layer(Args&&... args)
	{
		m_layer_stack->push_layer<T>(std::forward<Args>(args)...);
	}

	void arcnum::pop_layer()
	{
		m_layer_stack->pop_layer();
	}

	void arcnum::update()
	{
		for (const auto& layer : m_layer_stack->get_layers())
			layer->on_update();
	}

	void arcnum::on_event(std::shared_ptr<ac::event> event)
	{
		ac::event_dispatcher dispatcher(event);

		for (const auto& layer : m_layer_stack->get_layers())
			layer->on_event();
	}

	bool arcnum::print_event(std::shared_ptr<ac::event> event)
	{
		/*switch (event->m_type)
		{
		case ac::event_type::WINDOW_RESIZED:
			A_CORE_TRACE("[EVENT]: WINDOW RESIZED {X: %d, Y: %d}\n", event->m_width, ((window_resized_event*)event)->height);
			return true;
		case ac::event_type::MOUSE_MOVE:
			A_CORE_TRACE("[EVENT]: MOUSE POSITION {X: %f, Y: %f}", ((mouse_move_event*)event)->x_pos, ((mouse_move_event*)event)->y_pos);
			return true;
		case ac::event_type::MOUSE_SCROLLED:
			A_CORE_TRACE("[EVENT]: MOUSE SCROLLED \n");
			return true;
		case ac::event_type::KEY_PRESSED:
			A_CORE_TRACE("[EVENT]: KEY PRESSED {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
			return true;
		case ac::event_type::KEY_RELEASED:
			A_CORE_TRACE("[EVENT]: KEY RELEASED {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
			return true;
		case ac::event_type::KEY_REPEAT:
			A_CORE_TRACE("[EVENT]: KEY HELD {KEYCODE: %d}\n", ((key_pressed_event*)event)->key_code);
			return true;
		case ac::event_type::MOUSE_PRESSED:
			A_CORE_TRACE("[EVENT]: MOUSE BUTTON PRESSED {KEYCODE: %d}\n", ((mouse_pressed_event*)event)->button);
			return true;
		case ac::event_type::MOUSE_RELEASED:
			A_CORE_TRACE("[EVENT]: MOUSE BUTTON RELEASED {KEYCODE: %d}\n", ((mouse_pressed_event*)event)->button);
			return true;
		}
		return false;*/

		return true;
	}
}

// ============================================================================