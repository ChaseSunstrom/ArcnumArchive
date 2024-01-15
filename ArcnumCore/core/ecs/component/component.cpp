#include "component.hpp"

namespace ac
{
	template <typename T>
	void component_array<T>::insert(entity entity, T component)
	{
		if (entity >= m_component_array.size())
			m_component_array.resize(entity + 1);

		m_component_array[entity] = component;
	}

	template <typename T>
	void component_array<T>::entity_destroyed(entity entity)
	{
		assert(entity < m_component_array.size() && "entity exceeds component array bounds.");
		m_component_array[entity] = T();
	}

	template <typename T>
	T& component_array<T>::operator[](entity entity)
	{
		assert(entity < m_component_array.size() && "entity exceeds component array bounds.");
		return m_component_array[entity];
	}

	template <typename T>
	component_array<T>& component_manager::get_component_array()
	{
		std::type_index type = std::type_index(typeid(T));
		return static_cast<component_array<T>&>(*m_components[type].get());
	}

	template <typename T>
	void component_manager::register_component()
	{
		m_components[std::type_index(typeid(T))] = std::make_unique<component_array<T>>();
	}

	template <typename... components>
	void component_manager::register_components()
	{
		(register_component<components>(), ...);
	}

	template <typename T>
	void component_manager::add_component(entity entity, T component)
	{
		get_component_array<T>().insert(entity, component);
	}

	template <typename T>
	T& component_manager::operator[](entity entity)
	{
		return get_component_array<T>()[entity];
	}

	void component_manager::destroy_component_array(entity entity)
	{
		for (const auto& component : m_components)
			component.second->entity_destroyed(entity);
	}
}