#include "arcnum.hpp"

namespace arc
{
	arcnum::arcnum()
	{
		this->push_layer<ac::renderer_layer>(0.005);
		this->push_layer<ac::ecs_layer>();
		this->push_layer<ac::window_layer>("Arcnum", 720, 1280, false);
	}

	void arcnum::main()
	{
		auto sub = ac::subscription<ac::event>::create(ac::subscription_topic::WINDOW_EVENT, on_event);
		
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

	void arcnum::render()
	{
		// TODO: implement abstraction for GL calls
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void arcnum::update()
	{
		for (const auto& layer : m_layer_stack->get_layers())
			layer->on_update();
	}

	bool arcnum::on_event(std::shared_ptr<ac::event> _event)
	{
		ac::event_dispatcher dispatcher(_event);

		return dispatcher.dispatch(print_event);
	}

	bool print_event(std::shared_ptr<ac::event> event)
	{
		switch (event->m_type)
		{
		case ac::event_type::WINDOW_RESIZED:
			A_CORE_TRACE("[EVENT]: WINDOW RESIZED X: " 
				<< std::static_pointer_cast<ac::window_resized_event>(event)->m_width 
				<< "Y: " << std::static_pointer_cast<ac::window_resized_event>(event)->m_height);
			return true;

		case ac::event_type::MOUSE_MOVE:
			A_CORE_TRACE("[EVENT]: MOUSE POSITION X: "
				<< std::static_pointer_cast<ac::mouse_moved_event>(event)->m_x_pos
				<< " Y: " << std::static_pointer_cast<ac::mouse_moved_event>(event)->m_y_pos);
			return true;

		case ac::event_type::MOUSE_SCROLLED:
			A_CORE_TRACE("[EVENT]: MOUSE SCROLLED");
			return true;

		case ac::event_type::KEY_PRESSED:
			A_CORE_TRACE("[EVENT]: KEY PRESSED KEYCODE: "
				<< std::static_pointer_cast<ac::key_pressed_event>(event)->m_key_code);
			return true;

		case ac::event_type::KEY_RELEASED:
			A_CORE_TRACE("[EVENT]: KEY RELEASED KEYCODE: "
				<< std::static_pointer_cast<ac::key_pressed_event>(event)->m_key_code);
			return true;

		case ac::event_type::KEY_REPEAT:
			A_CORE_TRACE("[EVENT]: KEY HELD KEYCODE: "
				<< std::static_pointer_cast<ac::key_pressed_event>(event)->m_key_code);
			return true;

		case ac::event_type::MOUSE_PRESSED:
			A_CORE_TRACE("[EVENT]: MOUSE BUTTON PRESSED BUTTON: "
				<< std::static_pointer_cast<ac::mouse_pressed_event>(event)->m_button);
			return true;

		case ac::event_type::MOUSE_RELEASED:
			A_CORE_TRACE("[EVENT]: MOUSE BUTTON RELEASED BUTTON: "
				<< std::static_pointer_cast<ac::mouse_pressed_event>(event)->m_button);
			return true;
		}

		return false;
	}
}