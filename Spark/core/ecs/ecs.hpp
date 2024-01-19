#ifndef CORE_ECS_H
#define CORE_ECS_H

#include "../core.hpp"

#include "component/component.hpp"
#include "entity/entity.hpp"
#include "system/system.hpp"

namespace ac
{
	__A_CORE_API__ class ecs
	{
	public:

		// ==============================================================================
		// Interface functions for all the managers:

		ecs() = default;
		~ecs() = default;

		template <typename T>
		void register_component();

		template <typename... components>
		void register_components();

		template <typename T>
		void add_component(entity entity, T component);

		template <typename T>
		T& get_component(entity entity);

		template <typename T>
		bool has_component(entity entity);

		template <typename T>
		component_array<T>& get_component_array();

		template<typename T, typename... Args>
		std::shared_ptr<T> register_update_system(Args&&... systems);

		template<typename T, typename... Args>
		std::shared_ptr<T> register_start_system(Args&&... systems);

		template<typename T, typename... Args>
		std::shared_ptr<T> register_shutdown_system(Args&&... systems);

		void start_systems();
		void update_systems(float64_t delta_time);
		void shutdown_systems();

		entity create_entity();
		void destroy_entity(entity entity);
		
		// ==============================================================================
	
	private:
		std::shared_ptr<component_manager> m_component_manager = std::make_shared<component_manager>();
		std::unique_ptr<entity_manager> m_entity_manager = std::make_unique<entity_manager>(m_component_manager);
		std::unique_ptr<system_manager> m_system_manager = std::make_unique<system_manager>(m_component_manager);
	};
}

#endif // CORE_ECS_H