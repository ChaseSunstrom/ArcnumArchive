#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

#include "../core.hpp"

#include "../ecs/ecs.hpp"
#include "batcher.hpp"

// ==============================================================================
// RENDERER:     | Used for rendering and storing rendering data
// ==============================================================================

namespace ac
{
	// ==============================================================================
	// RENDERER:     | Used for rendering and storing rendering data
	// ==============================================================================

	class renderer
	{
	public:
		renderer() = default;
		renderer(float64_t fixed_delta_time, std::function<void(void)> render_fn) : m_fixed_delta_time(fixed_delta_time), m_render_fn(render_fn) {}
		~renderer() = default;
		void on_update();
		void on_render();
		void on_event();
		void render();
		void calculate_tick_time();
		void calculate_delta_time();
		void calculate_last_frame_time();
	private:
		float64_t m_delta_time = 0;
		float64_t m_fixed_delta_time = 0.005;
		float64_t m_last_frame_time = 0;
		float64_t m_tick_time = 0;
		// User must provide a render function
		std::function<void(void)> m_render_fn = nullptr;
		std::unique_ptr<batcher> m_batcher    = std::make_unique<batcher>();
	};
}

#endif //CORE_RENDERER_H