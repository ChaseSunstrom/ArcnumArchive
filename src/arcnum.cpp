#include "core_include.hpp"

// required function
void on_start()
{
	// Default delta time
	ac::renderer::s_fixed_delta_time = 0.005;

	// Default tick speed
	ac::renderer::s_tick_speed = 60;
}

// required function
void on_update()
{

}

// required function
// will recieve events from everything, it is automatically subscribed to recieve
// every event
bool on_event(std::shared_ptr<ac::event> event)
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

// Registers functions to be called at different points in the application
// automatically
void register_functions()
{
	ac::app_functions::register_functions(on_start, on_update, on_event);
}