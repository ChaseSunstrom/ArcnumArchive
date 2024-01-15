#include "ecs.hpp"

namespace ac
{
	template <typename T>
	void ecs::register_component()
	{
		m_component_manager->register_component<T>();
	}

	template <typename... components>
	void ecs::register_components()
	{
		m_component_manager->register_components<components...>();
	}

	template <typename T>
	void ecs::add_component(entity entity, T component)
	{
		m_component_manager->add_component<T>(entity, component);
	}

	template <typename T>
	T& ecs::get_component(entity entity)
	{
		return m_component_manager[entity];
	}

	template<typename T, typename... Args>
	std::shared_ptr<T> ecs::register_update_system(Args&&... systems)
	{
		return m_system_manager->register_update_system<T>(std::forward<Args>(systems)...);
	}

	template<typename T, typename... Args>
	std::shared_ptr<T> ecs::register_start_system(Args&&... systems)
	{
		return m_system_manager->register_start_system<T>(std::forward<Args>(systems)...);
	}

	template<typename T, typename... Args>
	std::shared_ptr<T> ecs::register_shutdown_system(Args&&... systems)
	{
		return m_system_manager->register_shutdown_system<T>(std::forward<Args>(systems)...);
	}

	void ecs::start_systems()
	{
		m_system_manager->start_systems();
	}

	void ecs::update_systems(float64_t delta_time)
	{
		m_system_manager->update_systems(delta_time);
	}

	void ecs::shutdown_systems()
	{
		m_system_manager->shutdown_systems();
	}

	entity ecs::create_entity()
	{
		return m_entity_manager->create_entity();
	}

	void ecs::destroy_entity(entity entity)
	{
		m_entity_manager->destroy_entity(entity);
		m_component_manager->destroy_component_array(entity);
	}
}