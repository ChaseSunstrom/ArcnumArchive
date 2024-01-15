#include "renderer.hpp"

namespace ac
{
	void renderer::on_update()
	{
		render();
	}

	void renderer::on_render()
	{
		
	}

	void renderer::on_event()
	{

	}

	void renderer::render()
	{
		m_render_fn();
		on_render();
	}

	void renderer::calculate_tick_time()
	{

	}

	void renderer::calculate_delta_time()
	{

	}

	void renderer::calculate_last_frame_time()
	{

	}
}