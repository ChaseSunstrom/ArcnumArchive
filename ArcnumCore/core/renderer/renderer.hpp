#ifndef CORE_RENDERER_H
#define CORE_RENDERER_H

#include "../core.hpp"

#include "../events/event.hpp"
#include "../ecs/ecs.hpp"
#include "batcher.hpp"

namespace ac
{
	// ==============================================================================
	// RENDERER:     | Used for rendering and storing rendering data
	// ==============================================================================

	class renderer
	{
	public:
		renderer() = default;
		renderer(float64_t fixed_delta_time) : m_fixed_delta_time(fixed_delta_time) {}
		renderer(uint64_t tick_speed) : m_tick_speed(tick_speed) {}
		renderer(float64_t fixed_delta_time, uint64_t tick_speed) : m_fixed_delta_time(fixed_delta_time), m_tick_speed(tick_speed) {}
		~renderer() = default;
		void on_update();
		void render();
		void calculate_total_time();
		void calculate_delta_time();
		void calculate_last_frame_time();
	private:
		float64_t m_delta_time = 0;
		float64_t m_fixed_delta_time = 0.005;
		float64_t m_last_frame_time = 0;
		float64_t m_total_time = 0;
		uint64_t  m_tick_speed = 60;
	
		std::unique_ptr<batcher> m_batcher    = std::make_unique<batcher>();

		// Time when renderer was constructed (used for time calculations)
		std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time = std::chrono::high_resolution_clock::now();
		std::chrono::time_point<std::chrono::high_resolution_clock> m_last_frame_time_point = std::chrono::high_resolution_clock::now();
	};
}

#endif //CORE_RENDERER_H