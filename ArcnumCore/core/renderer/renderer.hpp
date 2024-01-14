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
		renderer(float64_t fixed_delta_time) : m_fixed_delta_time(fixed_delta_time) {}
		~renderer() = default;
		void on_update();
		void on_render();
		void on_event();
		void calculate_tick_time();
		void calculate_delta_time();
		void calculate_last_frame_time();
	private:
		float64_t m_delta_time = 0;
		float64_t m_fixed_delta_time = 0;
		float64_t m_last_frame_time = 0;
		float64_t m_tick_time = 0;
		std::unique_ptr<batcher> m_batcher = std::make_unique<batcher>();
	};
}

#endif //CORE_RENDERER_H