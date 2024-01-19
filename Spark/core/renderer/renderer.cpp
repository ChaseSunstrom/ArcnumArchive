#include "../logging/log.hpp"
#include "renderer.hpp"
#include "../util/wrap.hpp"

namespace ac
{
	void renderer::on_update()
	{
		calculate_delta_time();
		calculate_last_frame_time();
		calculate_total_time();
	}

	void renderer::render(const scene* scene)
	{
		glm::vec4 color = scene->get_scene_config()->get_background_color();

		set_background_color(color.r, color.g, color.b, color.a);
		
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void renderer::calculate_total_time()
	{
		m_total_time += m_delta_time;
	}

	void renderer::calculate_delta_time()
	{
		auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float64_t> elapsed = now - m_last_frame_time_point;
		m_delta_time = elapsed.count(); // Time between the last frame and the current frame in seconds
		m_last_frame_time_point = now;
	}

	void renderer::calculate_last_frame_time()
	{
		m_last_frame_time = m_delta_time * 1000.0; // Convert seconds to milliseconds
	}
}